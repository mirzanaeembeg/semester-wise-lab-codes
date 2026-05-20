
#include <stdio.h>
int main()

{
    int i,j,k,l,m,n,o,p;

    for(i=1; i<=5; i++)
    {
        for(j=i; j<5; j++)
        {
            printf(" ");
        }
        for(j=1; j<=(2*i-1); j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(k=1; k<=5; k++)
    {
        for(l=k; l<5; l++)
        {
            printf(" ");
        }
        for(l=1; l<=(2*k-1); l++)
        {
            if(k==5 || l==1 || l==(2*k-1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(m=1; m<=5; m++)
    {
        for(n=1; n<=5; n++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(o=1; o<=5; o++)
    {
        for(p=1; p<=5; p++)
        {
            if(o==1 || o==5 || p==1 || p==5)

            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    int stars, spaces;
    stars = 1, spaces = 4;

    for(int i=1; i<5*2; i++)
    {
        for(int j=1; j<=spaces; j++)
            printf(" ");
        for(int j=1; j<stars*2; j++)
            printf("*");
        printf("\n");
        if(i<5)
        {
            spaces--;
            stars++;
        }
        else
        {
            spaces++;
            stars--;
        }
    }

    return 0;
}
