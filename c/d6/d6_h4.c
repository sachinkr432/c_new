#include<stdio.h>

int SIZE=3;

int isSymmetric(int array[][SIZE],int size);

int main()
{
	int i,j;
	int arr[SIZE][SIZE];
	printf("%s\n", "Enter elements row wise:" ); 
	for (i = 0; i < SIZE; ++i)
	{
		for (j = 0; j < SIZE; ++j)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	if(isSymmetric(arr,SIZE))
		printf("Matrix is symmetric\n");
	else
		printf("Marrix is not symmetric\n");
	return 0;
}

int isSymmetric(int arr[][SIZE],int sz)
{
	int i,j;
	for (i = 0; i < sz-1; ++i)
	{
		for(j=i+1;j<sz;j++)
			if(arr[i][j] != -arr[j][i])
				return 0;
	}
	return 1;
}