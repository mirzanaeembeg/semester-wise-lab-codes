#include <stdio.h>

int main()
{
    int x,y,pow=1;
    printf("\nEnter base & power:\n");
    scanf("%d%d",&x,&y);
    for(int i=1; i<=y; i++)
    {
        pow=pow*x;

    }
    printf("%d",pow);
    return 0;
}
