#include<stdio.h>

void add(int a, int b, int x, int y);
void subtract(int a, int b, int x, int y);
void multiply(int a, int b, int x, int y);

int main()
{
	int a, b, x, y;
	printf("Enter 2 numbers in form (a,bi): ");
	scanf("%d,%di",&a,&b);
	scanf("%d,%di",&x,&y);
	printf("Pair is: (%d,%di),(%d,%di)",a,b,x,y);
	printf("\n");
	printf("Addition: ");
	add(a,b,x,y);
	printf("Subtraction: ");
	subtract(a,b,x,y);
	printf("Multiplication: ");
	multiply(a,b,x,y);
	return 0;
}

void add(int a, int b, int x, int y)
{
	int r,i;
	r = a+x;
	i = b+y;
	printf("(%d,%di)\n", r, i);
}

void subtract(int a, int b, int x, int y)
{
	int r,i;
	r = a-x;
	i = b-y;
	printf("(%d,%di)\n", r, i);
}

void multiply(int a, int b, int x, int y)
{
	int r,i;
	r = a*x-b*y;
	i = a*y+b*x;
	printf("(%d,%di)\n", r, i);
}