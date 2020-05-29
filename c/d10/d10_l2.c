#include<stdio.h>
int fib(int a,int b,int n);
int print(int,int);
int main()
{
	int i=1,n,f;
	printf("enter no. of terms to be printed\n");
	scanf("%d",&n);
	if(n<=0)
	printf("invalid input");
	else
		print(i,n);
	return 0;
}
int fib(int a,int b,int n)
{
	if(n==1)
		return a;
	if(n==2)
		return b;
	else
		return fib(b,a+b,n-1);
}
int print(int i,int n)
{
	if(fib(0,1,i)<0)
		printf("overflow\n");
	else
	{
		printf("%d\t",fib(0,1,i));
		i+=1;
		if(i<=n)
		return print(i,n);
	}
}
