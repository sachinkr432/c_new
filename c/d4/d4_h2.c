#include<stdio.h>

int main()
{
	int i,num,temp=1,fact=1;
	printf("Please enter number: ");
	scanf("%d",&num);
	for(i=2;i<=num;i++)
	{
		if(fact/temp+1==i)
		{
			temp = fact;
			fact *= i;

		}
		else
			break;
	}
	if(i-1==num)
		printf("Factorial is: %d",fact);
	else
		printf("Overflow caught at num %d = %d",i-1,fact);

	return 0;
}