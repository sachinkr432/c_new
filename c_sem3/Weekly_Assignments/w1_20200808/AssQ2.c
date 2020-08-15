//Instead of taking input from keyboard, Inputs are taken using rand() function wherever required
//In case you want to enable user input, Uncomment line 25, 26, 27, 28, 50, 61 and
//Comment down line 29, 30, 51, 52, 54, 62, 63, 65 and
//the program will take input from User;		#SACHIN


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int** mul(int row1,int col1,int col2,int **a,int **b);

int main()
{
	srand(time(0));

	float time_in_sec;
	clock_t start, end;
	start = clock();

	int row1,row2,col1,col2,i,j,**m;

	//printf(" Enter the no. of row and columns of matrix a: \n");
	//scanf("%d%d",&row1,&col1);
	//printf(" Enter the no. of row and columns of matrix b: \n");
	//scanf("%d%d",&row2,&col2);
	printf("Mat1: %dx%d\n", row1=rand()%4+1, col1=rand()%4+1);
	printf("Mat2: %dx%d\n", row2=rand()%4+1, col2=rand()%4+1);

	if(col1!=row2)
	{
		printf("Invalid set of Matrix entered");
	}
	else
	{
		int **a,**b;
		a = (int**)malloc(row1*sizeof(int*));
		for (int i = 0; i < row1; ++i)
			a[i] = (int*)malloc(col1*sizeof(int));
		b = (int**)malloc(row2*sizeof(int*));
		for (int i = 0; i < row2; ++i)
			b[i] = (int*)malloc(col2*sizeof(int));
		printf("\n Matrix A's elements\n");
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col1;j++)
			{
				//scanf("%d",&a[i][j]);
				a[i][j] = (rand()%20+1);
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		printf("\n Matrix B's elements\n");
		for(i=0;i<row2;i++)
		{
			for(j=0;j<col2;j++)
			{
				//scanf("%d",&a[i][j]);
				b[i][j] = (rand()%20+1);
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}
		m=mul(row1,col1,col2,a,b);
		free(a);
		free(b);
		printf("\n The multiplication of the give matrices is:\n");
		for(i=0;i<row1;i++)
		{
			for(j=0;j<col2;j++)
				printf("%2d ",m[i][j]);
			printf("\n");
		}
		free(m);
	}

	end = clock();
	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("\nThe execution time is %f",time_in_sec);
	return 0;
}


int** mul(int row1,int col1,int col2,int **a,int **b)
{
	int i,j,k,sum,**m;
	m=(int**)malloc(row1*sizeof(int*));
	for(i=0;i<row1;i++)
		m[i]=(int*)malloc(col2*sizeof(int));
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			sum=0;
			for(k=0;k<col1;k++)
				sum+=a[i][k]*b[k][j];
			m[i][j]=sum;
		}
	}
	return m;
}