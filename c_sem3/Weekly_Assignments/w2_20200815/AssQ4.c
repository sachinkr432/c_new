// created by SACHIN
// This Shifts elements in an array by x (user input) amount towards left;
// Left Shifter in array;

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void shiftList(int arr[], int n, int d);

int main()
{
	int arr[SIZE];
	int n, i, d;

	printf("Enter no. of elements you want to enter:");
	scanf("%d",&n);

	printf("Enter elements: ");
	for (i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	printf("\nEnter 'd' for no. of unit of rotation");
	scanf("%d", &d);

	printf("Elements before sorting: \n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	shiftList(arr, n, d);

	printf("Elements after sorting: \n");
	for(i=0; i<n; i++)
		printf("%d\t", arr[i]);
	
	return 0;
}

void shiftList(int arr[], int n, int d)
{
	int i, j, temp;
	for (i = 0; i < d; ++i)
	{
		for (j = 0; j < n-1; ++j)
		{
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}
}