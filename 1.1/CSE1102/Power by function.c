#include <stdio.h>
int power(int x,int y);
void main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",power(x,y));
}

int power(int x,int y)
{
    int power=1;
    for(int i=1; i<=y; i++)
    {
        power=power*x;
    }

    return power;
}

