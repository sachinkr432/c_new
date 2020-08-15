#include<stdio.h>

int main(int argc, char const *argv[])
{
	int arr[5] = {1, 3, 5, 7, 11};
	int *ptr, *ptr1;
	ptr = &arr;
	ptr1 = *ptr + 3;
	printf("%d--%d",*ptr,ptr1 );
	return 0;
}