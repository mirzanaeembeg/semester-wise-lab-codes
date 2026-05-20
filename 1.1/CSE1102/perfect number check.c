#include <stdio.h>
int main()
{
    int sum=0,n;
    scanf("%d", &n);

    for(int i=1; i<n; i++)
    {
        if(n%i==0)
        {
            sum += i;
        }

    }

    if(sum==n)
        printf("%d is a perfect number",sum);
    else
        printf("%d is not a perfect number",n);
    return 0;
}
