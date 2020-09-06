// created by SACHIN
// This program implements NQUEEN problem

#include <stdio.h>
#include <stdlib.h>

#define SZ 20

int block[SZ], count = 0;

void queen(int, int);
int checkValidity(int, int);
void print(int);

int main()
{
	int n; 
	printf("This is N-QUEEN problem program\n");
	printf("Enter no. of queen: ");
	scanf("%d", &n);
	queen(0, n);
	printf("\nTerminating!!\n");
	return 0;
}

void queen(int row, int n)
{
	int col = 0;
	while(col < n)
	{
		if(checkValidity(row, col))
		{
			block[row] = col;
			if (row == n-1)
				print(n);
			else
				queen(row+1, n);
		}
		col++;
	}
}

int checkValidity( int row, int col)
{
	int i=0;
	while(i < row-1)
	{
		if(col == block[i])
			return 0;
		if(abs(block[i] - col) == abs(i - row))
			return 0;
		i++;
	}
	return 1;
}

void print(int n)
{
	int i, j;
	printf("\nSolution no.: %d\n", ++count);

	for(i = 0; i < n; ++i)
		printf("\t%d", i+1);

	for (i = 0; i < n; ++i)
	{
		printf("\n\n%d", i+1);
		for (j = 0; j < n; ++j)
		{
			if(block[i] == j)
				printf("\tQ");
			else
				printf("\t--");
		}
	}
}