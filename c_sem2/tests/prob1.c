#include<stdio.h>

int main()
{
	int n;
	printf("Enter the number : ");
	scanf("%d",&n);
	if (n%2 == 0)
		printf("Number is not prime.");
	else
	{
		int i=3;
		while(i*i<=n)
		{
			if(n%i==0)
			{	
				printf("Number is not prime.");
				break;	
			}
			else
				i+=2;
		}
		if(n<=i*i)
			printf("Number is prime.");
	}
}