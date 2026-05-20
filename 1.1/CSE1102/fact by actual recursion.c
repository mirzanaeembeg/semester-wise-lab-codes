#include <stdio.h>
int rec(int a);

int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",rec(a));
    return 0;
}

int rec(int x)
{
    int f;
    if(x == 1)
        return 1;

    f=x*rec(x-1);
    return f;
}
