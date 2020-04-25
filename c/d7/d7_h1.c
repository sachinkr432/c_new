#include <stdio.h>

void findUnique(int [], int);

int main()
{
	int n;
	printf("Enter length of array: ");
	scanf("%d",&n);
	int arr[n];

	printf("Enter array elements\n");
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	findUnique(arr, n);

	return 0;
}

void findUnique(int arr[], int n)
{
	int count=1;
	for (int i = 0,j; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (arr[i]==arr[j] && i!=j)
				break;
		}
		if (j==n)
		{
			printf("Unique element [%d]: %d\n",count ,arr[i] );
			count++;
		}
	}
}