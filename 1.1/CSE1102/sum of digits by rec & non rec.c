#include <stdio.h>
int nrdSum(int x);
int rdSum(int x);
int main()
{
    int a,s,t;
    scanf("%d", &a);
    s=nrdSum(a);
    t=rdSum(a);
    printf("sum of digits by non rec = %d", s);
    printf("\nsum of digits by rec = %d", t);
    return 0;
}
int nrdSum(int x)
{
    int i,rem,sum=0;
    for(i=1;x!=0;i++)
    {
        rem=x%10;
        sum=sum+rem;
        x=x/10;
    }
    return sum;
}
int rdSum(int x)
{
    if(x==0)
        return 0;
    return (x%10+rdSum(x/10));
}
