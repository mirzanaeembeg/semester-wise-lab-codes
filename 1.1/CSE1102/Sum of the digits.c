#include <stdio.h>
void main()
{
    int x,digit,sum=0;
    scanf("%d",&x);
    for(;x!=0;)
    {
        digit=x%10;
        sum+=digit;
        x=x/10;
    }
    printf("sum=%d",sum);

    return 0;
}
