// created by SACHIN
// This program implements BUBBLE SORT in best case time complexity O(n)

#include <stdio.h>
#include <time.h>

#define SZ 10000000

void bubbleSort(int*, int);
void print(int[], int);

int main()
{
	float time_in_sec;
	time_t start, end;

	int i = 0, n, arr[SZ];

	FILE *fp1;
	if ((fp1=fopen("unsorted.txt","r"))==NULL)
	{
	printf("file failed to open\n");
	return 1;
	}
	else
		while((fscanf(fp1,"%d",&arr[i]))!=EOF)
			i++;
	n = i;
	fclose(fp1);

	printf("\nBefore sorting\n");
	print(arr, n);
	start = clock();
	bubbleSort(arr, n);
	end = clock();
	printf("\nAfter sorting\n");
	print(arr, n);

	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("\nTime complexity: %f\n", time_in_sec);
	return 0;
}

void bubbleSort(int *arr, int n)
{
	int i = n-1, j, flag = 1, temp;
	while(i>=0 && flag)
	{
		flag = 0;
		j = 0;
		while(j < i)
		{
			if (arr[j] > arr[j+1])
			{
				temp =  arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
			j++;
		}
		i--;
	}
}

void print(int A[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("\t%d", A[i]);
}