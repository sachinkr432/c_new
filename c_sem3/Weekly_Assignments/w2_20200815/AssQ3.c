//created by SACHIN

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void sortList(int arr[], int n);

int main()
{
	int arr[SIZE];
	int n, i;

	printf("Enter no. of elements you want to enter:");
	scanf("%d",&n);

	printf("Enter elements: ");
	for (i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	printf("Elements before sorting: \n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	sortList(arr, n);

	printf("Elements after sorting: \n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	
	return 0;
}

void sortList(int arr[], int n)
{
	int i, k, z=0;
	for (i = n-1; i > z; --i)
	{
		if (!arr[i])
		{
			for (k = i; k >= z; --k)
				arr[k] = arr[k-1];
			arr[0] = 0;
			i++;
			z++;
		}
	}
}