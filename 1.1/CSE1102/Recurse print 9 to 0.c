#include <stdio.h>
void recurse(int i);
void main()
{
    recurse(0);
}
void recurse(int i)
{
    if(i<10)
    {
        recurse(i+1);
        printf("%d ",i);
    }

}
