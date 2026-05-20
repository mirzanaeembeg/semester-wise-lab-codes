#include <stdio.h>
int power(int x,int y);
int fact(int x);
void main()
{
    int x,n;
    float sum=0;
    printf("Enter values for x and n:");
    scanf("%d%d",&x,&n);
    for(int i=0;i<=n;i++)
    {
        sum=sum+(float)power(x,2*i)/fact(i);
    }
    printf("result=%f",sum);

}
int power(int x,int y)
{
    int power=1;
    for(int i=1; i<=y; i++)
    {
        power=power*x;
    }

    return power;
}
int fact(int x)
{
    int fact=1;
    for(int i=1; i<=x; i++)
    {
        fact=fact*i;
    }

    return fact;
}
