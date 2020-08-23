// created by SACHIN
// Program to find the merger in a linklist;
// It creates a merger and then finds value in same;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
	int num;
	struct node *next;
};

int trace(struct node **, struct node **);
void createNode(struct node **, struct node **);
void displayAll(struct node **, struct node **);

int main()
{
	srand(time(0));
	int res;
	struct node *h1 = NULL, *h2 = NULL;
	struct node **head1, **head2;
	head1 = &h1;
	head2 = &h2;
	createNode(head1, head2);
	displayAll(head1, head2);
	printf("\nTracing the merge point\n");
	if ((res = trace(head1, head2)) > 0)
		printf("Address of Merger: %d\n", res);
	else
		printf("No Merger found!!\n");
	return 0;
}

// This function creates two linklist in which merger is "FORCEFULLY" created in between the total length of linklist;
// If the two link list is provided, this function is of no use;
void createNode(struct node **head1, struct node **head2)
{
	int i;
	struct node *newNode, *ptr1 = *head1, *ptr2 = *head2;

	//Creating non-shared part of 1st linklist
	int n = (rand()%5 + 6);	//n between (6-10)
	// printf("1st Linklist length: %d\n", n);
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
	// printf("2nd Linklist length: %d\n", n);
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

// This displays the two linklist side by side along with address of each node.
void displayAll(struct node **head1, struct node **head2)
{
	struct node *ptr1, *ptr2;
	ptr1 = *head1;
	ptr2 = *head2;
	// printf("%d\t%d\n", *head1, *head2);
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
			printf("%d\t%d", ptr2->num, ptr2);
			ptr2 = ptr2->next;
		}
		printf("\n");
	}
}


// This function is to find where is merger. 
// It displays value if merger is found and returns address of that node, else returns -1
int trace(struct node **head1, struct node **head2)
{
	struct node *ptr1, *ptr2;
	ptr1 = *head1;
	ptr2 = *head2;
	while(ptr1 != NULL)
	{
		ptr2 = *head2;
		while(ptr2 != NULL)
		{
			if (ptr1 == ptr2)
			{
				printf("Value at Merge: %d\n", ptr1->num);
				return (int)ptr1;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return -1;
}