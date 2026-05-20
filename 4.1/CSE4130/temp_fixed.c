#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 2000
#define MAX_SYMBOLS 200
#define MAX_NAME_LEN 64
#define MAX_SCOPE_LEN 32
#define MAX_TYPE_LEN 24
#define MAX_ERRORS 200
#define MAX_LINE_LEN 512

// ---------- Data Structures ----------

// Token with line number
typedef struct
{
    char type[20];  // kw, id, op, num, sep, str
    char value[64]; // actual token value
    int line_number;
} Token;

// Symbol Table entry (now stores declaration line)
typedef struct
{
    int sl_no;
    char name[MAX_NAME_LEN];
    char id_type[MAX_TYPE_LEN];   // var, func, param
    char data_type[MAX_TYPE_LEN]; // int, float, double, char, void, ...
    char scope[MAX_SCOPE_LEN];    // global or function name
    char value[MAX_NAME_LEN];     // assigned value (constant-folded when possible)
    int decl_line;                // line number of declaration (for error reporting)
} SymbolEntry;

// Syntax error record
typedef struct
{
    int line_number;
    char error_type[64];
    char description[256];
} SyntaxError;

// ---------- Globals ----------
Token tokens[MAX_TOKENS];
int token_count = 0;

SymbolEntry symtab[MAX_SYMBOLS];
int symcount = 0;

SyntaxError errors[MAX_ERRORS];
int errcount = 0;

char current_scope[MAX_SCOPE_LEN] = "global";

// ---------- Prototypes ----------
static int is_keyword(const char *w);
static int is_library_function(const char *w);
static void scan_and_show_filtered();
static void tokenize_with_lines();
static void step_build_symbol_table();
static void step_detect_errors();

// symbol helpers
static int insert_symbol(const char *name, const char *id_type, const char *data_type,
                         const char *scope, int decl_line);
static SymbolEntry *lookup_symbol(const char *name, const char *scope);
static SymbolEntry *lookup_any_scope(const char *name);
static void set_symbol_value(SymbolEntry *e, const char *value);

// error helpers
static void add_error(int line, const char *type, const char *desc);
static void sort_and_show_errors();

// parsing helpers
static void parse_parameters_and_insert(int i_open_paren, const char *func_name);
static int eval_const_expr_to_str(int i_start, int *i_end, char outbuf[], size_t outsz);

// main
int main(void)
{
    printf("\nSample Input: Input.c\n\n");
    FILE *f = fopen("Input.c", "r");
    if (f)
    {
        char line[MAX_LINE_LEN];
        int ln = 1;
        while (fgets(line, sizeof(line), f))
        {
            printf("%d. %s", ln++, line);
        }
        fclose(f);
    }
    printf("\n\nSample Output:\n\n");

    // Step 1: Scanned & filtered
    scan_and_show_filtered();

    // Step 2: Tokenize with line numbers
    tokenize_with_lines();

    // Step 3: Build symbol table
    step_build_symbol_table();

    // Step 4: Detect syntax errors
    step_detect_errors();

    return 0;
}

// ---------- Keyword & library checks ----------
static int is_keyword(const char *word)
{
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    int n = (int)(sizeof(keywords) / sizeof(keywords[0]));
    for (int i = 0; i < n; i++)
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}
static int is_library_function(const char *word)
{
    const char *libs[] = {"printf", "scanf", "puts", "gets", "main"};
    int n = (int)(sizeof(libs) / sizeof(libs[0]));
    for (int i = 0; i < n; i++)
        if (strcmp(word, libs[i]) == 0)
            return 1;
    return 0;
}

