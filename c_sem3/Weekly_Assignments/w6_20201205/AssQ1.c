#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial
{
	int coeff;
	int power;
	struct polynomial *next;
}poly;
poly* create_node(poly *head,int coeff,int power);
void print(poly *ptr);
void remove_dup(poly *head);
poly* multiply(poly* poly1,poly* poly2,poly* poly3);
int main()
{
	int i,terms,coeff,power;
	poly *poly1=NULL;
	poly *poly2=NULL;
	poly *poly3=NULL;
	printf("Enter no. of terms of poly 1:");
	scanf("%d",&terms);
	for(i=1;i<=terms;i++)
	{
		printf("Enter coeff %d",i);
		scanf("%d",&coeff);
		printf("Enter power %d",i);
		scanf("%d",&power);
		poly1=create_node(poly1,coeff,power);
	}
	printf("Enter no. of terms of poly 2:");
	scanf("%d",&terms);
	for(i=1;i<=terms;i++)
	{
		printf("Enter coeff %d",i);
		scanf("%d",&coeff);
		printf("Enter power %d",i);
		scanf("%d",&power);
		poly2=create_node(poly2,coeff,power);
	}
	printf("\n1st polynomial is :");
	print(poly1);
	printf("\n2nd polynomial is :");
	print(poly2);
	poly3=multiply(poly1,poly2,poly3);
	printf("\nResultant polynomial is :");
	print(poly3);
	return 0;
}
poly* create_node(poly *head,int coeff,int power)
{
	poly *newnode;
	newnode=(poly*)malloc(sizeof(poly));
	newnode->coeff=coeff;
	newnode->power=power;
	newnode->next=NULL;
	if(head==NULL)
		return newnode;
	poly* ptr=head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=newnode;
	return head;
}
void print(poly *ptr)
{
	while(ptr!=NULL)
	{
		printf("%dx^%d",ptr->coeff,ptr->power);
		if(ptr->next!=NULL)
		printf("+");
		ptr=ptr->next;
	}
}
void remove_dup(poly *head)
{
	poly *ptr1,*ptr2,*dup;
	ptr1=head;
	while(ptr1!=NULL && ptr1->next!=NULL)
	{
		ptr2=ptr1;
		while(ptr2->next!=NULL)
		{
			if(ptr1->power==ptr2->next->power)
			{
				ptr1->coeff+=ptr1->next->coeff;
				dup=ptr2->next;
				ptr2->next=ptr2->next->next;
				free(dup);
			}
			else
				ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}
poly* multiply(poly* poly1,poly* poly2,poly* poly3)
{
	poly *ptr1,*ptr2;
	ptr1=poly1;
	ptr2=poly2;
	while(ptr1!=NULL)
	{
		while(ptr2!=NULL)
		{
			int power,coeff;
			power=ptr1->power+ptr2->power;
			coeff=ptr1->coeff*ptr2->coeff;
			poly3=create_node(poly3,coeff,power);
			ptr2=ptr2->next;
		}
		ptr2=poly2;
		ptr1=ptr1->next;
	}
	remove_dup(poly3);
	return poly3;
}
