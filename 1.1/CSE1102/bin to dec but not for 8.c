#include <stdio.h>
int main()
{
    int i, bin=0,dec,temp,rem;
    printf("Enter a decimal number:");
    scanf("%d", &dec);
    temp=dec;
    for(i =0; temp!=0; i++)
    {
        rem=temp%2;
        bin=bin*10+rem;
        temp=temp/2;
    }
    printf("Bin of %d is %d",dec,bin);
    return 0;
}
