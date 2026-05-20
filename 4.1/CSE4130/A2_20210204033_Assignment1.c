#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to display file contents
void displayFile(const char* filename, const char* title) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }
    
    printf("%s\n", title);
    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    fclose(file);
}

// Function to remove comments and clean whitespace
void processFile(const char* inputFile, const char* outputFile) {
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");
    
    if (!input) {
        printf("Error: Cannot open input file %s\n", inputFile);
        return;
    }
    
    if (!output) {
        printf("Error: Cannot create output file %s\n", outputFile);
        fclose(input);
        return;
    }
    
    int current, next;
    int inSingleComment = 0;
    int inMultiComment = 0;
    int inString = 0;
    int inChar = 0;
    int prevWasSpace = 1; // Change from 0 to 1 to prevent leading space
    int writtenChar = 0;  // Track if any non-space character has been written

    
    while ((current = fgetc(input)) != EOF) {
        // Lookahead for next character
        next = fgetc(input);
        if (next != EOF) {
            ungetc(next, input);
        }
        
        // Handle string literals
        if (current == '"' && !inSingleComment && !inMultiComment && !inChar) {
            inString = !inString;
            fputc(current, output);
            prevWasSpace = 0;
            continue;
        }
        
        // Handle character literals
        if (current == '\'' && !inSingleComment && !inMultiComment && !inString) {
            inChar = !inChar;
            fputc(current, output);
            prevWasSpace = 0;
            continue;
        }
        
        // Preserve content inside strings and character literals
        if (inString || inChar) {
            fputc(current, output);
            prevWasSpace = 0;
            continue;
        }
        
        // Handle single-line comments
        if (current == '/' && next == '/' && !inMultiComment) {
            inSingleComment = 1;
            continue;
        }
        
        // Handle multi-line comments start
        if (current == '/' && next == '*' && !inSingleComment) {
            inMultiComment = 1;
            fgetc(input); // consume the '*'
            continue;
        }
        
        // Handle multi-line comments end
        if (current == '*' && next == '/' && inMultiComment) {
            inMultiComment = 0;
            fgetc(input); // consume the '/'
            continue;
        }
        
        // Handle end of single-line comment
        if (current == '\n' && inSingleComment) {
            inSingleComment = 0;
            // Don't output the newline, let it be handled by whitespace logic
        }
        
        // Skip characters inside comments
        if (inSingleComment || inMultiComment) {
            continue;
        }
        
        // Handle whitespace - compress multiple whitespace into single space
        if (current == ' ' || current == '\t' || current == '\n' || current == '\r') {
            if (!prevWasSpace && writtenChar) { // Only write space after first non-space character
                fputc(' ', output);
                prevWasSpace = 1;
            }
        } else {
            fputc(current, output);
            prevWasSpace = 0;
            writtenChar = 1; // Mark that we've written a non-space character
        }
    }
    
    fclose(input);
    fclose(output);
}

int main() {
    const char* inputFile = "Input.c";
    const char* outputFile = "output.txt";
    
    // Display input file
    displayFile(inputFile, "Sample Input: Input.c");
    
    // Process the file
    processFile(inputFile, outputFile);
    
    // Display output file
    displayFile(outputFile, "\nSample Output: output.txt");
    
    return 0;
}