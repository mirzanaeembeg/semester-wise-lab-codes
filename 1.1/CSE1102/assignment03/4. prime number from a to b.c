#include <stdio.h>
int main()

{
    int start,end,num,count,prime;

    printf("Enter the range[a to b(a<b)]:\n");
    scanf("%d%d", &start, &end);
    printf("Prime numbers between %d and %d are\t", start, end);

    for(num = start; num <= end; num++)
    {
        prime = 1;
        for(count = 2; count < num; count++)
        {
            if(num % count == 0)
            {
                prime = 0;
                break;
            }
        }
        if(prime)
            printf("%d\t",num);
    }

    return 0;
}
