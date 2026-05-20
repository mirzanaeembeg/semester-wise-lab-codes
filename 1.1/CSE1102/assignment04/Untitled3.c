#include <stdio.h>
void main()
{
    int arr[]= {30,35,39,41,53,64,71};
    int i, x, pos, size=7;


    printf("Enter the element:\n");
    scanf("%d", &x);

    for(i=0; i<size; i++)
    {
        if(x>arr[i] && x<arr[i+1])
        {
            size++;
            pos = i+2;
            for(i = size-1; i >= pos; i--)
                arr[i] = arr[i-1];
            arr[pos - 1] = x;
        }
        else if(x>arr[size-1])
        {
            size++;
            arr[size-1]=x;
        }
    }
    printf("Updated array:\n");
    for(i = 0; i < size; i++)
        printf("%d\t", arr[i]);

    printf("\n");

}
