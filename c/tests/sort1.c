#include <stdio.h>
#define N 6

int main()
{
	int a[]={8,3,5,2,6,5};
	int tmp;

	printf("\n\t");
	for (int i = 0; i < N; ++i)
	{
		printf("%d\t", a[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (a[j]<a[i])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
			else
				printf("\t**");
		printf("\n%d,%d\t",i,j);
		for (int k = 0; k < N; ++k)
		{
			printf("%d\t",a[k] );
		}
		}
	}

	printf("\n\t");
	for (int i = 0; i < N; ++i)
	{
		printf("%d\t", a[i]);
	}
	return 0;
}