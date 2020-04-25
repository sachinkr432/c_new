#include<stdio.h>

#define SIZE 20
int count=3;

void findDifference(int arr[],int sz);

int main()
{
	int i;
	int arr[]={1,2,4,7,11,16,22,29};
	int size=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<size;++i)
		printf("%d ",arr[i]);
	printf("\n");
	findDifference(arr,size);
	return 0;
}

void findDifference(int arr[],int sz)
{
	count--;
	int D[sz-1],i;
	for(i=0;i<sz-1;++i)
	{
		D[i]=arr[i+1]-arr[i];
		printf("%d ",D[i]);
	}
	printf("\n");
	if(count==0)
		return;
	else
		return findDifference(D,sz-1);
}