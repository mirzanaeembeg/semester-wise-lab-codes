#include <stdio.h>
int main()
{
	int arr[20];
	int i, x, pos, size;
	printf("Enter the array size <20:\n");
	scanf("%d", &size);
	printf("Enter the array:\n");
	for(i = 0; i < size; i++)
		scanf("%d", &arr[i]);
    printf("Enter the element and position:\n");
    scanf("%d%d", &x, &pos);
	size++;
	for(i = size-1; i >= pos; i--)
		arr[i] = arr[i-1];
    arr[pos - 1] = x;
    printf("Updated array:\n");
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}
