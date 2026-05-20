#include <stdio.h>
void main()
{
    int a,b;
    scanf("%d%d", &a,&b);
    if(b>0)
    {
        while(b!=0)
        {
            a++;
            b--;
        }
    }
    else if(b<0)
    {

        while(b!=0)
        {
            a--;
            b++;
        }
    }
    printf("%d",a);
    return 0;
}
