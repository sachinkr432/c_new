#include<stdio.h>
int large(int arr[],int n);
int main()
{
	int n,i;
	printf("enter the no. of elements\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	large(arr,n);
	return 0;
}
int large(int arr[],int n)
{
	int j,max,max2;
	if(arr[0]>arr[1])
	{
		max = arr[0];
		max2 = arr[1];
	}
	else
	{
		max = arr[1];
		max2 = arr[0];
	}
	for(j=2;j<n;j++)
	{
		if(arr[j]>max)
		{
			max2=max;
			max=arr[j];
		}
		else if(arr[j]>max2 && arr[j]!=max)
			max2=arr[j];
	}
	printf("largest no. is %d\n2nd largest is %d",max,max2);
}
