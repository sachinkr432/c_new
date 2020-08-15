#include <stdio.h>
#include <stdlib.h>

int** add (int row, int column, int **A, int **B);
void print(int r, int c, int** ar);
int** new_data( int r, int c, int** n);

int main()
{
	int r1=5,c1=7;
	int r2=5,c2=7;
	int **A,**B;
	int **t;

	//printf("Enter A's Rows and Cols: \n");
	//scanf("%d%d",&r1,&c1);
	A= new_data(r1, c1, A);

	//printf("Enter B's Rows and Cols: \n");
	//scanf("%d%d",&r2,&c2);
	B= new_data(r2, c2, B);


	print(r1,c1,A);
	print(r2,c2,B);

	if(r1==r2 && c1==c2)
	{
		t = add( r1, c1, A, B);
		print(r1,c1,t);
	}
	else
		printf("Error in Addition, Mismatch in Rows,Cols\n");
	return 0;
}

int** add (int row, int column, int **A, int **B)
{
	int** tr;
	tr = (int**)calloc(sizeof(int*),row);
	for (int i = 0; i < row; ++i)
	{
		tr[i] = (int*)calloc(sizeof(int),column);
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < column; ++j)
			tr[i][j] = A[i][j] + B[i][j];

	return tr;
}

void print(int r, int c, int** ar)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			printf("%d\t",ar[i][j]);
		printf("\n");
	}
	printf("\n");
}

int** new_data( int r, int c, int** n)
{
	n = (int**)calloc(sizeof(int*),r);
	for (int i = 0; i < r; ++i)
		n[i]=(int*)calloc(sizeof(int),c);
	//printf("Enter elements:\n");
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			n[i][j]=i-j;
			//scanf("%d",&n[i][j]);
	return n;
}