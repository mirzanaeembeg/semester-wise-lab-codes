#include <stdio.h>
int main()
{
    int i,t,j,start,end,num;
    scanf("%d%d", &start,&end);
    for(j=start; j<=end; j++)
    {
        for(i=2; i<j; i++)
        {
            if(j%i==0)
                t=1;
        }
        if(t!=1)
            printf("%d\t", j);
        t=0;
    }
    return 0;
}
