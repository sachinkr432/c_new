//#SACHIN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main()
{
	float time_in_sec;
	clock_t start, end;
	start = clock();

	int nums[SIZE];
	FILE *fptr;
	int i=0,n;
	if ((fptr=fopen("random_numbers.txt","r"))==NULL)
	{
		printf("random_numbers.txt failed to open\n");
		return 1;
	}
	float avg = 0;
	while((fscanf(fptr,"%d",&nums[i]))!=EOF) 
	{
		avg += nums[i];
		i++;
	}
	n = i;
	avg /= n;

	printf("Numbers are:\n");
	for(i=0; i<n; i++)
		printf("%d ",nums[i] );

	int *ptro, *ptre;
	ptro = (int*)calloc(n/2 + 1, sizeof(int));
	ptre = (int*)calloc(n/2 + 1, sizeof(int));

	int j=0, k=0;
	for( i=0; i<n; i++)
	{
		if(avg< nums[i])
			if(i%2)
				ptro[j++] = nums[i];
			else
				ptre[k++] = nums[i];
	}

	printf("\nNumbers at odd places:\n");
	for(i=0; i<j; i++)
		printf("%d ",ptro[i] );

	printf("\nNumbers at even places:\n");
	for(i=0; i<k; i++)
		printf("%d ",ptre[i] );

	free(ptre);
	free(ptro);

	end = clock();
	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("The execution time is %f",time_in_sec);
	return 0;
}