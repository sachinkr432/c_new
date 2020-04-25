#include <stdio.h>
#include <math.h>

int min(int [], int );
int max(int [], int );
float avg(int [], int );
float stdDeviation(int [], int );

int main()
{
	int len;
	printf("Enter length of array: ");
	scanf("%d",&len);
	int arr[len];
	printf("Enter elements:\n");
	for (int i = 0; i < len; ++i)
	{
		scanf("%d",&arr[i]);
	}

	printf("Minimum is: %d\n", min( arr, len));	//Minimum

	printf("Maximum is: %d\n", max( arr, len));	//Maximum

	printf("Average is: %0.2f\n", avg( arr, len));	//Average

	printf("Standard Deviation : %0.2f\n", stdDeviation( arr, len));

	return 0;
}

int min(int arr[], int sz)
{
	int temp=arr[0];
	for (int i = 1; i < sz; ++i)
	{
		if(arr[i]<temp)
			temp=arr[i];
	}
	return temp;
}

int max(int arr[], int sz)
{
	int temp=arr[0];
	for (int i = 1; i < sz; ++i)
	{
		if(arr[i]>temp)
			temp=arr[i];
	}
	return temp;
}

float avg(int arr[], int sz)
{
	int sum=0;
	for (int i = 0; i < sz; ++i)
	{
		sum += arr[i];
	}
	return sum/sz;
}

float stdDeviation(int arr[], int sz)
{
	float mean = avg( arr, sz);
	float temp=0;
	for (int i = 0; i < sz; ++i)
	{
		temp += (arr[i]-mean)*(arr[i]-mean);
	}
	temp /= sz;
	temp = sqrt(temp);
	return temp;
}