#include<stdio.h>
int sum(int,int);
int main ()
{
	int n,s=0;
	printf("enter a no.");
	scanf("%d",&n);
	printf("the sum of digits of the number is %d",sum(n,s));
	return 0;
}
int sum(int n,int s)
{
	int a;
	if(n!=0)
	{
		a=n%10;
		return sum(n/10,s+a);
	}
	else
		return s;
}
