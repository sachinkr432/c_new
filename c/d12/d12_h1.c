#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
	char author[25];
	char publisher[25];
	int price;
	char branch[10];
}bookDetail;

void print(bookDetail *ptr);
void add(bookDetail *ptr);
void srcBranch(bookDetail *ptr);
void srcPublisher(bookDetail *ptr);

int main()
{
	bookDetail *ptr;
	int i;
	ptr = (bookDetail*)malloc(sizeof(bookDetail));
	while(1)
	{
		printf("\nChoice are:\n1. Add new Book\n2. Search by Branch\n3. Search by Publisher\n4. Exit\t\t");
		scanf("%d",&i);
		getchar();
		if (i==4)
			break;
		else if (i==1)
			add(ptr);
		else if (i==2)
			srcBranch(ptr);
		else if(i==3)
			srcPublisher(ptr);
		else
			printf("INVALID INPUT\n");
	}
	return 0;
}

void print(bookDetail *ptr)
{
	printf("%s\t\t",ptr->author);
	printf("%s\t\t",ptr->publisher);
	printf("%d\t\t",ptr->price);
	printf("%s\n", ptr->branch);
}

void add(bookDetail *t)
{
	FILE *fptr;
	fptr=fopen("lib.txt","a");
	if(fptr==NULL)
	{
		printf("Cannot open file.");
		fclose(fptr);
		return;
	}
	printf("Enter Author name: ");
	gets(t->author);
	printf("Enter Publisher name: ");
	gets(t->publisher);
	printf("Enter Price: ");
	scanf("%d",&t->price);
	getchar();
	printf("Enter Branch (in short): ");
	gets(t->branch);
	fwrite(t,sizeof(bookDetail),1,fptr);
	fclose(fptr);
	printf("DATA ADDED.\n");
}

void srcBranch(bookDetail *ptr)
{
	FILE *fptr;
	int p=0;
	char tempBranch[10];
	fptr = fopen("lib.txt","r");
	if(fptr==NULL)
	{
		printf("Cannot open file.\n");
		fclose(fptr);
		return;
	}
	if(feof(fptr))
	{
		printf("Empty\n");
		fclose(fptr);
		return;
	}
	printf("Enter Branch to search: ");
	gets(tempBranch);

	printf("%s\t\t","Author");
	printf("%s\t\t","Publisher");
	printf("%s\t\t","Price");
	printf("%s\n", "Branch");

	while(fread(ptr,sizeof(bookDetail),1,fptr))
	{
		if (!strcmp(tempBranch,ptr->branch))
		{
			print(ptr);
			p=1;
		}
	}
	if(!p)
		printf("0 search Found\n");
	fclose(fptr);
	return;
}

void srcPublisher(bookDetail *ptr)
{
	FILE *fptr;
	char tempPublisher[25];
	fptr = fopen("lib.txt","r");
	if(fptr==NULL)
	{
		printf("Cannot open file.\n");
		fclose(fptr);
		return;
	}
	if(feof(fptr))
	{
		printf("Empty\n");
		fclose(fptr);
		return;
	}
	printf("Enter Publisher name to search: ");
	gets(tempPublisher);

	printf("%s\t\t","Author");
	printf("%s\t\t","Publisher");
	printf("%s\t\t","Price");
	printf("%s\n", "Branch");
	
	while(fread(ptr,sizeof(bookDetail),1,fptr))
	{
		if (strcmp(tempPublisher,ptr->publisher))
			continue;
		print(ptr);
	}
	fclose(fptr);
	return;
}