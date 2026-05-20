#include <stdio.h>
int main ()
{
    int n,rvs=0,j;
    printf("enter a number:");
    scanf("%d", &n);
    for( ; n!=0 ; )
    {
        j = n % 10;
        rvs = rvs*10+j;
        n = n / 10;


    }
    printf("revers = %d",rvs);
    return 0;
}
