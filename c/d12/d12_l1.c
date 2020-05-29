#include<stdio.h>
#include<stdlib.h>
int* findMaxMin(int arr[],int);
int main()
{
	int n,i,*p;
	printf("Enter the size of Array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the set of nos.\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	p=findMaxMin(arr,n);
	printf("The max and min nos. are %d %d respectively\n",p[0],p[1]);
	return 0;
}
int* findMaxMin(int arr[],int n)
{
	int i;int *a;
	a=(int*)malloc(2*sizeof(int));
	a[0]=arr[0];a[1]=arr[0];
	for(i=0;i<n;i++)
	{
		if(a[0]<arr[i])
			a[0]=arr[i];
		else if(a[1]>arr[i])
			a[1]=arr[i];
	}
	return a;
}

