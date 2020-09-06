// created by SACHIN
// This program implements BINARY SEARCH on a sorted array

#include <stdio.h>
#include <time.h>

#define SZ 1000

int binSearch(int*, int, int);

int main()
{
	float time_in_sec;
	time_t start, end;

	int i = 0, n, arr[SZ], key;

	FILE *fp1;
	if ((fp1=fopen("sorted.txt","r"))==NULL)
	{
	printf("file failed to open\n");
	return 1;
	}
	else
		while((fscanf(fp1,"%d",&arr[i]))!=EOF)
			i++;
	n = i;
	fclose(fp1);

	printf("Enter key to search: ");
	scanf("%d", &key);

	start = clock();
	if(binSearch(arr, n, key))
		printf("Key found in array\n");
	else
		printf("Key not found\n");
	end = clock();

	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("\nTime complexity: %0.2f\n", time_in_sec);
	return 0;
}

int binSearch(int *A, int n, int key)
{
	int low = 0, high = n-1, mid;
	while(1)
	{
		mid = (low + high) / 2;
		if(low > mid || mid > high)
			break;
		else if(key < A[mid])
			high = mid - 1;
		else if(key > A[mid])
			low = mid + 1;
		else if(key == A[mid])
			return 1;
	}
	return 0;
}