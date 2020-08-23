// created by SACHIN
// Program to find rth position element from last in a n-length Single Link List
// It follows recursion of function!!!

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int num;
	struct Node *next;
}node;

void displayAll( node **);
void createNode( node **);
void findPosLast(node **);
int _findPosLast(node **, int);

int main()
{
	node **head;
	node *h = NULL;
	head = &h;
	createNode(head);
	displayAll(head);
	findPosLast(head);
	
	return 0;
}

void createNode( node **head)
{
	node *ptr, *newNode;

	int val;

	ptr = *head;



	printf("Enter value to add ( 0 to end adding): \n");
	scanf("%d", &val);
	while (val)
	{
		newNode = (node *)malloc(sizeof(node));
		newNode->num = val;
		newNode->next = NULL;
		
		if(*head == NULL)
		{
			*head = ptr = newNode;
		}
		else
		{
			ptr->next = newNode;
			ptr = ptr->next;
		}
		
		scanf("%d", &val);
	} 
	printf("Link List created!!\n");
}

void displayAll(node **head)
{
	node *ptr;
	ptr = *head;
	printf("Current Status:\n");
	if (ptr == NULL)
	{
		printf("Empty");
		return;
	}
	while(ptr != NULL)
	{
		printf("%d\t", ptr->num);
		ptr = ptr->next;
	}
}

void findPosLast(node **head)
{
	int c, res;
	node *ptr;
	printf("\nEnter Position from last: ");
	scanf("%d", &c);
	res = _findPosLast(head, c);
	if(res > 0)
		printf("Index error!!");
	return;
}

int _findPosLast(node **head, int x)
{
	node *ptr = *head;
	if (*head == NULL)
		return x;
	x = _findPosLast(&((*head)->next), x);
	x--;
	if(x == 0)
	{
		printf("Element is: %d", ptr->num);
		return x;
	}
	else
		return x;
}