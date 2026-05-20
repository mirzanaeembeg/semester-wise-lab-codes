#include <stdio.h>
int main()
{
    int num,temp,rem,arm=0;
    scanf("%d", &num);
    temp=num;
    while(temp!=0)
    {
        rem=temp%10;
        arm=arm+(rem*rem*rem);
        temp=temp/10;
    }
    if(arm == num)
        printf("armstrong");
    else
        printf("not armstrong");
    return 0;
}
