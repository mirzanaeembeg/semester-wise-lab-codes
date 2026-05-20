#include <stdio.h>
int main()
{
    int i,t,num;
    scanf("%d", &num);
    for(i=2; i<num; i++)
    {
        if(num%i==0)
            t=1;
    }
    if(t==1)
        printf("%d is Not a Prime Number!", num);
    else
        printf("%d is a Prime Number!", num);
    return 0;
}