// ---------- Step 1: Filter (show-only, non-mutating) ----------
static void scan_and_show_filtered()
{
    printf("Step 1: Scanned and filtered source program\n");
    FILE *in = fopen("Input.c", "r");
    if (!in)
    {
        printf("Error: Cannot open Input.c\n\n");
        return;
    }
    int c, next;
    int in_slc = 0, in_mlc = 0, in_str = 0;
    int prev_space = 0;
    while ((c = fgetc(in)) != EOF)
    {
        next = fgetc(in);
        if (next != EOF)
            ungetc(next, in);
        if (c == '\"' && !in_slc && !in_mlc)
        {
            in_str = !in_str;
            putchar(c);
            prev_space = 0;
            continue;
        }
        if (in_str)
        {
            putchar(c);
            prev_space = 0;
            continue;
        }
        if (c == '/' && next == '/' && !in_mlc)
        {
            in_slc = 1;
            continue;
        }
        if (c == '/' && next == '*')
        {
            in_mlc = 1;
            fgetc(in);
            continue;
        }
        if (c == '*' && next == '/' && in_mlc)
        {
            in_mlc = 0;
            fgetc(in);
            continue;
        }
        if (c == '\n' && in_slc)
        {
            in_slc = 0;
        }
        if (in_slc || in_mlc)
            continue;
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        {
            if (!prev_space)
            {
                putchar(' ');
                prev_space = 1;
            }
        }
        else
        {
            putchar(c);
            prev_space = 0;
        }
    }
    fclose(in);
    printf("\n\n");
}

// ---------- Step 2: Tokenize with line numbers ----------
static void tokenize_with_lines()
{
    printf("Step 2: Separated and tokenized lexemes\n");
    FILE *in = fopen("Input.c", "r");
    if (!in)
    {
        printf("Error: Cannot open Input.c\n\n");
        return;
    }

    char line[MAX_LINE_LEN];
    int ln = 1;
    while (fgets(line, sizeof(line), in))
    {
        int i = 0, L = (int)strlen(line);
        while (i < L)
        {
            while (i < L && isspace((unsigned char)line[i]))
                i++;
            if (i >= L)
                break;

            // skip line comments
            if (i + 1 < L && line[i] == '/' && line[i + 1] == '/')
                break;
            // skip block comments inline
            if (i + 1 < L && line[i] == '/' && line[i + 1] == '*')
            {
                i += 2;
                while (i + 1 < L && !(line[i] == '*' && line[i + 1] == '/'))
                    i++;
                if (i + 1 < L)
                    i += 2;
                continue;
            }

            // string literal
            if (line[i] == '\"')
            {
                char buf[64];
                int b = 0;
                buf[b++] = line[i++];
                while (i < L && line[i] != '\"' && b < 63)
                    buf[b++] = line[i++];
                if (i < L && b < 63)
                    buf[b++] = line[i++];
                buf[b] = '\0';
                strcpy(tokens[token_count].type, "str");
                strcpy(tokens[token_count].value, buf);
                tokens[token_count].line_number = ln;
                token_count++;
                continue;
            }

            // identifier / keyword
            if (isalpha((unsigned char)line[i]) || line[i] == '_')
            {
                char buf[64];
                int b = 0;
                while (i < L && (isalnum((unsigned char)line[i]) || line[i] == '_') && b < 63)
                    buf[b++] = line[i++];
                buf[b] = '\0';
                if (is_keyword(buf))
                    strcpy(tokens[token_count].type, "kw");
                else
                    strcpy(tokens[token_count].type, "id");
                strcpy(tokens[token_count].value, buf);
                tokens[token_count].line_number = ln;
                token_count++;
                continue;
            }

            // number (integer/float)
            if (isdigit((unsigned char)line[i]))
            {
                char buf[64];
                int b = 0;
                int dot = 0;
                while (i < L && (isdigit((unsigned char)line[i]) || (!dot && line[i] == '.')) && b < 63)
                {
                    if (line[i] == '.')
                        dot = 1;
                    buf[b++] = line[i++];
                }
                buf[b] = '\0';
                strcpy(tokens[token_count].type, "num");
                strcpy(tokens[token_count].value, buf);
                tokens[token_count].line_number = ln;
                token_count++;
                continue;
            }

            // two-char ops
            if (i + 1 < L && ((line[i] == '<' && line[i + 1] == '<') || (line[i] == '=' && line[i + 1] == '=') || (line[i] == '!' && line[i + 1] == '=')))
            {
                char buf[3] = {line[i], line[i + 1], 0};
                i += 2;
                strcpy(tokens[token_count].type, "op");
                strcpy(tokens[token_count].value, buf);
                tokens[token_count].line_number = ln;
                token_count++;
                continue;
            }

            // single-char ops
            if (strchr("+-*/%=!<>&|", line[i]))
            {
                char buf[2] = {line[i], 0};
                i++;
                strcpy(tokens[token_count].type, "op");
                strcpy(tokens[token_count].value, buf);
                tokens[token_count].line_number = ln;
                token_count++;
                continue;
            }

            // separators
            if (strchr("(){}[];,", line[i]))
            {
                char buf[2] = {line[i], 0};
                i++;
                strcpy(tokens[token_count].type, "sep");
                strcpy(tokens[token_count].value, buf);
                tokens[token_count].line_number = ln;
                token_count++;
                continue;
            }

            // unknown char -> skip
            i++;
        }
        ln++;
    }
    fclose(in);

    for (int i = 0; i < token_count; i++)
        printf("[%s %s] ", tokens[i].type, tokens[i].value);
    printf("\n\n");
}

