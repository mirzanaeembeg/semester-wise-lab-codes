#include <stdio.h>
int main()
{
    int a,b;
    printf("Enter two number:");
    scanf("%d%d",&a,&b);
    if(a>b)
        printf("%d is maximum and %d is minimum",a,b);
    else
        printf("%d is maximum and %d is minimum",b,a);

    return 0;
}
