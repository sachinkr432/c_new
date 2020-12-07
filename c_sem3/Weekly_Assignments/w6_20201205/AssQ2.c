#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}dll;
dll* create(dll *head);
void display(dll *head);
dll* insert_beg(dll *head,int data);
dll* insert_end(dll *head,int data);
dll* insert_pos(dll *head,int pos,int data);
dll* del_beg(dll *head);
dll* del_end(dll *head);
dll* del_pos(dll *head,int pos);
int main()
{
	int data,ch,pos;
	dll *p=NULL;
	do
	{
	printf("Enter your choice\n1.Create a doubly linked list\n2.Display\n3.Insert at beginning\n4.Insert at end\n");
	printf("5.Insert at position\n6.Delete from beginning\n7.Delete from end\n8.Delete from position\n-1 to end\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		p=create(p);
		break;
		case 2:
		display(p);
		break;
		case 3:
		printf("Enter data:");
		scanf("%d",&data);
		p=insert_beg(p,data);
		break;
		case 4:
		printf("Enter data:");
		scanf("%d",&data);	
		p=insert_end(p,data);
		break;
		case 5:
		printf("Enter data,position:");
		scanf("%d%d",&data,&pos);
		p=insert_pos(p,data,pos);
		break;
		case 6:
		p=del_beg(p);
		break;
		case 7:
		p=del_end(p);
		break;
		case 8:
		printf("Enter position:");
		scanf("%d",&pos);
		p=del_pos(p,pos);
		break;
		case -1:
		printf("Exiting the program\n");
		break;
		default :
		printf("Invalid input\n");	
	}
	}while(ch!=-1);
	return 0;
}
dll* create(dll *head)
{
	int n,ch;
	dll *node,*ptr;
	ptr=head;
	printf("-1 to end insertion of data\n");
	printf("Enter data (-1 to end):");
	scanf("%d",&n);
	while(n!=-1)
	{
		node=(dll*)malloc(sizeof(dll));
		node->data=n;
		node->next=NULL;
		if(head==NULL)
		{
			head=ptr=node;
		}				
		else
		{
			ptr->next=node;
			node->prev=ptr;
			ptr=node;
		}
		printf("Enter data (-1 to end):");
		scanf("%d",&n);
	}
	return head;
}
void display(dll *head)
{
	dll *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("DLL is empty\n");
		return;
	}
	printf("List=");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}
dll* insert_beg(dll *head,int data)
{
	dll *p,*newnode;
	newnode=(dll*)malloc(sizeof(dll));
	newnode->data=data;
	p=head;
	newnode->next=p;
	p->prev=newnode;
	head=newnode;
	printf("Data inserted succesfully\n");
	return head;
}
dll* insert_end(dll *head,int data)
{
	dll *p,*newnode,*q;
	p=q=head;
	newnode=(dll*)malloc(sizeof(dll));
	newnode->data=data;
	newnode->next=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=newnode;
	newnode->prev=q;
	printf("Data inserted succesfully\n");
	return head;
}
dll* insert_pos(dll *head,int data,int pos)
{
	dll *p,*newnode,*q;
	p=q=head;
	int k=1;
	newnode=(dll*)malloc(sizeof(dll));
	newnode->data=data;
	while((p!=NULL)&&(k<pos))
	{
		k++;
		q=p;
		p=p->next;
	}
	if(p==NULL)
	{
		printf("Position not found\n");
	//	head=insert_end(head,data);
	}
	else
	{
	q->next=newnode;
	newnode->next=p;
	newnode->prev=q;
	q->next=newnode;
	p->prev=newnode;
	printf("Data inserted succesfully\n");
	}
	return head;
}
dll* del_beg(dll *head)
{
	dll *p,*q;
	if (head==NULL)
	{
		printf("DLL is empty\n");
		return head;
	}
	p=head;
	q=head->next;
	head=head->next;
	q->prev=head;
	free (p);
	printf("Node deleted\n");
	return head;
}
dll* del_end(dll *head)
{
	dll *p,*q;
	if (head==NULL)
	{
		printf("DLL is empty\n");
		return head;
	}
	p=q=head;
	while (p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);
	printf("Node deleted\n");
	return head;
}
dll* del_pos(dll *head,int pos)
{
	dll *p,*q;
	int k=1;
	p=q=head;
	if (head==NULL)
	{
		printf("DLL is empty\n");
		return head;
	}
	while ((p->next!=NULL)&&(k<pos))
	{
		k++;
		q=p;
		p=p->next;
	}
	if(k==pos)
	{
		q->next=p->next;
		p->next->prev=p->prev;
	}
	else
		printf("position does not exists\n");
	return head;
}
