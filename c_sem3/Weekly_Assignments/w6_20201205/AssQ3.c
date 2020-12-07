#include<stdio.h>
#include<stdlib.h>
typedef struct C_queue
{
	int data;
	struct C_queue *next;
}list;
list *front,*rear,*p;
void display();
void enqueue(int);
int dequeue();
int main()
{
	int data,ch;
	do
	{
	printf("Enter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("Enter data:");
		scanf("%d",&data);
		enqueue(data);
		break;
		case 2:
		dequeue();
		break;
		case 3:
		display();
		break;
		case 4:
		exit(0);
		break;
		default:
		printf("Invalid choice\n");
		break;
	}
	}while(1);
	return 0;
}
void enqueue(int data)
{
	list *node=(list*)malloc(sizeof(list));
	if(rear==NULL)
	{
		front=node;
		rear=node;
	}
	node->data=data;
	rear->next=node;
	rear=node;
	node->next=front;
}
void display()
{
	list* ptr;
	ptr=front;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return ;
	}
	do
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}while(ptr!=front);
}
int dequeue()
{
	list *temp=front;
	int data;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return 0;
	}
	if(front==rear)
	{
		data=rear->data;
		front=NULL;
		free(rear);
		rear=NULL;
		printf("Dequeued element is %d\n",data);
		return data;
	}
	else
	{
		front=front->next;
		rear->next=front;
	}
	data=temp->data;
	free(temp);
	printf("Dequeued element is %d\n",data);
	return data;
}
