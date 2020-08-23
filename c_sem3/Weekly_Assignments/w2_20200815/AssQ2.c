// created by SACHIN
// Perform all basic operations in a linklist like adding, deleting, finding length, viewing elements in a linklist;

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};

void displayAllNormal(struct node *head);
struct node *createNode( struct node *head);
struct node *addNodeEnd( struct node *head);
struct node *addNodeStart( struct node *head);
struct node *addNodePlace( struct node *head);
struct node *delNodeEnd(struct node *head);
struct node *delNodeStart(struct node *head);
struct node *delNodePlace(struct node *head);
int nodeLength(struct node *head);
void displayAllReverse(struct node *head);

int main()
{
	int ch;
	struct node *head;
	head = NULL;
	printf("This is a Link List program!!!\n");
	head = createNode(head);
	displayAllNormal(head);
	do
	{
		printf("\n 1. Add Node at Beginning\n 2. Add Node at End\n 3. Add Node at certain position\n");
		printf(" 4. Delete Node at Beginning\n 5. Delete Node at End\n 6. Delete Node at certain position\n");
		printf(" 7. Count total number of nodes\n 8. Display all Nodes\n 9. Display in Reverse\n 0. Exit");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :	head = addNodeStart(head);
						displayAllNormal(head);
						break;
			case 2 :	head = addNodeEnd(head);
						displayAllNormal(head);
						break;
			case 3 :	head = addNodePlace(head);
						displayAllNormal(head);
						break;
			case 4 :	head = delNodeStart(head);
						displayAllNormal(head);
						break;
			case 5 :	head = delNodeEnd(head);
						displayAllNormal(head);
						break;
			case 6 :	head = delNodePlace(head);
						displayAllNormal(head);
						break;
			case 7 :	printf("\nTotal Nodes are: %d\n", nodeLength(head));
						break;
			case 8 :	displayAllNormal(head);
						break;
			case 9 :	displayAllReverse(head);
						break;
			case 0 :	break;
			default: printf("\nInvalid choice!!!\n");
		}
	}while(ch);
	return 0;
}

void displayAllNormal(struct node *head)
{
	struct node *ptr;
	ptr = head;
	printf("Current Status:\n");
	while(ptr != NULL)
	{
		printf("%d\t", ptr->num);
		ptr = ptr->next;
	}
}

struct node *createNode( struct node *head)
{
	struct node *ptr, *newNode;

	int val;

	ptr = head;



	printf("Enter value to add ( 0 to end adding): \n");
	scanf("%d", &val);
	do
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->num = val;
		newNode->next = NULL;
		
		if(head == NULL)
			head = ptr = newNode;
		else
		{
			ptr->next = newNode;
			ptr = ptr->next;
		}
		
		scanf("%d", &val);
	} while (val);
	printf("Link List created!!\n");
	return head;

}

struct node *addNodeEnd( struct node *head)
{
	int val;
	struct node *ptr, *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));

	printf("Enter data to add at end: ");
	scanf("%d", &val);

	newNode->num = val;
	newNode->next = NULL;

	ptr = head;
	if(head == NULL)
		head = ptr = newNode;
	else
	{
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newNode;
	}
	printf("Added\n");
	return head;
}

struct node *addNodeStart( struct node *head)
{
	int val;
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));

	printf("Enter data to add at beginning: ");
	scanf("%d", &val);

	newNode->num = val;
	newNode->next = head;
	head = newNode;
	printf("Added\n");
	return head;
}

struct node *addNodePlace( struct node *head)
{
	int val, ch;
	struct node *ptr, *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));

	printf("Enter data to add in middle: ");
	scanf("%d", &val);
	printf("Place where you want to add data: ");
	scanf("%d", &ch);

	newNode->num = val;
	newNode->next = NULL;

	ptr = head;
	if(head == NULL)
	{
		if (ch == 1)
			head = ptr = newNode;
		else
		{
			printf("Invalid position! No node exists!!\n");
			return head;
		}
	}
	else
	{
		while(ptr->next != NULL && ch !=2)
		{
			ptr = ptr->next;
			ch--;
		}
		if(ch == 2)
		{
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
		else
		{
			printf("Invalid position!! Underflow caught!!\n");
			return head;
		}
	}
	printf("Added\n");
	return head;
}

struct node *delNodeEnd(struct node *head)
{
	struct node *ptr, *preptr;
	ptr = preptr = head;
	if(head == NULL)
	{
		printf("\nUnderflow Caught!! No Node found!!!\n");
		return head;
	}
	else if (head->next == NULL)
		head = NULL;
	else
	{
		while(ptr->next != NULL)
		{
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = NULL;
	}
	free(ptr);
	printf("\nLast Node deleted\n");
	return head;
}

struct node *delNodeStart(struct node *head)
{
	struct node *ptr;
	ptr = head;
	if(head == NULL)
	{
		printf("\nUnderflow Caught!! No Node found!!!\n");
		return head;
	}
	else
		head = head->next;
	free(ptr);
	printf("\nFirst Node deleted\n");
	return head;
}

struct node *delNodePlace(struct node *head)
{
	int ch;
	printf("\nPlace of node to be deleted: \n");
	scanf("%d", &ch);
	ch--;
	struct node *ptr, *preptr;
	ptr = preptr = head;
	if(head == NULL)
	{
		printf("Underflow Caught!! No Node found!!!\n");
		return head;
	}
	else
	{
		while(ptr->next != NULL && ch != 0)
		{
			preptr = ptr;
			ptr = ptr->next;
			ch--;
		}
		if (ch == 0)
		{
			preptr->next = ptr->next;
		}
		else
		{
			printf("Underflow Caught!!! No node at given place!!\n");
			return head;
		}
	}
	free(ptr);
	printf("Node deleted\n");
	return head;
}

int nodeLength(struct node *head)
{
	int counter = 0;
	struct node *ptr;
	ptr = head;
	while(ptr != NULL)
	{
		counter++;
		ptr = ptr->next;
	}
	return counter;
}

void displayAllReverse(struct node *head)
{
	if(head == NULL)
		return;
	displayAllReverse(head->next);
	printf("%d\t", head->num);
}