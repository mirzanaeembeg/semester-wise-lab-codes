#include <stdio.h>
int main()
{
    int array[10]={10,21,37,48,54,63,71,84,95,130};
    int n;
    printf("Enter an index number between 1-10:");
    scanf("%d", &n);
    printf("%dth array is %d.",n,array[n-1]);
    return 0;
}
