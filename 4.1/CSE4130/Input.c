// This is a sample C program with comments
#include <stdio.h>
#include <stdlib.h>

/* This is a multi-line comment
   that spans multiple lines
   and should be removed */

int main() {
    int x = 10;    // Initialize variable x
    int y = 20;    /* Another comment */

    /* Calculate sum */
    int sum = x + y;

    // Print the result
    printf("Sum: %d\n", sum);

    /* 
     * This is a block comment
     * with multiple lines
     */

    printf("This string contains // but it's not a comment\n");
    printf("This string contains /* but it's not a comment */\n");

    char c = '/';  // Single slash character

    return 0;  // Return success
}