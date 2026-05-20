#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter three length of the sides of a triangle:\n");
    scanf("%d%d%d", &a, &b, &c);
    if(((a+b)>c) && ((b+c)>a) &&((a+c)>b))
        printf("right");
    else
        printf("wrong");
    return 0;
}
