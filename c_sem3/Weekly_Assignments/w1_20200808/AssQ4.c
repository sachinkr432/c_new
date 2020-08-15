/*
While making this program, I tried to take input from file but after multiple failure
I decided to work on that later.
PLEASE skip those commented lines!!!
#SACHIN
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

struct cust
{
	char name[25];
	long int acc_no;
	int bal;
};

void printName(struct cust obj[], int n);
void addBalance(struct cust obj[], int n);
void printAll(struct cust data[], int n);

int main()
{
	int i=0,n;
	float time_in_sec;
	clock_t start, end;
	start = clock();

		/*
		struct cust data[SIZE];
		FILE *fptr;
		if ((fptr=fopen("cust_data.txt","r"))==NULL)
		{
			printf("cust_data.txt failed to open\n");
			return 1;
		}
		else
		{
			while(!feof(fptr))
			{
				fscanf(fptr, "%s", data[i].name);
				fscanf(fptr, "%ld,", data[i].acc_no);
				fscanf(fptr, "%d,", data[i].bal);
				i++;
			}
			n=i;
			printf("Value of N is %d\n", n);
		}
		*/

		printf("Enter number of data to put: ");
		scanf("%d",&n);
		getchar();
		struct cust data[n];
		for (i = 0; i < n; ++i)
		{
			printf("Enter data of customer %d\n", i+1);
			printf("Name: ");
			gets(data[i].name);
			printf("Account Number: ");
			scanf("%ld", &data[i].acc_no);
			printf("Account Balance: ");
			scanf("%d", &data[i].bal);
			getchar();
		}


	printAll(data, n);
	printName(data, n);
	printf("\n");
	addBalance(data, n);

	//fclose(fptr);
	end = clock();
	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("The execution time is %f",time_in_sec);
	return 0;
}

void printName(struct cust obj[], int n)
{
	int j=1;
	printf("Person with balance less than $200\n");
	for(int i=0; i<n; i++)
		if(obj[i].bal<200)
		{
			printf("%s\n", obj[i].name );
			j=0;
		}
	if(j)
		printf("None\n");
}

void addBalance(struct cust obj[], int n)
{
	int j=1;
	printf("New Balance of Person with balance greater than $1000\n");
	for(int i=0; i<n; i++)
		if(obj[i].bal>1000)
		{
			j=0;
			printf("%s\t", obj[i].name );
			printf("%d\n", obj[i].bal += 100);
		}
	if(j)
		printf("None\n");
}

void printAll( struct cust data[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("%s\t", data[i].name );
		printf("%ld\t", data[i].acc_no);
		printf("%d\n", data[i].bal);
	}
}