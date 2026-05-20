#include <stdio.h>
int main()
{
   int x,a,b,c,d,e,f,g,h;
   printf("enter a 5 digit number:");
   scanf("%d",&x);
   a=x/10;
   b=x%10;
   c=a/10;
   d=a%10;
   e=c/10;
   f=c%10;
   g=e/10;
   h=e%10;

   printf("\nThe reverse of five digits=%d%d%d%d%d",b,d,f,h,g);
   return 0;
}
