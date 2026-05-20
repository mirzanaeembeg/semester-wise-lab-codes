//bin to dec
#include <stdio.h>
int main()
{
    int bin,temp,rem,dec=0;
    printf("Enter a bin number:");
    scanf("%d", &bin);
    temp=bin;
    for(int i=0;temp!=0;i++)
    {
        rem=temp%10;
        dec=dec+rem*pow(2,i);
        temp=temp/10;
    }
    printf("Dec of %d is %d",bin,dec);

    return 0;
}
