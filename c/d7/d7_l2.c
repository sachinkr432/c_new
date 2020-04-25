#include <stdio.h>

void add(int [], int, int , int);
void rem(int [],int ,int );

int main()
{
	int len;
	printf("Enter Array length: ");
	scanf("%d",&len);
	int arr[len];

	int index, data, ch;
	do
	{
		printf("\n1. Add,\n2.Remove,\n3.Exit\n");
		scanf("%d",&ch);
		if (ch==3)
			break;
		else if (ch == 1)
		{
			printf("Enter Position and Data respectively: \n");
			scanf("%d%d",&index,&data);
			add( arr, len, index, data);
			len++;
		}
		else if (ch == 2)
		{
			printf("Enter Position to delete: ");
			scanf("%d",&index);
			rem( arr, len, index);
			len--;
		}
		for (int i = 0; i < len; ++i)
		{
			printf("%d ",arr[i]);
		}
	} while (1);

	return 0;
}

void add( int arr[], int sz, int pos, int val)
{
	int i;
	for (i=sz; pos < i; --i)
	{
		arr[i]=arr[i-1];
	}
	arr[pos]=val;
}

void rem( int arr[], int sz, int pos)
{
	for (int i = pos; i < sz-1; ++i)
	{
		arr[i]=arr[i+1];
	}
	arr[sz-1]=0;
}