#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEXEME_LENGTH 100
#define MAX_LEXEMES 1000

// Token types
typedef enum
{
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    SEPARATOR,
    UNKNOWN
} TokenType;

// Structure to store lexemes and their tokens
typedef struct
{
    char lexeme[MAX_LEXEME_LENGTH];
    char token[20];
} LexemeToken;

// C Keywords (Only the 32 standard C keywords)
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

// Built-in library functions
const char *libraryFunctions[] = {
    "printf", "scanf", "puts", "gets", "putchar", "getchar", "strlen", "strcpy",
    "strcmp", "strcat", "malloc", "free", "fopen", "fclose", "fread", "fwrite",
    "fprintf", "fscanf", "fgetc", "fputc", "fgets", "fputs", "exit", "system",
    "memcpy", "memset", "memcmp", "atoi", "atof", "itoa", "abs", "sqrt",
    "pow", "sin", "cos", "tan", "log", "exp", "ceil", "floor", "rand", "srand"};

int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
int numLibraryFunctions = sizeof(libraryFunctions) / sizeof(libraryFunctions[0]);

// DFA for Identifier Recognition
// States: 0=start, 1=valid identifier
int identifierDFA(char *lexeme)
{
    int state = 0;
    int i = 0;
    int len = strlen(lexeme);

    if (len == 0)
        return 0;

    // Check first character
    if (isalpha(lexeme[0]) || lexeme[0] == '_')
    {
        state = 1;
        i = 1;
    }
    else
    {
        return 0; // Invalid identifier
    }

    // Check remaining characters
    while (i < len && state == 1)
    {
        if (isalnum(lexeme[i]) || lexeme[i] == '_')
        {
            i++;
        }
        else
        {
            state = 0; // Invalid character found
            break;
        }
    }

    return (state == 1 && i == len) ? 1 : 0;
}

// DFA for Numeric Constants Recognition
// States: 0=start, 1=integer part, 2=decimal point, 3=fractional part
int numericDFA(char *lexeme)
{
    int state = 0;
    int i = 0;
    int len = strlen(lexeme);

    if (len == 0)
        return 0;

    // State 0: Start state
    if (isdigit(lexeme[i]))
    {
        state = 1;
        i++;
    }
    else
    {
        return 0;
    }

    // State 1: Reading integer part
    while (i < len && state == 1)
    {
        if (isdigit(lexeme[i]))
        {
            i++;
        }
        else if (lexeme[i] == '.')
        {
            state = 2;
            i++;
            break;
        }
        else
        {
            state = 0;
            break;
        }
    }

    // If we finished in state 1, it's a valid integer
    if (state == 1 && i == len)
        return 1;

    // State 2: After decimal point
    if (state == 2)
    {
        if (i < len && isdigit(lexeme[i]))
        {
            state = 3;
            i++;
        }
        else
        {
            state = 0; // No digit after decimal point
        }
    }

    // State 3: Reading fractional part
    while (i < len && state == 3)
    {
        if (isdigit(lexeme[i]))
        {
            i++;
        }
        else
        {
            state = 0;
            break;
        }
    }

    return (state == 3 && i == len) ? 1 : 0;
}

