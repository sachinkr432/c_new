// created by SACHIN
// This program implements queue into singly link list

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
}*front = NULL,*rear = NULL;

void enqueue(int);
int dequeue(void);
void print(void);

int main()
{
	int ch, num;
	do
	{
		print();
		printf("Options:\n1. Enqueue\n2. Dequeue\n0. Exit\n\t\t");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : 	printf("Enter element to add: ");
						scanf("%d", &num);
						enqueue(num);
						break;
			case 2 : 	printf("Dequeued: %d\n", dequeue());
						break;
			case 0 : break;
			default: printf("Invalid Choice\n");
		}

	} while (ch);	
	return 0;
}

void enqueue(int num)
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;

	if(front == NULL)
	{
		front = newNode;
		rear = newNode;
		rear->next = front;
	}
	else
	{
		rear->next = newNode;
		rear = rear->next;
		rear->next = front;
	}
}

int dequeue(void)
{
	int num;
	if (rear == NULL)
	{
		printf("Empty Queue!! Underflow caught\n");
		return 0;
	}
	if(front == rear)
	{
		num = front->num;
		front = NULL;
		free(rear);
		rear = NULL;
	}
	else
	{
		num = front->num;
		front = front->next;
		free(rear->next);
		rear->next = front;
	}
	return num;
}

void print(void)
{
	struct node *temp = front;
	printf("Current Status: \n");
	if (front == NULL)
	{
		printf("Empty \n");
		return ;
	}
	do
	{
		printf("%d\t", temp->num);
		temp = temp->next;
	}while(temp != rear->next);
	printf("\n");
}