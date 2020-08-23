// created by SACHIN
// Program to deal with Stack operation of adding and removing

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int);
void pop(void);
void print(void);

int main()
{
	int ch, num;
	do
	{
		print();
		printf("\nOptions:\n1. Add element\n2. Delete element\n0. exit\n\t\t");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : 	printf("Enter element to add: ");
						scanf("%d", &num);
						push(num);
						break;
			case 2 : 	pop();
						break;
			default: printf("Invalid Choice\n");
		}

	} while (ch);	
	return 0;
}

void push(int num)
{
	if(top == MAX_SIZE - 1)
		printf("Stack Overflow!! No space left.\n");
	else
		stack[++top] = num;
}

void pop(void)
{
	if (top == -1)
		printf("Stack Underflow!! No element to delete\n");
	else
	{
		printf("Top element deleted");
		top--;
	}
}

void print(void)
{
	int i = 0;
	printf("Current Status\n");
	if (top == -1)
	{
		printf("Empty\n");
		return ;
	}
	while(i != top+1)
	{
		printf("%d\t", stack[i]);
		i += 1;
	}
}