// Check if a string is a keyword
int isKeyword(char *lexeme)
{
    for (int i = 0; i < numKeywords; i++)
    {
        if (strcmp(lexeme, keywords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Check if a string is a library function
int isLibraryFunction(char *lexeme)
{
    for (int i = 0; i < numLibraryFunctions; i++)
    {
        if (strcmp(lexeme, libraryFunctions[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Check if character is an operator
int isOperatorChar(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
            c == '=' || c == '!' || c == '<' || c == '>' || c == '&' ||
            c == '|' || c == '^' || c == '~');
}

// Check if character is a separator
int isSeparatorChar(char c)
{
    return (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' ||
            c == ';' || c == ',');
}

// Tokenize the lexeme
void tokenizeLexeme(char *lexeme, char *token)
{
    if (strlen(lexeme) == 0)
    {
        strcpy(token, "unkn");
        return;
    }

    // Check for preprocessor directives
    if (lexeme[0] == '#')
    {
        strcpy(token, "prep");
    }
    // Check for header files (ends with .h)
    else if (strlen(lexeme) > 2 && lexeme[strlen(lexeme) - 2] == '.' && lexeme[strlen(lexeme) - 1] == 'h')
    {
        strcpy(token, "header");
    }
    // Check for keywords
    else if (isKeyword(lexeme))
    {
        strcpy(token, "kw");
    }
    // Check for library functions
    else if (isLibraryFunction(lexeme))
    {
        strcpy(token, "lib");
    }
    // Check for identifiers using DFA
    else if (identifierDFA(lexeme))
    {
        strcpy(token, "id");
    }
    // Check for numeric constants using DFA
    else if (numericDFA(lexeme))
    {
        strcpy(token, "num");
    }
    // Check for string literals
    else if (strlen(lexeme) >= 2 && lexeme[0] == '"' && lexeme[strlen(lexeme) - 1] == '"')
    {
        strcpy(token, "str");
    }
    // Check for operators
    else if (strlen(lexeme) == 1 && isOperatorChar(lexeme[0]))
    {
        strcpy(token, "op");
    }
    else if (strlen(lexeme) == 2 &&
             ((strcmp(lexeme, "==") == 0) || (strcmp(lexeme, "!=") == 0) ||
              (strcmp(lexeme, "<=") == 0) || (strcmp(lexeme, ">=") == 0) ||
              (strcmp(lexeme, "&&") == 0) || (strcmp(lexeme, "||") == 0) ||
              (strcmp(lexeme, "++") == 0) || (strcmp(lexeme, "--") == 0) ||
              (strcmp(lexeme, "<<") == 0) || (strcmp(lexeme, ">>") == 0)))
    {
        strcpy(token, "op");
    }
    // Check for separators
    else if (strlen(lexeme) == 1 && isSeparatorChar(lexeme[0]))
    {
        strcpy(token, "sep");
    }
    // Unknown token
    else
    {
        strcpy(token, "unkn");
    }
}

// Extract lexemes from input
int extractLexemes(char *input, LexemeToken lexemes[])
{
    int count = 0;
    int i = 0;
    int len = strlen(input);

    while (i < len && count < MAX_LEXEMES)
    {
        // Skip whitespace
        while (i < len && isspace(input[i]))
        {
            i++;
        }

        if (i >= len)
            break;

        char lexeme[MAX_LEXEME_LENGTH];
        int lexemeIndex = 0;

        // Handle preprocessor directives like #include
        if (input[i] == '#')
        {
            lexeme[lexemeIndex++] = input[i++];
            // Continue reading alphanumeric characters
            while (i < len && isalpha(input[i]))
            {
                lexeme[lexemeIndex++] = input[i++];
            }
            lexeme[lexemeIndex] = '\0';
            strcpy(lexemes[count].lexeme, lexeme);
            count++;
            continue;
        }

        // Handle header files like stdio.h
        if (isalpha(input[i]))
        {
            int start = i;
            // Read alphanumeric characters
            while (i < len && isalnum(input[i]))
            {
                lexeme[lexemeIndex++] = input[i++];
            }
            // Check if followed by .h
            if (i < len && input[i] == '.' && i + 1 < len && input[i + 1] == 'h')
            {
                lexeme[lexemeIndex++] = input[i++]; // add '.'
                lexeme[lexemeIndex++] = input[i++]; // add 'h'
            }
            lexeme[lexemeIndex] = '\0';
            strcpy(lexemes[count].lexeme, lexeme);
            count++;
            continue;
        }

        // Handle underscore-starting identifiers
        if (input[i] == '_')
        {
            while (i < len && (isalnum(input[i]) || input[i] == '_'))
            {
                lexeme[lexemeIndex++] = input[i++];
            }
            lexeme[lexemeIndex] = '\0';
            strcpy(lexemes[count].lexeme, lexeme);
            count++;
            continue;
        }

        // Handle two-character operators
        if (i + 1 < len)
        {
            char twoChar[3] = {input[i], input[i + 1], '\0'};
            if (strcmp(twoChar, "==") == 0 || strcmp(twoChar, "!=") == 0 ||
                strcmp(twoChar, "<=") == 0 || strcmp(twoChar, ">=") == 0 ||
                strcmp(twoChar, "&&") == 0 || strcmp(twoChar, "||") == 0 ||
                strcmp(twoChar, "++") == 0 || strcmp(twoChar, "--") == 0 ||
                strcmp(twoChar, "<<") == 0 || strcmp(twoChar, ">>") == 0)
            {
                strcpy(lexemes[count].lexeme, twoChar);
                i += 2;
                count++;
                continue;
            }
        }

        // Handle single character operators and separators
        if (isOperatorChar(input[i]) || isSeparatorChar(input[i]))
        {
            lexeme[0] = input[i];
            lexeme[1] = '\0';
            strcpy(lexemes[count].lexeme, lexeme);
            i++;
            count++;
            continue;
        }

        // Handle numeric constants
        if (isdigit(input[i]))
        {
            while (i < len && (isdigit(input[i]) || input[i] == '.'))
            {
                lexeme[lexemeIndex++] = input[i++];
            }
            lexeme[lexemeIndex] = '\0';
            strcpy(lexemes[count].lexeme, lexeme);
            count++;
            continue;
        }

        // Handle string literals
        if (input[i] == '"') {
            lexeme[lexemeIndex++] = input[i++];
            while (i < len && input[i] != '"') {
                lexeme[lexemeIndex++] = input[i++];
            }
            if (i < len && input[i] == '"') {
                lexeme[lexemeIndex++] = input[i++];
            }
            lexeme[lexemeIndex] = '\0';
            strcpy(lexemes[count].lexeme, lexeme);
            count++;
            continue;
        }

        // Handle unknown characters
        lexeme[0] = input[i];
        lexeme[1] = '\0';
        strcpy(lexemes[count].lexeme, lexeme);
        i++;
        count++;
    }

    return count;
}

// Display file contents
void displayFile(const char *filename, const char *title)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    printf("%s\n", title);
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        putchar(c);
    }
    printf("\n");
    fclose(file);
}

// Read input file
char *readInputFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Cannot open input file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(fileSize + 1);
    if (!content)
    {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    fread(content, 1, fileSize, file);
    content[fileSize] = '\0';
    fclose(file);

    return content;
}

int main()
{
    const char *inputFile = "input.txt";
    const char *step1File = "step1_output.txt";
    const char *step2File = "step2_output.txt";

    // Read input file
    char *input = readInputFile(inputFile);
    if (!input)
    {
        return 1;
    }

    // Display input
    displayFile(inputFile, "Sample Input: input.txt");

    // Extract lexemes
    LexemeToken lexemes[MAX_LEXEMES];
    int lexemeCount = extractLexemes(input, lexemes);

    // Step 1: Write separated lexemes (horizontal with spaces)
    FILE *step1 = fopen(step1File, "w");
    if (step1)
    {
        for (int i = 0; i < lexemeCount; i++)
        {
            fprintf(step1, "%s", lexemes[i].lexeme);
            if (i < lexemeCount - 1)
            {
                fprintf(step1, " ");
            }
        }
        fprintf(step1, "\n");
        fclose(step1);
    }

    // Step 2: Tokenize lexemes (horizontal with square brackets)
    FILE *step2 = fopen(step2File, "w");
    if (step2)
    {
        for (int i = 0; i < lexemeCount; i++)
        {
            tokenizeLexeme(lexemes[i].lexeme, lexemes[i].token);
            fprintf(step2, "[%s %s]", lexemes[i].token, lexemes[i].lexeme);
            if (i < lexemeCount - 1)
            {
                fprintf(step2, " ");
            }
        }
        fprintf(step2, "\n");
        fclose(step2);
    }

    // Display outputs
    printf("\nSample Output:\n");
    displayFile(step1File, "\nStep 1:");
    displayFile(step2File, "\nStep 2:");

    free(input);
    return 0;
}