#include<stdio.h>
#include<stdlib.h>
int** transpose(int r,int a[][r]);
int** mul(int r,int a[][r],int **tran);
void identity(int r,int **m);
int main() 
{
	int i,j,r,**tran,**m;
	printf("enter the order of the matrix\n");
	scanf("%d",&r);
	int a[r][r];
	printf("enter the elements of the matrix\n");
	for(i=0;i<r;i++)
		for(j=0;j<r;j++)
			scanf("%d",&a[i][j]);
	tran=transpose(r,a);
	m=mul(r,a,tran);
	identity(r,m);
	free(tran);
	free(m);
	return 0;
}
int** transpose(int r,int a[][r])
{
	int i,j,**tran;
	tran=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		tran[i]=(int*)malloc(sizeof(int));
	for(i=0;i<r;i++)
		for(j=0;j<r;j++)
			tran[j][i]=a[i][j];
	return tran;
}
int** mul(int r,int a[][r],int **tran)
{
	int sum,i,j,k,**m;
	m=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		m[i]=(int*)malloc(sizeof(int));
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			sum=0;
			for(k=0;k<r;k++)
				sum+=a[i][k]*tran[k][j];
			m[i][j]=sum;
		}
	}
	return m;
}
void identity(int r,int **m)
{
	int i,j,x=1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			if(i==j && m[i][i] !=1)
				x=0;
			else if(i!=j && m[i][j] !=0)
				x=0;
		}
	}
	//	printf("x=%d  \n",x);
		if(x==0)
			printf("It is not an orthogonal matrix");
		else
			printf("It is an orthogonal matrix");
}
