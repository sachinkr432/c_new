#include <stdio.h>

int insert(int A[], int n , int pos, int x);
int del_Index(int A[], int n, int pos);
int del(int A[], int n, int value);

int main()
{
	int len;
	printf("Enter Array length: ");
	scanf("%d",&len);
	int arr[len];
	printf("Enter elements: ");
	for (int i = 0; i < len; ++i)
	{
		scanf("%d",&arr[i]);
	}

	int index, data, ch;
	do
	{
		for (int i = 0; i < len; ++i)
		{
			printf("%d ",arr[i]);
		}

		printf("\n1. Add,\n2. Remove by Index,\n3. Remove by value,\n4. Exit\n");
		scanf("%d",&ch);
		if (ch==4)
			break;
		else if (ch == 1)
		{
			printf("Enter Position and Data respectively: \n");
			scanf("%d%d",&index,&data);
			if(insert( arr, len, index, data))
				len++;
			else
				printf("Error in adding.\n");
		}
		else if (ch == 2)
		{
			printf("Enter Position to delete: ");
			scanf("%d",&index);
			if(del_Index( arr, len, index))
				len--;
			else
				printf("Error in evaluating Index no. \n");
		}
		else if (ch == 3)
		{
			printf("Enter value to remove\n");
			scanf("%d",&data);
			len = del( arr, len, data);
		}

	} while (1);

	return 0;
}

int insert( int arr[], int sz, int pos, int val)
{
	if (pos>sz+1)
	{
		return 0;
	}
	int i;
	pos--;
	for (i=sz; pos < i; --i)
	{
		arr[i]=arr[i-1];
	}
	arr[pos]=val;
	return 1;
}

int del_Index(int arr[], int n, int pos)
{
	if(pos>=n)
		return 0;
	for (int i = pos-1; i < n-1; ++i)
	{
		arr[i]=arr[i+1];
	}
	arr[n-1]=0;
	printf("\nDeletion successful\n");
	return 1;
}

int del(int A[], int n, int value)
{
	for (int i = 0; i < n; ++i)
	{
		if(A[i]==value)
		{
			for (int j = i+1; j < n; ++j)
				A[j-1]=A[j];
			A[n]=0;
			n--;
			i--;
		}
	}
	return n;
}