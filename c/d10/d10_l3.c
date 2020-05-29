#include<stdio.h>
int rev(int,int);
int main()
{
	int n,a=0;
	printf("enter a no.\n");
	scanf("%d",&n);
	printf("the reversed no. is %d",rev(n,a));
	return 0;
}
int rev(int n,int a)
{
	if(n!=0)
		return rev((n/10),((a*10)+(n%10)));
	else
		return a;
}