// ---------- Symbol helpers ----------
static int insert_symbol(const char *name, const char *id_type, const char *data_type,
                         const char *scope, int decl_line)
{
    if (symcount >= MAX_SYMBOLS)
        return -1;
    symtab[symcount].sl_no = symcount + 1;
    strcpy(symtab[symcount].name, name);
    strcpy(symtab[symcount].id_type, id_type);
    strcpy(symtab[symcount].data_type, data_type ? data_type : "");
    strcpy(symtab[symcount].scope, scope);
    symtab[symcount].value[0] = '\0';
    symtab[symcount].decl_line = decl_line;
    symcount++;
    return symcount - 1;
}
static SymbolEntry *lookup_symbol(const char *name, const char *scope)
{
    for (int i = 0; i < symcount; i++)
        if (!strcmp(symtab[i].name, name) && !strcmp(symtab[i].scope, scope))
            return &symtab[i];
    return NULL;
}
static SymbolEntry *lookup_any_scope(const char *name)
{
    // prefer exact scope, fallback to global
    SymbolEntry *best = NULL;
    for (int i = 0; i < symcount; i++)
        if (!strcmp(symtab[i].name, name))
        {
            if (!strcmp(symtab[i].scope, current_scope))
                return &symtab[i];
            if (!strcmp(symtab[i].scope, "global"))
                best = &symtab[i];
            if (!best)
                best = &symtab[i];
        }
    return best;
}
static void set_symbol_value(SymbolEntry *e, const char *value)
{
    if (!e)
        return;
    strncpy(e->value, value, MAX_NAME_LEN - 1);
    e->value[MAX_NAME_LEN - 1] = '\0';
}

