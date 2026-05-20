#include <stdio.h>
float area(float);
void main()
{
    float r,ar;
    printf("Program to Calculate Circle Area:\n");
    scanf("%f",&r);
    ar=area(r);
    printf("Area is : %f",ar);

}
float area(float x)
{
    return 3.1416*x*x;
}
