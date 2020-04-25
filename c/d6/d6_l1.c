#include<stdio.h>
#include<stdlib.h>

void fact(int num);
void prime(int n);
void palindrome(int num);
int input(void);

int main()
{
	int ch;
	printf("WELCOME\n");

	do 														//infinite loop for operating until it finds 'break;'
	{
		printf("1. Factorial\n2. Prime Check\n");
		printf("3. Palindrome Check\n4.Exit\nPlease make a choice: ");
		scanf("%d",&ch);
		if(ch==4)											//exits main loop if choice is 4(exit)
			break;

		switch(ch)
		{
			case 1: fact(input());
					break;
			case 2: prime(input());
					break;
			case 3: palindrome(input());
					break;
			default: printf("Enter a valid choice\n");
		}
	}while(1);
}

void fact(int num)
{
	int temp=1,fact=1,i;

	for(i=2;i<=num;i++)					//calculating factorial
	{
		if(fact/temp==i-1)				//if checking for overflow
		{
			temp=fact;
			fact*=i;
		}
		else
		{
			printf("Overflow caught at num=%d\n",i-1);
			break;
		}
	}
	if(i-1==num || num==0)
		printf("Factorial is: %d\n",fact);
}

void prime(int n)
{
	if (n%2 == 0)
		printf("Number is not prime.");
	else
	{
		int i=3;
		while(i*i<=n)
		{
			if(n%i==0)
			{	
				printf("Number is not prime.\n");
				break;	
			}
			else
				i+=2;
		}
		if(n<=i*i)
			printf("Number is prime.\n");
	}
}

void palindrome(int num)
{
	int temp1,temp2=0;
	temp1 = num;
	while(temp1)
	{
		temp2 = (temp2*10)+(temp1%10);
		temp1 /= 10;
	}
	if(temp2==num)
		printf("\nThe number is palidrome.\n");
	else
		printf("\nThe number is not palidrome.\n");
}

int input(void)
{
	int num;
	do 									//input data verification
	{
		printf("\nEnter num(>=0): ");
		scanf("%d",&num);
	}while(num<0);
	return num;
}