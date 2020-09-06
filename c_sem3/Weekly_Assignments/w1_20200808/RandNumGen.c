#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	float time_in_sec;

	clock_t start, end;
	
	int n,I,J,Duplicate,Numbers[1000];
	FILE *fptr;
	printf("Enter how many random numbers you want to generate");
	scanf("%d",&n);
	//for loop to generate a complete set of n random numbers
	start = clock();
	for (I = 0; I < n; I++)
	{
		// do while loop used to generate random numbers until a distinct random number is generated
		do
		{
			Duplicate = 0; // set check to false
			Numbers[I] = (rand()%n) + 1; // generates a random number 1 - n and stores it into Numbers[I]
			// for loop used to check the other numbers in set for any repeats
			for (J = I - 1; J > -1; J--) 
				if (Numbers[I] == Numbers[J]) 
				{
					Duplicate = 1; //sets Duplicate to true to indicate there is a repeat
					break;
				}
		} while (Duplicate); //loops until a new, distinct number is generated
	}

	//int count = 0;
	//for(I=0;I<n;I++)
	//{
		//printf("%d ",Numbers[I]);
		//count ++;
	//}
	//printf("\nTotal nos: %d\n", count);
	fptr = (fopen("unsorted.txt", "w"));
	if(fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	for(I=0;I<n;I++)
		fprintf(fptr,"%d ", Numbers[I]);
	fclose(fptr);
	end = clock();
	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("The execution time is %f",time_in_sec);
}