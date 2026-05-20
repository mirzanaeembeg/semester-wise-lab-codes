#include <stdio.h>
void main()
{
    int size;
    int i,ind,num;
    printf("Enter array size:\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter array element:\n");
    for(i=0;i<size;i++)
    {
       scanf("%d", &arr[i]);
    }
    printf("Enter an element to delete:\n");
    scanf("%d", &num);
    for(i=0;i<size;i++)
    {
        if(num==arr[i])
        {
            ind=i;
        }
    }
    size--;
    for(i=ind;i<size;i++)
    {
        arr[i]=arr[i+1];
    }

    printf("New array:\n");
    for(i=0;i<size;i++)
    {
       printf("%d\t", arr[i]);
    }
}
