#include<stdio.h>
int ncr(int,int);
int main()
{
	int n,r,s;
	printf("enter the values of n,r\n");
	scanf("%d%d",&n,&r);
	if(n<0||r<0)
		printf("invalid input");
	else
	{
		s=ncr(n,r);
		printf("%d",s);
	}
		return 0;	
}
int ncr(int n,int r)
{
	int i,j;
	if(r==0)
	{
		i=1;
		return i;
	}
	else if(n==r)
	{
		i=1;
		return i;
	}
	else
	{
		j=ncr(n-1,r-1)+ncr(n-1,r);
	}
	return j;
}
