#include <stdio.h>
float product(float a,int b);
void main()
{
    float a;
    int b;
    printf("Enter a float & an integer:\n");
    scanf("%f%d",&a,&b);
    printf("result=%f",product(b,a));

}
float product(float a,int b)
{
    return a*b;
}
