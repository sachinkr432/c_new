// created by SACHIN
// Program to deal with Cercular Queue operation of adding and removing

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int);
void dequeue(void);
void print(void);

int main()
{
	int ch, num;
	do
	{
		print();
		printf("\nFront: %d\nRear: %d\n", front, rear);
		printf("\nOptions:\n1. Add element\n2. Delete element\n0. exit\n\t\t");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 : 	printf("Enter element to add: ");
						scanf("%d", &num);
						enqueue(num);
						break;
			case 2 : 	dequeue();
						break;
			default: printf("Invalid Choice\n");
		}

	} while (ch);	
	return 0;
}

void enqueue(int num)
{
	if(front == -1)
	{
		front = 0;
		rear = 0;
		queue[front] = num;
	}
	else if((front == rear - 1) ||(front == MAX_SIZE-1 && rear == 0))
		printf("Queue Overflow!! No space left. \n");
	else if(front == MAX_SIZE-1)
	{
		front = 0;
		queue[front] = num;
	}
	else
		queue[++front] = num;
}

void dequeue(void)
{
	if (front == -1)
		printf("Queue Underflow!! No element to delete\n");
	else if (front == rear)
		front = rear = -1;
	else if(rear == MAX_SIZE-1)
		rear = 0;
	else 
		rear += 1;
}

void print(void)
{
	int i = rear;
	printf("Current Status\n");
	if(rear <= front)
		while(i != front+1)
			printf("%d\t", queue[i++]);
	else
	{
		while(i < MAX_SIZE)
			printf("%d\t", queue[i++]);
		i = 0;
		while(i <= front)
			printf("%d\t", queue[i++]);
	}
}