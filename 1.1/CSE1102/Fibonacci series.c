#include <stdio.h>
void main()
{
    int n,x,y,z;
     x=0,y=1;

    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
         printf("%d ",x);
         z=x+y;
         x=y;
         y=z;

    }
    return 0;

}
