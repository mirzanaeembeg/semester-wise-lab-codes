#include <stdio.h>
int main()
{
    float length,breadth,area,perimeter;
    printf("Enter the lenght:");
    scanf("%f",&length);
    printf("Enter the breadth:");
    scanf("%f",&breadth);
    area=length*breadth;
    perimeter=2*(length+breadth);
    printf("\nThe area of the rectangle= %.2f",area);
    printf("\nThe perimeter of the rectangle= %.2f",perimeter);
    return 0;

}
