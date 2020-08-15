#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cust
{
	char name[25];
	long int acc_no;
	int bal;
};

int main()
{
	struct cust data;
	int i, n;

	FILE *fptr;
	fptr = fopen("cust_data.txt","w" );

	printf("Enter number of data to add: \n");
	scanf("%d", &n);
	getchar();

		for (i = 0; i < n; ++i)
		{
			printf("Enter data of customer %d\n", i+1);
			printf("Name: ");
			gets(data.name);
			fprintf(fptr, "%s ", data.name);
			printf("Account Number: ");
			scanf("%ld", &data.acc_no);
			fprintf(fptr, "%ld,", data.acc_no);
			printf("Account Balance: ");
			scanf("%d", &data.bal);
			fprintf(fptr, "%d,", data.bal);
			getchar();
		}
	fclose(fptr);

	return 0;
}