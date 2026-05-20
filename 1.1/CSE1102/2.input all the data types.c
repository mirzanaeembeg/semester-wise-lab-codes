#include <stdio.h>
int main()
{
    char ch;
    int x;
    float y;
    printf("Enter a character:");
    scanf("%c", &ch);
    printf("\nEnter an integer:");
    scanf("%d",&x);
    printf("\nEnter a float number:");
    scanf("%f",&y);
    printf("\nCharacter is %c",ch);
    printf("\nInteger is %d",x);
    printf("\nFloating number is %f",y);
    return 0;
}
