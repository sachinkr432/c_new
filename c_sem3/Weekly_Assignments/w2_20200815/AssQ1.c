// created by SACHIN
// This creates a triple form of a given Sparse matrix if condition is met. Triples are allocated dynamically;

#include <stdio.h> 
#include <stdlib.h>
#define MAX 20 
 
int read_matrix(int a[10][10], int row, int column); 
void print_sparse(int **b); 
void create_sparse(int a[10][10], int row, int column, int **b); 
 
int main() 
{
	int a[10][10], **b, row, column, count;
	printf("\nEnter the size of matrix (rows, columns): ");
	scanf("%d%d", &row, &column); 
 
	

    count = read_matrix(a, row, column);
    if (count*3 > row * column)
    {
    	printf("\nIncompatible matrix! Can't convert to Sparse!!\n");
    	return -1;
    }

    b = (int**)malloc((count+1) * sizeof(int*));
	for (int i = 0; i <= count ; ++i)
	{
		b[i] = (int*)malloc(3 * sizeof(int));
	}

    create_sparse(a, row, column, b);
    print_sparse(b);
    return 0;
} 
 
int read_matrix(int a[10][10], int row, int column)
{
	int i, j, counter = 0;
	printf("\nEnter elements of matrix\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
			if(a[i][j])
				counter++;
		}
	}
	return counter;
} 
 
void create_sparse(int a[10][10], int row, int column, int **b)
{
	int i, j, k;
	k = 1;
	b[0][0] = row;
	b[0][1] = column;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (a[i][j] != 0)
			{
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2] = k - 1;
    }
} 
 
void print_sparse(int **b)
{
	int i, column;
	column = b[0][2];
	printf("\nSparse form - list of 3 triples\n\n");
	for (i = 0; i <= column; i++)
	{
		printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
	}
}