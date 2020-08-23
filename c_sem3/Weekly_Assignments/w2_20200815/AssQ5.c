// created by SACHIN
// Checks whether two linklist are IDENTICAL or not;

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct node *addNodeEnd( struct node *head);
void displayAllNormal(struct node *head);
void cmpNode( struct node *head1, struct node *head2);

int main()
{
	struct node *head1, *head2;
	head1 = head2 = NULL;
	printf("For 1st Node\n");
	head1 = addNodeEnd(head1);

	printf("\nFor 2nd Node\n");
	head2 = addNodeEnd(head2);

	printf("\nValue For 1st Node\n");
	displayAllNormal(head1);
	printf("\nValue For 2nd Node\n");
	displayAllNormal(head2);
	printf("\n");
	cmpNode(head1, head2);
	return 0;
}

struct node *addNodeEnd( struct node *head)
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
	return head;

}

void displayAllNormal(struct node *head)
{
	struct node *ptr;
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\t", ptr->num);
		ptr = ptr->next;
	}
}

void cmpNode( struct node *head1, struct node *head2)
{
	struct node *ptr1, *ptr2;
	ptr1 = head1;
	ptr2 = head2;
	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(ptr1->num != ptr2->num)
			break;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	if(ptr1 == NULL && ptr2 == NULL)
		printf("Link List Identical\n");
	else
		printf("Link List not Identical\n");
}