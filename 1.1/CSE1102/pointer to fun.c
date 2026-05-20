#include<stdio.h>
void disp( int * );
void show(int *);
int main()
{
    int i;
    int marks[]={55,65,75,56,78};
    for(i=0;i<=4;i++)
        disp(&marks[i]);
    return 0;
}
void disp(int *n)
{
    show(&n);
}
void show(int *x)
{
    printf("%d\t",x);
}
