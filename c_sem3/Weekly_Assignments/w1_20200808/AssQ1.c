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
	int max, min;
	if(fscanf(fptr,"%d",&nums[i])!=EOF)
	{
		max = nums[i];
		min = nums[i];
	}

	while((fscanf(fptr,"%d",&nums[i]))!=EOF) 
	{
		if(nums[i]<min)
			min = nums[i];
		else if (nums[i]>max)
			max = nums[i];
		i++;
	}
	n = i;

	printf("Numbers are:\n");
	for(i=0; i<n; i++)
		printf("%d ",nums[i] );

	printf("\n");
	printf("Max is %d\n", max);
	printf("Min is %d\n", min);

	end = clock();
	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("The execution time is %f",time_in_sec);
	return 0;
}