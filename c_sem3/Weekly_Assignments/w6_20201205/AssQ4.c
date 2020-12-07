#include<stdio.h>
#include<stdlib.h>
void bubble_sort(int arr[],int n);
void selection_sort(int arr[],int n);
void insertion_sort(int arr[],int n);
void quick_sort(int arr[],int,int);
int partition(int arr[],int low,int high);
void heap_sort(int arr[],int n);
void heapify(int arr[],int n,int i);
int main()
{
	int ch,n,i;
	do
	{
	printf("\nEnter number of elements of array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		printf("Enter number at %d index:",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter your choice (-1 to exit)\n1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Quick sort\n5.Heap sort\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:bubble_sort(arr,n);
		break;
		case 2:selection_sort(arr,n);
		break;
		case 3:insertion_sort(arr,n);
		break;
		case 4:quick_sort(arr,0,n-1);
		break;
		case 5:heap_sort(arr,n);
		break;
		case -1:exit(0);
		break;
		default:
		printf("Invalid input\n");
	}
	printf("Sorted array: ");
	for (i=0;i<n;i++)
		printf("%d ",arr[i]);
	}
	while(1);
	return 0;
}
void bubble_sort(int arr[],int n)
{
	int i,j,temp,pass=1;
	for(i=n-1;i>=0 && pass;i--)
	{
		pass=0;
		for(j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				pass=1;
			}
		}
	}
//	printf("Sorted array: ");
//	for (i=0;i<n;i++)
//		printf("%d ",arr[i]);
}
void insertion_sort(int arr[],int n)
{
	int i,j,v;
	for (i=1;i<=n-1;i++)
	{
		v=arr[i];
		j=i;
		while(arr[j-1]>v && j>=1)
		{
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=v;
	}
//	for(k=0;k<n;k++)
//		printf("%d ",arr[k]);
}
void selection_sort(int arr[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
//	for (i=0;i<n;i++)
//		printf("%d ",arr[i]);
}
void quick_sort(int arr[],int low,int high)
{
	if (low<high)
	{
		int p;
		p=partition(arr,low,high);
		quick_sort(arr,low,p-1);
		quick_sort(arr,p+1,high);
	}
}
int partition(int arr[],int low,int high)
{
	int p=arr[high],i=low-1,j,temp;
	for (j=low;j<=high-1;j++)
	{
		if (arr[j]<p)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[high];
	arr[high]=arr[i+1];
	arr[i+1]=temp;
	return i+1;
}
void heap_sort(int arr[],int n)
{
	int i,temp;
	for (i=n/2-1; i>=0; i--)
		heapify(arr,n,i);
	for (i=n-1; i>0; i--)
	{
		temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		heapify(arr,i,0);
	}
}
void heapify(int arr[],int n,int i)
{
	int largest=i,temp;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l] > arr[largest])
		largest=l;
	if (r<n && arr[r] > arr[largest])
		largest=r;
	if (largest!=i)
	{
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		heapify(arr,n,largest);
	}
}
