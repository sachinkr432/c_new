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
	static int x = 0;
	node *ptr;
	printf("\nEnter Position from last: ");
	scanf("%d", &x);
	ptr = _findPosLast(head);
}

node *_findPosLast(node **head)
{
	if (*head == NULL)
	{
		x--;
		return NULL;
	}
	_findPosLast(&(*head->next));
	x--;
	if(x == 0)
		return *head;
	else
		return;
}