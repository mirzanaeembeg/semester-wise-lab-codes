#include <stdio.h>

int fact (int n);
int main()
{
    int n;
    scanf("%d", &n);
    printf("factorial is : %d",fact(n));
    return 0;
}
int fact(int n)
{
    int factn;
    if(n == 1)
        return;
    factn=fact(n-1)*n;
    return factn;
}
