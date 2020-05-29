#include<stdio.h>
#include<stdlib.h>
int* sort(int *a,int n);
int main()
{
	int i,j,*a,n,*b;
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	b=sort(a,n);
	for(i=0;i<n;i++)
		printf("%d\t",b[i]);
	free(a);
	return 0;
}
int* sort(int *a,int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	return a;
}
