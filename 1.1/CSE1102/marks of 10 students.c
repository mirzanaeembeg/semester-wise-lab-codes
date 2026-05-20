#include <stdio.h>
void main()
{
    int marks[10];
    printf("Enter marks:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d", &marks[i]);
    }
    printf("Marks of 10 students:\n");
    for(int i=0;i<10;i++)
    {
        printf("%d  ",marks[i]);
    }
}
