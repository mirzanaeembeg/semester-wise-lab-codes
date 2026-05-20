#include <stdio.h>
void main()
{
    int a[5];
    int i,t,x;
    printf("Enter the array element:\n");
    for(i=0; i<5; i++)
        scanf("%d", &a[i]);
    printf("Enter a number to search:");
    scanf("%d", &x);
    for(i=0; i<5; i++)
    {
        if(a[i]==x)
            t=0;
        else
            t=1;
    }
    if(t==1)
        printf("%d is not available in the array",x);
    else if(t==0)
        printf("%d is available in the array",x);
}
