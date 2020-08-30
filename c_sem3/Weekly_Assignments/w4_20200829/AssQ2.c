// created by SACHIN
// This program implements stack into singly link list

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
}*top = NULL;

void push(int);
int pop(void);
void print(void);

int main()
{
	int ch, num;
	do
	{
		print();
		printf("Options:\n1. Push\n2. Pop\n0. Exit\n\t\t");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : 	printf("Enter element to add: ");
						scanf("%d", &num);
						push(num);
						break;
			case 2 : 	printf("Popped: %d\n", pop());
						break;
			default: printf("Invalid Choice\n");
		}

	} while (ch);	
	return 0;
}

void print(void)
{
	struct node *temp = top;
	printf("Current Status\n");
	if (temp == NULL)
	{
		printf("Empty\n");
		return ;
	}
	while(temp != NULL)
	{
		printf("%d\t", temp->num);
		temp = temp->next;
	}
	printf("\n");
}

int pop(void)
{
	struct node *temp = top;
	int num;
	if (top == NULL)
	{
		printf("Stack Empty\n");
	}
	else
	{
		temp = top;
		num = top->num;
		top = top->next;
		free(temp);
		return num;
	}
}

void push(int num)
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = top;
	top = newNode;
}