#include <stdio.h>
int main()

{
    int i, j, start, end, sum;

    printf("Enter the range (a<b) :\n");
    scanf("%d%d", &start, &end);
    printf("All perfect numbers from %d to %d:\n", start, end);

    for(i=start; i<=end; i++)
    {
        sum = 0;
        for(j=1; j<i; j++)
        {
            if(i % j == 0)
            {
                sum += j;
            }
        }
        if(sum == i)
        {
            printf("%d  ", i);
        }
    }

    return 0;
}
