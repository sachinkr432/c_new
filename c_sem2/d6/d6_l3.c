#include<stdio.h>

void wbw(int n1,int n2);
void wobw(int n1, int n2);

int main()
{
	int num1,num2,ch;
	do
	{
		printf("Enter two numbers(>=0) seperated by space: ");
		scanf("%d%d",&num1,&num2);
	}while(num1<0||num2<0);
	printf("1. using Bitwise, or 2. without using Bitwise: ");
	scanf("%d",&ch);
	if(ch==1)
		wbw(num1,num2);
	else if(ch==2)
		wobw(num1,num2);
	else
		printf("Invalid choice\n");
	return 0;
}

void wbw(int n1, int n2)
{
	int count=0,n=n1^n2;
	while(n)
	{
		if(n%2)
			count++;
		n/=2;
	}
	printf("No. of bits to alter(1): %d",count);
}

void wobw(int n1, int n2)
{
	int count=0;
	while(n1||n2)
	{
		if(n1%2!=n2%2)
			count++;
		n1/=2;
		n2/=2;
	}
	printf("No. of bits to alter(2): %d",count);
}