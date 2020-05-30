#include<stdio.h>
#include <stdlib.h>

int maxNo(int arr[],int n);
int minNo(int arr[],int n);
int main()
{
	int n,i,j=0;
	printf("enter the no. of terms to be entered\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the set of nos.\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("The maximum no. is %d\nThe minimum no. is %d\n",maxNo(arr,n),minNo(n,j,arr));
	return 0;
}
int minNo(int arr[], int n)
{
	if (n==1)
		return arr[0];
	return min(arr[n-1],minNo(arr,n-1));
}
int maxNo(int arr[],int n)
{
	if (n==1)
		return arr[0];
	return max(arr[n-1],maxNo(arr,n-1));
}
