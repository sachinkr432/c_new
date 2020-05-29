#include<stdio.h>
#include<stdlib.h>

int** transpose (int row, int column, int A[] [column] );

int main()
{
	int r=4,c=7;
	int** t;
	//printf("Enter Rows and Cols: \n");
	//scanf("%d%d",&r,&c);
	int mat[r][c];
	//printf("Enter elements:\n");
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			mat[i][j]=i-j;
			//scanf("%d",&mat[i][j]);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}

	t = transpose( r, c, mat);

	printf("\n");

	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < r; ++j)
			printf("%d\t",t[i][j]);
		printf("\n");
	}
	return 0;
}

int** transpose (int row, int column, int A[] [column] )
{
	int** tr;
	tr = (int**)calloc(sizeof(int*),column);
	for (int i = 0; i < column; ++i)
	{
		tr[i] = (int*)calloc(sizeof(int),row);
	}
	for (int i = 0; i < column; ++i)
		for (int j = 0; j < row; ++j)
			tr[i][j] = A[j][i];

	return tr;
}