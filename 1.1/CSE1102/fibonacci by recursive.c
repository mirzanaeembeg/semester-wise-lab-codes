#include <stdio.h>

int fib(int n);
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d",fib(n));
    return 0;
}
int fib(int n)
{
    int fibn;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    fibn = fib(n-1) + fib(n-2);
    return fibn;
}
