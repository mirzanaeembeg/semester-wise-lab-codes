#include <stdio.h>

#define MAX_SIZE 10

void forwardElimination(int n, double matrix[MAX_SIZE][MAX_SIZE + 1]) {
    int i, j, k;
    double factor;

    // Forward elimination
    for (k = 0; k < n - 1; k++) {
        for (i = k + 1; i < n; i++) {
            factor = matrix[i][k] / matrix[k][k];
            for (j = k; j <= n; j++) {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }
}

void forwardSubstitution(int n, double matrix[MAX_SIZE][MAX_SIZE + 1], double solution[MAX_SIZE]) {
    int k, j;
    double sum;

    // Compute x[n]
    solution[n - 1] = matrix[n - 1][n] / matrix[n - 1][n - 1];

    // Forward substitution
    for (k = n - 2; k >= 0; k--) {
        sum = 0;
        for (j = k + 1; j < n; j++) {
            sum += matrix[k][j] * solution[j];
        }
        solution[k] = (matrix[k][n] - sum) / matrix[k][k];
    }
}

int main() {
    int n,i,j,k;

    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    double matrix[MAX_SIZE][MAX_SIZE + 1];
    double solution[MAX_SIZE];

    // Input coefficients of the linear equation
    printf("Enter the coefficients of the linear equations:\n");
    for (k = 0; k < n; k++) {
        for (j = 0; j <= n; j++) {
            scanf("%lf", &matrix[k][j]);
        }
    }

    // Perform Gaussian elimination without pivoting
    forwardElimination(n, matrix);
    forwardSubstitution(n, matrix, solution);

    // Print the solution vector
    printf("\nSolution Vector:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2lf\n", i + 1, solution[i]);
    }

    return 0;
}

