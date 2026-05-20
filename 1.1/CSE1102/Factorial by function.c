#include <stdio.h>
int fact(int);
void main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fact(n));
}

int fact(int x)
{
    int fact=1;
    for(int i=1; i<=x; i++)
    {
        fact=fact*i;
    }

    return fact;
}

