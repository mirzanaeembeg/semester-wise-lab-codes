#include <stdio.h>

int sum(int n);
int main()
{
    int n;
    scanf("%d", &n);
    printf("sum of the series: %d", sum(n));
    return 0;
}
int sum(int n)
{
    int nsum=0;
    if(n == 1)
        return;
    nsum = sum(n-1)+n;
    return nsum;
}
