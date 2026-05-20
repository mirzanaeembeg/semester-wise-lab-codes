#include <stdio.h>

#define MAX_SIZE 10

void print_matrix(int n, double matrix[MAX_SIZE][MAX_SIZE+1])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%lf ",matrix[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void gaussianElimination(int n, double matrix[MAX_SIZE][MAX_SIZE + 1]) {
    int i, j, k;
    double pivot, factor;

    // Forward elimination
    for (i = 0; i < n; i++) {
        pivot = matrix[i][i];

        for (j = i; j <= n; j++) {
            matrix[i][j] /= pivot;
            //print_matrix(n,matrix);
        }
        print_matrix(n,matrix);

        for (k = 0; k < n; k++) {
            if (k != i) {
                factor = matrix[k][i];
                for (j = i; j <= n; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                    //print_matrix(n,matrix);
                }
            }
            print_matrix(n,matrix);
        }
    }
}

int main() {
    int n;
    int i,j;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double matrix[MAX_SIZE][MAX_SIZE + 1];

    printf("Enter the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    gaussianElimination(n, matrix);

    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2lf\n", i + 1, matrix[i][n]);
    }

    return 0;
}
