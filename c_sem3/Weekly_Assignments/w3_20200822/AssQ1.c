#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
	int num;
	struct node *next;
};

int trace(struct node *, struct node *);
void createNode(struct node **, struct node **);
void displayAll(struct node **, struct node **);

int main()
{
	srand(time(0));
	struct node *h1 = NULL, *h2 = NULL;
	struct node **head1, **head2;
	head1 = &h1;
	head2 = &h2;
	createNode(head1, head2);
	displayAll(head1, head2);
	return 0;
}

void createNode(struct node **head1, struct node **head2)
{
	int i;
	struct node *newNode, *ptr1 = *head1, *ptr2 = *head2;

	//Creating non-shared part of 1st linklist
	int n = (rand()%5 + 6);	//n between (6-10)
	for (i=0; i < n; ++i)
	{
		// printf("Hello\n");
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->num = (rand()%300 + 1);
		newNode->next = NULL;
		if(*head1 == NULL)
			*head1 = ptr1 = newNode;
		else
		{
			ptr1->next = newNode;
			ptr1 = newNode;
		}
	}

	//Creating non-shared part of 2nd linklist
	n = (rand()%5 + 6);	//n between (6-10)
	for (i=0; i < n; ++i)
	{
		// printf("Hello\n");
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->num = (rand()%300 + 1);
		newNode->next = NULL;
		if(*head2 == NULL)
			*head2 = ptr2 = newNode;
		else
		{
			ptr2->next = newNode;
			ptr2 = newNode;
		}
	}

	//Here comes merged (shared) part
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = (rand()%300 + 1);
	newNode->next = NULL;
	ptr1->next = newNode;
	ptr2->next = newNode;
	ptr2 = newNode;
	n = (rand()%5 + 6); //n between (6-10)
	for (i=0; i < n; ++i)
	{
		// printf("Hello\n");
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->num = (rand()%300 + 1);
		newNode->next = NULL;
		ptr2->next = newNode;
		ptr2 = newNode;
	}
}

void displayAll(struct node **head1, struct node **head2)
{
	struct node *ptr1, *ptr2 = *head2;
	ptr1 = *head1;
	printf("%d\t%d\n", *head1, *head2);
	printf("Current Status:\n");
	while(ptr1 != NULL || ptr2 != NULL)
	{
		if (ptr1 != NULL)
		{
			printf("%d\t%d\t", ptr1->num, ptr1);
			ptr1 = ptr1->next;
		}
		else
			printf("\t\t");
		if (ptr2 != NULL)
		{
			printf("%d\t%d", ptr1->num, ptr1);
			ptr1 = ptr1->next;
		}
		printf("\n");
	}
}
