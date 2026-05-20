#include <stdio.h>
int main()
{
    float rad,area,circum;
    printf("Enter the radius:");
    scanf("%f",&rad);
    area=3.14*rad*rad;
    circum=2*3.14*rad;
    printf("\nThe area of the circle= %.2f",area);
    printf("\nThe circumference of the circle= %.2f",circum);
    return 0;

}
