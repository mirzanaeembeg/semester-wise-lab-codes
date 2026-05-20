#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_SYMBOLS 100
#define MAX_NAME_LEN 50
#define MAX_SCOPE_LEN 20
#define MAX_TYPE_LEN 20

// Structure to store token information
typedef struct {
    char type[20];  // kw, id, op, num, sep, par, brc
    char value[50]; // actual token value
} Token;

// Structure for Symbol Table entry
typedef struct {
    int sl_no;
    char name[MAX_NAME_LEN];
    char id_type[MAX_TYPE_LEN];  // var, func
    char data_type[MAX_TYPE_LEN]; // int, float, double, etc.
    char scope[MAX_SCOPE_LEN];   // global, function name
    char value[MAX_NAME_LEN];    // assigned value
    int symbol_id;               // unique id for modified token stream
} SymbolEntry;

// Global variables
Token tokens[MAX_TOKENS];
SymbolEntry symbol_table[MAX_SYMBOLS];
int token_count = 0;
int symbol_count = 0;
char current_scope[MAX_SCOPE_LEN] = "global";
int next_symbol_id = 1;

// Function prototypes
void read_input_file(const char* filename);
void tokenize_input(const char* input);
void parse_tokenized_input(const char* input);
void step1_extract_tokens();
void step2_build_symbol_table();
void step3_symbol_table_operations();
void step4_generate_modified_tokens();
void write_output_file();


// Symbol table operations
int insert(const char* name, const char* id_type, const char* data_type, const char* scope);
void set_attribute(const char* name, const char* attribute, const char* value);
void free_symbol_table();
SymbolEntry* lookup(const char* name, const char* scope);
void display_symbol_table();

int main() {

    // Read input from file
    read_input_file("input.txt");
    
    // Step 1: Extract tokens (already done during file reading)
    step1_extract_tokens();
    
    // Step 2: Build symbol table
    step2_build_symbol_table();
    
    // Step 3: Implement symbol table operations
    step3_symbol_table_operations();
    
    // Step 4: Generate modified token stream
    step4_generate_modified_tokens();
    
    // Write to output file and display results
    write_output_file();
    
    // Clean up
    free_symbol_table();
    
    return 0;
}

void read_input_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Input file not found!");
        return;
    }
    
    char buffer[1000];
    char full_input[2000] = "";
    
    while (fgets(buffer, sizeof(buffer), file)) {
        strcat(full_input, buffer);
        strcat(full_input, " ");
    }
    
    fclose(file);
    
    parse_tokenized_input(full_input);
}

void parse_tokenized_input(const char* input) {
    int i = 0;
    char token_type[20], token_value[50];
    
    while (input[i] != '\0') {
        if (input[i] == '[') {
            i++; // skip '['
            int j = 0;
            
            // Extract token type
            while (input[i] != ' ' && input[i] != ']' && input[i] != '\0') {
                token_type[j++] = input[i++];
            }
            token_type[j] = '\0';
            
            j = 0;
            if (input[i] == ' ') {
                i++; // skip space
                // Extract token value
                while (input[i] != ']' && input[i] != '\0') {
                    token_value[j++] = input[i++];
                }
            } else {
                // No value, type is the value (like keywords)
                strcpy(token_value, token_type);
                strcpy(token_type, "kw"); // assume keywords for single tokens
            }
            token_value[j] = '\0';
            
            // Store token
            strcpy(tokens[token_count].type, token_type);
            strcpy(tokens[token_count].value, token_value);
            token_count++;
            
            // Skip ']'
            if (input[i] == ']') i++;
        } else {
            i++;
        }
    }
}

void step1_extract_tokens() {
    printf("Sample Input: Input.c\n\n");
    // Display original tokenized input
    for (int i = 0; i < token_count; i++) {
        printf("[%s %s] ", tokens[i].type, tokens[i].value);
    }
    printf("\n\n");
    
    // Display tokens with only identifiers kept (Step 1 requirement)
    printf("Step 1:\n");
    for (int i = 0; i < token_count; i++) {
        if (strcmp(tokens[i].type, "id") == 0) {
            printf("[%s] ", tokens[i].value);
        } else if (strcmp(tokens[i].type, "kw") == 0) {
            printf("[%s] ", tokens[i].value);
        } else {
            printf("[%s] ", tokens[i].value);
        }
    }
    printf("\n\n");
}

void step2_build_symbol_table() {
    printf("Step 2:\n");
    
    char current_data_type[MAX_TYPE_LEN] = "";
    char current_function[MAX_SCOPE_LEN] = "global";
    
    for (int i = 0; i < token_count; i++) {
        // Check for data type keywords
        if (strcmp(tokens[i].type, "kw") == 0) {
            if (strcmp(tokens[i].value, "int") == 0 || 
                strcmp(tokens[i].value, "float") == 0 || 
                strcmp(tokens[i].value, "double") == 0 || 
                strcmp(tokens[i].value, "char") == 0) {
                strcpy(current_data_type, tokens[i].value);
            }
        }
        
        // Process identifiers
        if (strcmp(tokens[i].type, "id") == 0) {
            // Check if it's already in symbol table
            if (lookup(tokens[i].value, current_scope) == NULL) {
                // Determine if it's a function (followed by parentheses)
                const char* id_type = "var";
                if (i + 1 < token_count && strcmp(tokens[i + 1].value, "(") == 0) {
                    id_type = "func";
                    strcpy(current_function, tokens[i].value);
                }
                
                // Insert into symbol table
                int id = insert(tokens[i].value, id_type, current_data_type, 
                              (strcmp(id_type, "func") == 0) ? "global" : current_function);
                
                // Check for assignment values
                if (i + 2 < token_count && strcmp(tokens[i + 1].value, "=") == 0) {
                    set_attribute(tokens[i].value, "value", tokens[i + 2].value);
                }
            }
        }
        
        // Update scope based on braces
        if (strcmp(tokens[i].type, "brc") == 0) {
            if (strcmp(tokens[i].value, "{") == 0) {
                strcpy(current_scope, current_function);
            } else if (strcmp(tokens[i].value, "}") == 0) {
                strcpy(current_scope, "global");
                strcpy(current_function, "global");
            }
        }
    }
    
    display_symbol_table();
}

