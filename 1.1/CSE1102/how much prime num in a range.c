#include <stdio.h>
int main()
{
    int i,t,j,c=0,start,end,num;
    scanf("%d%d", &start,&end);
    for(j=start; j<=end; j++)
    {
        for(i=2; i<j; i++)
        {
            if(j%i==0)
                t=1;
        }
        if(t!=1)
            c++;
        t=0;
    }
    printf("%d",c);
    return 0;
}
