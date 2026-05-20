#include <stdio.h>
void main()
{
    int size;
    int i,j,max,min;
    printf("Enter array size:\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter array element:\n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    max=min=arr[0];
    for(i=0; i<size; i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
    }
    float median = 0;
    float mid=0;
    if(size%2 == 0)
    {
        int temp=(size/2)-1;
        for(int i=0; i<size; i++)
        {
            if(temp==i || (temp+1)==i)
            {
                mid=mid+arr[i];
            }
        }
        mid=mid/2;
        printf("Median = %.1f\n",mid);
    }
    else
    {
        int temp=(size/2);
        for(int i=0; i<size; i++)
        {
            if(temp==i)
            {
                int mid=arr[i];
                printf("Median = %d\n",mid);
            }
        }
    }
    printf("Max = %d & Min = %d", max,min);
}