void step3_symbol_table_operations() {
    printf("\nStep 3: Symbol Table Operations Implemented\n");
    printf("- insert(): Add new entries to symbol table\n");
    printf("- set_attribute(): Set attributes for existing entries\n");
    printf("- lookup(): Search for entries in symbol table\n");
    printf("- display(): Show complete symbol table\n");
    printf("- free(): Clean up symbol table memory\n\n");
}

void step4_generate_modified_tokens() {
    printf("Step 4:\n");
    
    for (int i = 0; i < token_count; i++) {
        if (strcmp(tokens[i].type, "id") == 0) {
            // Find the symbol in the table and replace with its serial number
            SymbolEntry* entry = lookup(tokens[i].value, current_scope);
            if (entry != NULL) {
                printf("[id %d] ", entry->sl_no);  // Use serial number instead of symbol_id
            } else {
                printf("[id %s] ", tokens[i].value);
            }
        } else if (strcmp(tokens[i].type, "kw") == 0) {
            printf("[%s] ", tokens[i].value);
        } else {
            printf("[%s] ", tokens[i].value);
        }
    }
    printf("\n\n");
}

// Symbol Table Operations Implementation

int insert(const char* name, const char* id_type, const char* data_type, const char* scope) {
    if (symbol_count >= MAX_SYMBOLS) {
        printf("Symbol table is full!\n");
        return -1;
    }
    
    symbol_table[symbol_count].sl_no = symbol_count + 1;
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].id_type, id_type);
    strcpy(symbol_table[symbol_count].data_type, data_type);
    strcpy(symbol_table[symbol_count].scope, scope);
    symbol_table[symbol_count].value[0] = '\0'; // Initialize empty
    symbol_table[symbol_count].symbol_id = next_symbol_id++;
    
    symbol_count++;
    return symbol_count - 1;
}

void set_attribute(const char* name, const char* attribute, const char* value) {
    SymbolEntry* entry = lookup(name, current_scope);
    if (entry != NULL) {
        if (strcmp(attribute, "value") == 0) {
            strcpy(entry->value, value);
        }
    }
}

void free_symbol_table() {
    symbol_count = 0;
    next_symbol_id = 1;
    printf("Symbol table memory freed.\n");
}

SymbolEntry* lookup(const char* name, const char* scope) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

void display_symbol_table() {
    printf("Sl. No.\tName\tId Type\tData Type\tScope\t\tValue\n");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < symbol_count; i++) {
        printf("%d\t%s\t%s\t%s\t\t%s\t\t%s\n",
               symbol_table[i].sl_no,
               symbol_table[i].name,
               symbol_table[i].id_type,
               symbol_table[i].data_type,
               symbol_table[i].scope,
               symbol_table[i].value);
    }
    printf("\n");
}

void write_output_file() {
    FILE* output = fopen("output.txt", "w");
    if (!output) {
        printf("Error creating output file!\n");
        return;
    }
    
    fprintf(output, "=== Symbol Table Construction Output ===\n\n");
    
    // Write Step 1
    fprintf(output, "Step 1:\n");
    for (int i = 0; i < token_count; i++) {
        fprintf(output, "[%s %s]", tokens[i].type, tokens[i].value);
        if ((i + 1) % 10 == 0) fprintf(output, "\n");
    }
    fprintf(output, "\n\n");
    
    // Write Step 2 - Symbol Table
    fprintf(output, "Step 2:\n");
    fprintf(output, "Sl. No.\tName\tId Type\tData Type\tScope\t\tValue\n");
    fprintf(output, "---------------------------------------------------------------\n");
    
    for (int i = 0; i < symbol_count; i++) {
        fprintf(output, "%d\t%s\t%s\t%s\t\t%s\t\t%s\n",
                symbol_table[i].sl_no,
                symbol_table[i].name,
                symbol_table[i].id_type,
                symbol_table[i].data_type,
                symbol_table[i].scope,
                symbol_table[i].value);
    }
    fprintf(output, "\n\n");
    
    // Write Step 4 - Modified Token Stream
    fprintf(output, "Step 4:\n");
    for (int i = 0; i < token_count; i++) {
        if (strcmp(tokens[i].type, "id") == 0) {
            SymbolEntry* entry = lookup(tokens[i].value, current_scope);
            if (entry != NULL) {
                fprintf(output, "[id %d]", entry->symbol_id);
            } else {
                fprintf(output, "[id %s]", tokens[i].value);
            }
        } else if (strcmp(tokens[i].type, "kw") == 0) {
            fprintf(output, "[%s]", tokens[i].value);
        } else {
            fprintf(output, "[%s]", tokens[i].value);
        }
        
        if ((i + 1) % 15 == 0) fprintf(output, "\n");
    }
    fprintf(output, "\n");
    
    fclose(output);
    printf("Output written to 'output.txt'\n");
}
