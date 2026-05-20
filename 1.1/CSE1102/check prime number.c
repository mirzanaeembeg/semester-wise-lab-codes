#include <stdio.h>

int main()
{
    int i, num;
    printf("Enter a number:");
    scanf("%d",&num);

    if(num==1)
        printf("Co-prime");


    for(i=2; i<num; i++)
    {
        if(num%i==0)
        {
            printf("Not a prime number\n");
            break;
        }
    }
    if(i==num)
        printf("Prime number");

    return 0;
}
