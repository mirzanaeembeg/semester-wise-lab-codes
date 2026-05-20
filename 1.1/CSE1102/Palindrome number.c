#include <stdio.h>
int main ()
{
    int num,rev=0,rem,tem;
    scanf("%d",&num);
    tem=num;
    while(tem!=0)
    {
        rem=tem%10;
        rev=rev*10+rem;
        tem=tem/10;
    }
    printf("Reverse number = %d\n",rev);
    if(rev==num)
        printf("%d is a Palindrome number",rev);
    else
        printf("%d is Not a palindrome number", num);
    return 0;
}
