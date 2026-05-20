#include <stdio.h>
int count_dn(int count);
void main()
{
    int n;
    printf("How many times ?");
    scanf("%d",&n);
    count_dn(n);
}
int count_dn(int count)
{
    count--;
    printf("the value of count = %d\n",count);
    if(count>0)
        count_dn(count);
    printf("now count = %d\n",count);
}

