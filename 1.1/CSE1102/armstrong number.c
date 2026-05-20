#include <stdio.h>
int main ()
{
    int num,arm,rem,temp,start,end;
    scanf("%d%d",&start,&end);
    for(int i=start; i<=end; i++)
    {
        temp=i;
        while(temp!=0)
        {
            rem=temp%10;
            arm=arm+rem*rem*rem;
            temp=temp/10;
        }
        if(arm==i)
            printf("%d ",i);
        arm=0;
    }

    return 0;
}
