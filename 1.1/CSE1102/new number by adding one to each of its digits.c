#include <stdio.h>
int main()
{
   int x,a,b,c,d,e,f,g,h,i,j,k,l,m;
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
   i=b+1,j=d+1,k=f+1,l=h+1,m=g+1;
   printf("\nThe new number of five digits after adding 1 to each of its reverse digits=%d%d%d%d%d",i,j,k,l,m);
   return 0;
}
