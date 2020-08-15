#include<stdio.h>
int gcd(int,int);
int main()
{
	int a,b;
	printf("enter two no.\n");
	scanf("%d%d",&a,&b);
	if(a<=0||b<=0)
	printf("Invalid input\n");
	else
	printf("the HCF of the two nos. is %d",gcd(a,b));
	return 0;
}
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
