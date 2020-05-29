#include<stdio.h>
#include<stdlib.h>
int** mul(int r1,int c1,int c2,int **a,int **b);
int main()
{
	int r1,r2,c1,c2,i,j,**m;
	printf(" Enter the no. of row and columns of matrix a: \n");
	scanf("%d%d",&r1,&c1);
	printf(" Enter the no. of row and columns of matrix b: \n");
	scanf("%d%d",&r2,&c2);
	if(c1!=r2)
		printf("Invalid set of Matrix entered");
	else
	{
		int **a,**b;
		a = (int**)malloc(r1*sizeof(int*));
		for (int i = 0; i < r1; ++i)
			a[i] = (int*)malloc(c1*sizeof(int));
		b = (int**)malloc(r2*sizeof(int*));
		for (int i = 0; i < r2; ++i)
			b[i] = (int*)malloc(c2*sizeof(int));
		printf(" Enter matrix A's elements\n");
		for(i=0;i<r1;i++)
			for(j=0;j<c1;j++)
				scanf("%d",&a[i][j]);
		printf(" Enter matrix B's elements\n");
		for(i=0;i<r2;i++)
			for(j=0;j<c2;j++)
				scanf("%d",&b[i][j]);
		m=mul(r1,c1,c2,a,b);
		free(a);
		free(b);
		printf(" The multiplication of the give matrices is:\n");
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c2;j++)
				printf("%2d ",m[i][j]);
			printf("\n");
		}
		free(m);
	}
	return 0;
}
int** mul(int r1,int c1,int c2,int **a,int **b)
{
	int i,j,k,sum,**m;
	m=(int**)malloc(r1*sizeof(int*));
	for(i=0;i<r1;i++)
		m[i]=(int*)malloc(c2*sizeof(int));
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			sum=0;
			for(k=0;k<c1;k++)
				sum+=a[i][k]*b[k][j];
			m[i][j]=sum;
		}
	}
	return m;
}
