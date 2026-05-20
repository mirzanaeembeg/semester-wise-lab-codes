#include<stdio.h>

#define MAX 10

void gauss_jordan(int n, double matrix[MAX][MAX+1])
{
    int i,j,k;
    double pivot, factor;
    for(i=0;i<n;i++)
    {
        pivot=matrix[i][i];
        for(j=i;j<=n;j++)
        {
            matrix[i][j]=matrix[i][j]/pivot;
        }
        for(k=0;k<n;k++)
        {
            if(k!=i)
            {
                factor=matrix[k][i];
                for(j=i;j<=n;j++)
                {
                    matrix[k][j]=matrix[k][j]-factor*matrix[i][j];
                }
            }
        }
    }
}

int main()
{
    int n,i,j;
    printf("Enter number of equations:");
    scanf("%d",&n);

    double matrix[MAX][MAX+1];

    printf("Input matrix:");

    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            scanf("%lf",&matrix[i][j]);
    }

    gauss_jordan(n,matrix);

    for(i=0;i<n;i++)
    {
        printf("x%d = %.2lf\n",i+1,matrix[i][n]);
    }

}
