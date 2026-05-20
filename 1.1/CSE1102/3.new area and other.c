#include <stdio.h>
int main()
{
    float rad,area1,circum,length,height,area,perimeter;
    printf("Enter the lenght of the rectangle in meter :");
    scanf("%f",&length);
    printf("Enter the hieght of the rectangle in meter:");
    scanf("%f",&height);
    area=length*height;
    perimeter=2*(length+height);
    printf("Enter the radius of the circle in meter:");
    scanf("%f",&rad);
    area1=3.14*rad*rad;
    circum=2*3.14*rad;
    printf("\n\nThe area of the rectangle = %.2f square meter.",area);
    printf("\nThe perimeter of the rectangle = %.2f meter.",perimeter);
    printf("\nThe area of the circle = %.2f square meter.",area1);
    printf("\nThe circumference of the circle = %.2f meter.",circum);

    return 0;


}