// ---------- Build Symbol Table ----------
static void step_build_symbol_table()
{
    printf("Step 3: Generated Symbol Table\n");
    printf("Sl. No.\tName\tId Type\tData Type\tScope\t\tValue\n");
    printf("----------------------------------------------------------------\n");

    char current_type[MAX_TYPE_LEN] = "";
    char current_func[MAX_SCOPE_LEN] = "global";
    strcpy(current_scope, "global");

    // stacks for scopes by braces
    int brace_depth = 0;

    for (int i = 0; i < token_count; i++)
    {
        // track data types
        if (!strcmp(tokens[i].type, "kw"))
        {
            if (!strcmp(tokens[i].value, "int") || !strcmp(tokens[i].value, "float") ||
                !strcmp(tokens[i].value, "double") || !strcmp(tokens[i].value, "char") ||
                !strcmp(tokens[i].value, "void"))
            {
                strcpy(current_type, tokens[i].value);
            }
        }

        // function detection: id followed by '(' just after a type -> function declaration
        if (!strcmp(tokens[i].type, "id") && !is_library_function(tokens[i].value))
        {
            // decide id_type and scope
            const char *idtype = "var";
            char scope[MAX_SCOPE_LEN];
            strcpy(scope, current_scope);

            if (i + 1 < token_count && !strcmp(tokens[i + 1].value, "("))
            {
                // treat as function name if previous token was a type
                if (i > 0 && !strcmp(tokens[i - 1].type, "kw") &&
                    (!strcmp(tokens[i - 1].value, "int") || !strcmp(tokens[i - 1].value, "float") ||
                     !strcmp(tokens[i - 1].value, "double") || !strcmp(tokens[i - 1].value, "char") ||
                     !strcmp(tokens[i - 1].value, "void")))
                {
                    idtype = "func";
                    strcpy(scope, "global");
                    strcpy(current_func, tokens[i].value);
                }
            }

            // insert symbol (decl line = this identifier's line if preceded by a type or it's a param later)
            if (!strcmp(idtype, "func"))
            {
                insert_symbol(tokens[i].value, "func", current_type, "global", tokens[i].line_number);
            }
            else
            {
                // If previous token is a type keyword -> declaration
                if (i > 0 && !strcmp(tokens[i - 1].type, "kw") &&
                    (!strcmp(tokens[i - 1].value, "int") || !strcmp(tokens[i - 1].value, "float") ||
                     !strcmp(tokens[i - 1].value, "double") || !strcmp(tokens[i - 1].value, "char")))
                {
                    insert_symbol(tokens[i].value, "var", current_type, current_scope, tokens[i].line_number);
                }
            }

            // simple assignment capture: id = <const-expr>;
            if (i + 1 < token_count && !strcmp(tokens[i + 1].value, "="))
            {
                char buf[64];
                int end_i = i + 2;
                if (eval_const_expr_to_str(i + 2, &end_i, buf, sizeof(buf)))
                {
                    // set value on declared symbol in closest scope
                    SymbolEntry *e = lookup_symbol(tokens[i].value, current_scope);
                    if (!e)
                        e = lookup_symbol(tokens[i].value, "global");
                    if (e)
                        set_symbol_value(e, buf);
                }
            }
        }

        // when we see an opening parenthesis after a function name, parse parameters
        if (!strcmp(tokens[i].type, "id") && i + 1 < token_count && !strcmp(tokens[i + 1].value, "("))
        {
            // confirm it's a function we just declared (exists in global as func)
            SymbolEntry *f = lookup_symbol(tokens[i].value, "global");
            if (f && !strcmp(f->id_type, "func"))
            {
                parse_parameters_and_insert(i + 1, f->name); // i+1 is '('
                // Set current function for scope tracking
                strcpy(current_func, f->name);
            }
        }

        // scope by braces
        if (!strcmp(tokens[i].type, "sep"))
        {
            if (!strcmp(tokens[i].value, "{"))
            {
                brace_depth++;
                if (brace_depth == 1)
                {
                    // entering function body
                    if (strcmp(current_func, "global") != 0)
                    {
                        strcpy(current_scope, current_func);
                    }
                }
            }
            else if (!strcmp(tokens[i].value, "}"))
            {
                if (brace_depth > 0)
                    brace_depth--;
                if (brace_depth == 0)
                {
                    // leaving function body
                    strcpy(current_scope, "global");
                    strcpy(current_func, "global"); // reset ONLY after function body ends
                }
            }
        }
    }

    // Print table
    for (int i = 0; i < symcount; i++)
    {
        printf("%d\t%s\t%s\t%s\t\t%s\t\t%s\n",
               symtab[i].sl_no, symtab[i].name, symtab[i].id_type, symtab[i].data_type,
               symtab[i].scope, symtab[i].value[0] ? symtab[i].value : "");
    }
    printf("\n");
}

