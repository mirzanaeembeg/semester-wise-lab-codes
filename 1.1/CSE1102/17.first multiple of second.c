#include<stdio.h>
int main()
{
int x,y;

printf("enter the first integer:");
scanf("%d",&x);
printf("enter the second integer:");
scanf("%d",&y);
if(x%y == 0)
printf(" %d is a multiple of %d\n",x,y);
else
printf("%d is not a multiple of %d\n",x,y);
return 0;
}
