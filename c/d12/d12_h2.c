#include<stdio.h>
#include<stdlib.h>
typedef struct phoneData
{
	char name[30];
	char email[40];
	char phoneNo[10];
}teleDir;

void add(teleDir *t)
{
	FILE *fptr;
	fptr=fopen("directory.txt","a");
	if(fptr==NULL)
	{
		printf("Cannot open file.");
		return;
	}
	getchar();
	printf("Enter Name:");
	gets(t->name);
	printf("Enter phone no:");
	gets(t->email);
	printf("Enter email:");
	gets(t->phoneNo);
	fwrite(t,sizeof(teleDir),1,fptr);
	fclose(fptr);
	printf("DATA ADDED.\n");
}

void show(teleDir *t)
{
	FILE *fptr;
	fptr=fopen("directory.txt","r");
	if(fptr==NULL)
	{
		printf("Cannot open file.\n");
		return;
	}
	if(feof(fptr))
	{
		printf("Empty\n");
		fclose(fptr);
		return;
	}
	while(fread(t,sizeof(teleDir),1,fptr))
	{
		printf("%s\t\t",t->name);
		printf("%s\t\t",t->phoneNo);
		printf("%s\n",t->email);
	}
	fclose(fptr);
	return;
}
int main()
{
	int i=0;
	teleDir *t=(teleDir *)calloc(1,sizeof(teleDir));
	do
	{
		printf("1.Add new contact\n2.Show all Contacts\n3.Exit\nEnter your choice:");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				add(t);
				break;
			case 2:
				show(t);
				break;
			case 3:
				exit;
				break;
			default:
				printf("INVALID CHOICE:\n");
				break;
		}
	}while(i!=3);
	free(t);
	return 0;
}
