// created by SACHIN
// This program implements polynomial addition using sinly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coef;
	int expo;
	struct node *next;
};

struct node *getPoly( struct node*);
void showPoly(struct node*);
void addPoly(struct node**, int);

int main()
{
	int i, n;
	printf("Enter number of polynomial to recieve: ");
	scanf("%d", &n);
	struct node **head;
	head = (struct node**)malloc(sizeof(struct node*)*(n+1));
	head[n] = NULL;
	for (i = 0; i < n; ++i)
	{
		printf("Enter %dth polynomial\n", i+1);
		head[i] = getPoly(head[i]);
		showPoly(head[i]);
		printf("\n");

	}
	printf("\nPolynomial addition initiated!\n");
	addPoly( head, n);
	showPoly(head[n]);
	return 0;
}

struct node *getPoly( struct node *ptr)
{
	int coe, exp;
	int flag = 1;

	struct node *tmp;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->next = NULL;
	ptr = tmp;

	while(flag)
	{
		printf("Enter coefficient: ");
		scanf("%d", &coe);
		tmp->coef = coe;
		printf("Enter exponent: ");
		scanf("%d", &exp);
		tmp->expo = exp;

		printf("Press 0 to stop adding: ");
		scanf("%d", &flag);
		if(flag)
		{
			tmp->next = (struct node*)malloc(sizeof(struct node));
			tmp = tmp->next;
			tmp->next = NULL;
		}
	}
	return ptr;
}

void showPoly(struct node *ptr)
{
	printf("\nThe polynomial expression is:\n");
	while(ptr != NULL)
	{
		printf("%dx^%d", ptr->coef, ptr->expo);
		ptr = ptr->next;
		if(ptr != NULL)
			printf(" + ");
	}
}

void addPoly(struct node **head, int n)
{
	int i = 0;
	struct node *ptr1, *ptr2;
	printf("Hiiiiii\n");
	while(i<n)
	{
		ptr1 = head[i];
		while(ptr1 != NULL)
		{
			ptr2 = head[n];
			while(ptr2 != NULL)
			{
				if(ptr2->expo == ptr1->expo)
				{
					ptr2->coef += ptr1->coef;
					break;
				}
				ptr2 = ptr2->next;
			}
			if (head[n] == NULL)
			{
				head[n] = (struct node*)malloc(sizeof(struct node));
				ptr2 = head[n];
				ptr2->expo = ptr1->expo;
				ptr2->coef = ptr1->coef;
				ptr2->next = NULL;

			}
			if(ptr2 == NULL)
			{
				ptr2 = (struct node*)malloc(sizeof(struct node));
				ptr2->expo = ptr1->expo;
				ptr2->coef = ptr1->coef;
				ptr2->next = NULL;
			}
			ptr1 = ptr1->next;
		}
		i++;
	}
}