// Parse parameters inside (...) and insert as 'param' in function scope
static void parse_parameters_and_insert(int i_open_paren, const char *func_name)
{
    int i = i_open_paren + 1; // after '('
    char last_type[MAX_TYPE_LEN] = "";
    while (i < token_count && strcmp(tokens[i].value, ")") != 0)
    {
        if (!strcmp(tokens[i].type, "kw") &&
            (!strcmp(tokens[i].value, "int") || !strcmp(tokens[i].value, "float") ||
             !strcmp(tokens[i].value, "double") || !strcmp(tokens[i].value, "char")))
        {
            strcpy(last_type, tokens[i].value);
        }
        else if (!strcmp(tokens[i].type, "id"))
        {
            if (last_type[0])
            {
                insert_symbol(tokens[i].value, "param", last_type, func_name, tokens[i].line_number);
                last_type[0] = '\0';
            }
        }
        i++;
    }
}

// Evaluate very small constant expression: NUM ([+ - * /] NUM)?
// Returns 1 if evaluated, 0 otherwise. i_end becomes index after expression.
static int eval_const_expr_to_str(int i_start, int *i_end, char outbuf[], size_t outsz)
{
    if (i_start >= token_count)
        return 0;
    // first token must be number
    if (strcmp(tokens[i_start].type, "num") != 0)
        return 0;
    double val = atof(tokens[i_start].value);
    int i = i_start + 1;
    if (i < token_count && !strcmp(tokens[i].type, "op") && strchr("+-*/", tokens[i].value[0]))
    {
        char op = tokens[i].value[0];
        i++;
        if (i < token_count && !strcmp(tokens[i].type, "num"))
        {
            double rhs = atof(tokens[i].value);
            if (op == '+')
                val = val + rhs;
            else if (op == '-')
                val = val - rhs;
            else if (op == '*')
                val = val * rhs;
            else if (op == '/')
                val = rhs != 0 ? val / rhs : val;
            i++;
        }
    }
    snprintf(outbuf, outsz, "%g", val);
    *i_end = i;
    return 1;
}

// ---------- Error Detection ----------
static void check_duplicate_declarations()
{
    // Check for duplicate variable/function names in the same scope
    for (int i = 0; i < symcount; i++)
    {
        for (int j = i + 1; j < symcount; j++)
        {
            if (!strcmp(symtab[i].name, symtab[j].name) && !strcmp(symtab[i].scope, symtab[j].scope))
            {
                char msg[256];
                snprintf(msg, sizeof(msg), "%s is declared twice globally", symtab[j].name);
                add_error(symtab[j].decl_line, "Duplicate Declaration", msg);
            }
        }
    }
}

static void check_duplicate_keywords()
{
    // Check for consecutive duplicate keywords
    for (int i = 0; i < token_count - 1; i++)
    {
        if (!strcmp(tokens[i].type, "kw") && !strcmp(tokens[i + 1].type, "kw") &&
            !strcmp(tokens[i].value, tokens[i + 1].value))
        {
            char msg[128];
            snprintf(msg, sizeof(msg), "%s is declared twice", tokens[i].value);
            add_error(tokens[i + 1].line_number, "Duplicate Keyword", msg);
        }
    }
}

static void check_unmatched_else()
{
    // Use a more sophisticated approach to track if-else matching
    int if_stack[100];
    int stack_top = -1;

    for (int i = 0; i < token_count; i++)
    {
        if (!strcmp(tokens[i].type, "kw") && !strcmp(tokens[i].value, "if"))
        {
            // Push this if onto stack
            if_stack[++stack_top] = i;
        }
        else if (!strcmp(tokens[i].type, "kw") && !strcmp(tokens[i].value, "else"))
        {
            // Check for matching if
            if (stack_top >= 0)
            {
                // Pop the matching if
                stack_top--;
            }
            else
            {
                // No matching if found
                add_error(tokens[i].line_number, "Unmatched else", "\telse without a previous if");
            }
        }
    }
}

