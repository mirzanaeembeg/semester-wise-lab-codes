#include <stdio.h>
int main()
{
    int size1,size2,size3;
    printf("Enter the size of first array: ");
    scanf("%d",&size1);
    int a[size1];
    printf("Enter the array elements:\n");
    for(int i = 0; i < size1; i++)
        scanf("%d", &a[i]);
    printf("Enter the size of second array: ");
    scanf("%d",&size2);
    int b[size2];
    printf("Enter the array elements:\n");
    for(int i = 0; i < size2; i++)
        scanf("%d", &b[i]);
    size3 = size1 + size2;
    int c[size3];
    for(int i = 0; i < size1; i++)
        c[i] = a[i];
    for(int i = 0; i < size2; i++)
        c[i + size1] = b[i];

    printf("The merged array: ");
    for(int i = 0; i < size3; i++)
        printf("%d ", c[i]);
    int i,j,k;
    for(i=0; i<size3; i++)
    {
        for(j=i+1; j<size3; j++)
        {
            if(c[i] == c[j])
            {
                for(k=j; k < size3 - 1; k++)
                {
                    c[k] = c[k + 1];
                }
                size3--;
                j--;
            }
        }
    }
    printf("\nArray after deleting duplicates : ");
    for(i=0; i<size3; i++)
    {
        printf("%d\t", c[i]);
    }
    return 0;
}
