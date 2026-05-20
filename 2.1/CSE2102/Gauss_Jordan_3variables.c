#include<stdio.h>
int main()
{
    double a[3][4],x,y,z;
    int i,j,k;
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
            scanf("%lf",&a[i][j]);


    ///Upper triangular matrix for GJ
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(j!=i)
            {
                double c=a[j][i]/a[i][i];
                for(k=0;k<4;k++)
                    a[j][k]=a[j][k]-c*a[i][k];
            }
        }
    }

    z=a[2][3]/a[2][2];
    y=a[1][3]/a[1][1];
    x=a[0][3]/a[0][0];

    printf("x = %.2lf, y = %.2lf, z = %.2lf\n",x,y,z);


    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
            printf("%.2lf ",a[i][j]);
        printf("\n");
    }

}
/*
1 1 1 9
2 -3 4 13
3 4 5 40

*/