typedef struct
{
    char ch;
    int line;
} StackItem;
static void check_parentheses_and_braces()
{
    // Separate stacks for parentheses and braces
    StackItem pstack[512];
    int pt = 0;
    StackItem bstack[512];
    int bt = 0;

    for (int i = 0; i < token_count; i++)
    {
        if (!strcmp(tokens[i].value, "("))
        {
            pstack[pt].ch = '(';
            pstack[pt].line = tokens[i].line_number;
            pt++;
        }
        else if (!strcmp(tokens[i].value, ")"))
        {
            if (pt > 0)
                pt--;
            else
                add_error(tokens[i].line_number, "Mismatched parenthesis", "Extra closing parenthesis");
        }
        else if (!strcmp(tokens[i].value, "{"))
        {
            bstack[bt].ch = '{';
            bstack[bt].line = tokens[i].line_number;
            bt++;
        }
        else if (!strcmp(tokens[i].value, "}"))
        {
            if (bt > 0)
                bt--;
            else
                add_error(tokens[i].line_number, "Mismatched parenthesis", "Extra closing brace");
        }
    }

    // Report remaining unmatched opens
    while (pt > 0)
    {
        pt--;
        add_error(pstack[pt].line, "Mismatched parenthesis", "Unclosed opening parenthesis");
    }
    while (bt > 0)
    {
        bt--;
        add_error(bstack[bt].line, "Mismatched parenthesis", "Unclosed opening brace");
    }
}

static void check_undeclared_identifiers()
{
    // Check for identifiers that are used but not declared
    for (int i = 0; i < token_count; i++)
    {
        if (!strcmp(tokens[i].type, "id") && !is_library_function(tokens[i].value))
        {
            // Skip if this is a declaration (preceded by type keyword)
            int is_declaration = 0;
            if (i > 0 && !strcmp(tokens[i - 1].type, "kw") &&
                (!strcmp(tokens[i - 1].value, "int") || !strcmp(tokens[i - 1].value, "float") ||
                 !strcmp(tokens[i - 1].value, "double") || !strcmp(tokens[i - 1].value, "char") ||
                 !strcmp(tokens[i - 1].value, "void")))
            {
                is_declaration = 1;
            }

            // Skip if this is a function name followed by parenthesis
            if (i + 1 < token_count && !strcmp(tokens[i + 1].value, "("))
            {
                is_declaration = 1;
            }

            if (!is_declaration)
            {
                SymbolEntry *found = lookup_any_scope(tokens[i].value);
                if (!found)
                {
                    char msg[128];
                    snprintf(msg, sizeof(msg), "%s is not declared", tokens[i].value);
                    add_error(tokens[i].line_number, "Undeclared identifier", msg);
                }
            }
        }
    }
}

static void step_detect_errors()
{
    printf("Step 4: Detect and report syntax errors\n\n");

    check_duplicate_declarations(); // x1 declared twice globally
    check_duplicate_keywords();     // int int
    check_unmatched_else();         // else without if
    check_parentheses_and_braces(); // mismatched parentheses/braces
    check_undeclared_identifiers(); // y not declared

    sort_and_show_errors();
}

// ---------- Error helpers ----------
static void add_error(int line, const char *type, const char *desc)
{
    if (errcount >= MAX_ERRORS)
        return;
    errors[errcount].line_number = line;
    strncpy(errors[errcount].error_type, type, sizeof(errors[errcount].error_type) - 1);
    errors[errcount].error_type[sizeof(errors[errcount].error_type) - 1] = '\0';
    strncpy(errors[errcount].description, desc, sizeof(errors[errcount].description) - 1);
    errors[errcount].description[sizeof(errors[errcount].description) - 1] = '\0';
    errcount++;
}

static void sort_and_show_errors()
{
    // Sort errors by line number
    for (int i = 0; i < errcount - 1; i++)
    {
        for (int j = i + 1; j < errcount; j++)
        {
            if (errors[i].line_number > errors[j].line_number)
            {
                SyntaxError t = errors[i];
                errors[i] = errors[j];
                errors[j] = t;
            }
        }
    }

    if (errcount == 0)
    {
        printf("No syntax errors found.\n");
        return;
    }

    printf("Syntax Errors (sorted by line number):\n\n");
    printf("Line\tError Type\t\t\tDescription\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < errcount; i++)
    {
        printf("%d\t%s\t\t%s\n", errors[i].line_number, errors[i].error_type, errors[i].description);
    }
    printf("\n");
}