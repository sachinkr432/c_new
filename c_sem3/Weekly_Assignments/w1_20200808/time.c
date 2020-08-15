#include <stdio.h>
#include <time.h>
int main()
{
	float time_in_sec;
	int array[100] = {2, 5, 7, 3, 12, 15, 4, 78, 54, 65}, search=78, c, n=10;
	clock_t start, end;
	start = clock();
	//printf("Enter number of elements in array\n");
	//scanf("%d", &n);
	//printf("Enter %d integer(s)\n", n);
	//for (c = 0; c < n; c++)
	//	scanf("%d", &array[c]);
	//printf("Enter a number to search\n");
	//scanf("%d", &search);
	for (c = 0; c < n; c++)
	{
		if (array[c] == search) /* If required element is found */
		{
			printf("%d is present at location %d.\n", search, c+1);
			break;
		}
	}
	if (c == n)
	printf("%d isn't present in the array.\n", search);
	end = clock();
	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("The execution time is %f",time_in_sec);
	return 0;
}