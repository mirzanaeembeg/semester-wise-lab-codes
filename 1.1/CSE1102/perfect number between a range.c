#include <stdio.h>
int main()
{
    int i,j,start,end,sum;
    printf("Enter lower range:");
    scanf("%d", &start);
    printf("Enter upper range:");
    scanf("%d",&end);

    printf("All the perfect number from %d to %d are:\n",start,end);
    for(j=start; j<=end; j++)
    {
        sum=0;
        for(i=1; i<j; i++)
        {
            if(j%i==0)
            {
                sum += i;
            }
        }
        if(sum==j)
            printf("%d\t",sum);
    }

    return 0;
}
