#include<stdio.h>
#include<stdlib.h>
void up_low(int r,int **a);
int main()
{
	int r,i,j,**a;
	printf("enter the order of the matrix\n");
	scanf("%d",&r);
	a=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		a[i]=(int*)malloc(sizeof(int));
	printf("enter the elements of the matrix\n");
	for(i=0;i<r;i++)
		for(j=0;j<r;j++)
			scanf("%d",&a[i][j]);
	printf("the matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
			printf("%2d",a[i][j]);
		printf("\n");
	}
	up_low(r,a);
	free(a);
	return 0;
}
void up_low(int r,int **a)
{
	int i,j,u=0,l=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i][j]!=0)
				l++;
		}
		for(j=r-1;j>i;j--)
		{
			if(a[i][j]!=0)
				u++;
		}
	}
	if(l==0 && u==0)
		printf("the matrix is diagonal\n");
	else if(l==0)
		printf("the matrix is upper triangular\n");
	else if(u==0)
		printf("the matrix is lower triangular\n");
	else
		printf("the matrix is neither upper nor lower triangular\n");
}
