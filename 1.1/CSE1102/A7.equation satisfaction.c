#include <stdio.h>
int main()
{
    int a, b, c, d;
    printf("Enter an integer for a:");
    scanf("%d", &a);
    printf("\nEnter an integer for b:");
    scanf("%d", &b);
    printf("\nEnter an integer for c:");
    scanf("%d", &c);
    printf("\nEnter an integer for d:");
    scanf("%d", &d);
    if(a*a*a+b*b*b+c*c*c==d*d*d)
        {
         printf("\nThe equation a3+b3+c3=d3 is satisfied!");
        }
    else
    {
        printf("\nThe equation a3+b3+c3=d3 is not satisfied!");
    }
    return 0;
}
