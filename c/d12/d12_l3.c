#include <stdio.h>
#include <stdlib.h>

typedef struct employee
{
	int empNo;
	char name[30];
	char dept[10];
	float basicPay;
	float DA;
	float HRA;
	float totalSalary;
}employee;

void addData(employee *ptr);
void showData(employee *ptr);
void update(employee *ptr);


int main()
{
	int ch;
	employee *ptr = (employee *)malloc(sizeof(employee));
	while(1)
	{
		printf("Choice\n1. Add Data\n2. Show Result\n3. Exit\n\t\t");
		scanf("%d",&ch);

		if (ch==3)
			break;
		else if (ch==1)
		{
			addData(ptr);
			update(ptr);
		}
		else if (ch==2)
			showData(ptr);
		else
			printf("Invalid Entry\n");
	}
	free(ptr);
	return 0;
}

void addData(employee *ptr)
{
	float DAcent,HRAcent;
	FILE *fptr;
	fptr = fopen("I_P.txt","a");

	printf("Enter empNo: ");
	scanf("%d",&ptr->empNo);
	getchar();
	printf("Enter name: ");
	gets(ptr->name);
	printf("Enter Department: ");
	gets(ptr->dept);
	printf("Enter basic Pay: ");
	scanf("%f",&ptr->basicPay);
	printf("Enter percent of DA: ");
	scanf("%f",&DAcent);
	ptr->DA = ((ptr->basicPay*DAcent)/100.0);
	printf("Enter percent of HRA: ");
	scanf("%f",&HRAcent);
	ptr->HRA = ((ptr->basicPay*HRAcent)/100.0);

	ptr->totalSalary = (ptr->basicPay + ptr->DA + ptr->HRA);

	fwrite(ptr,sizeof(struct employee),1,fptr);

	fclose(fptr);
	printf("Data added Successfully\n\n");
}

void update(employee *ptr)
{
	int p=0;
	FILE *fptr;
	fptr = fopen("I_P.txt","r");
	employee *temptr = (employee *)malloc(sizeof(employee));
	if (fptr!=NULL)
	{
		p=1;
		fread(ptr,sizeof(struct employee),1,fptr);
		*temptr = *ptr;
	}
	while(fread(ptr,sizeof(struct employee),1,fptr))
	{
		if (ptr->totalSalary > temptr->totalSalary)
			*temptr = *ptr;
	}
	fclose(fptr);
	if (p==1)
	{
		fptr = fopen("O_P.txt","w");
		fwrite(temptr,sizeof(struct employee),1,fptr);
		fclose(fptr);
	}
	else
		printf("No content to show\n");
}

void showData(employee *ptr)
{
	FILE *fptr;
	fptr = fopen("O_P.txt","r");
	fread(ptr,sizeof(struct employee),1,fptr);

	printf("EmpNo: %d\n",ptr->empNo);
	printf("Name: %s\n",ptr->name);
	printf("Department: %s\n",ptr->dept);
	printf("Basic Pay: %0.2f\n", ptr->basicPay);
	printf("DA: %0.2f\n", ptr->DA);
	printf("HRA: %0.2f\n", ptr->HRA);
	printf("Total Gross Salary: %0.2f\n\n", ptr->totalSalary);

	fclose(fptr);
}