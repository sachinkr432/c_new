// created by SACHIN
// Reverses a given Doubly Link List provided with pointer to head of the list;

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *prev;
	int num;
	struct Node *next;
}node;

void print(node **);
void displayAll(node **head);
void createNode( node **);
void reverse(node **);

int main()
{
	node **head;
	node *h = NULL;
	head = &h;
	createNode(head);
	displayAll(head);
	printf("\nAfter reversing\n");
	reverse(head);
	displayAll(head);
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
			newNode->prev = NULL;
		}
		else
		{
			ptr->next = newNode;
			newNode->prev = ptr;
			ptr = ptr->next;
		}
		
		scanf("%d", &val);
	} 
	printf("Double Link List created!!\n");
}

void reverse(node **head)
{
	node *preptr = NULL, *ptr = *head;
	while(ptr != NULL)
	{
		preptr = ptr->prev;
		ptr->prev = ptr->next;
		ptr->next = preptr;
		ptr = ptr->prev;
	}
	if(preptr != NULL)
		*head = preptr->prev;
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