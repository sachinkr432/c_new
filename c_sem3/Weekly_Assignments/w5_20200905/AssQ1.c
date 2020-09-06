// created by SACHIN 
// Program to find systematic moves for problem of Hanoi Tower

#include <stdio.h>
#include <time.h>

void move(int, char, char, char);

int count = 0;

int main()
{
	float time_in_sec;
	clock_t start, end;
	start = clock();

	int n;
	printf("\nWe have to transfer all from A to C\n");
	printf("Enter the size of tower: ");
	scanf("%d", &n);
	start = clock();
	move(n, 'A', 'B', 'C');
	end = clock();
	printf("\nTotal number of moves: %d\n", count);
	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("\nTime complexity: %f\n", time_in_sec);
	return 0;
}

void move(int n, char source, char spare, char dest)
{
	if(n == 1)
	{
		printf("\n\t%c -> %c", source, dest);
		count++;
	}
	else
	{
		move(n-1, source, dest, spare);
		move(1, source, spare, dest);
		move(n-1, spare, source, dest);
	}
}