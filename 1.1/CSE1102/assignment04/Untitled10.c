#include<stdio.h>
int gcd(int a,int b)
{
    if(b%a==0)return a;
    return gcd(b%a,a);
}

int main()
{
    int n;
    scanf("%d",&n);
    int t;
    scanf("%d",&t);
    int ans=t;
    for(int i=2; i<=n; i++)
    {
        int c;
        scanf("%d",&c);
        int k=t;
        t=gcd(t,c);
        ans = (c * ans)/t;

    }
    printf("%d %d",t,ans);


    return 0;
}
