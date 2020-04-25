#include<stdio.h>

int main()
{
	int num,temp1,temp2=0,sum=0,i=0;
	printf("Enter number: ");
	scanf("%d",&num);
	temp1 = num;
	while(temp1)
	{
		temp2 = (temp2*10)+(temp1%10);
		sum += temp1%10;
		temp1 /= 10;
		i++;
	}
	if(temp2==num)
		printf("\nThe number is palidrome.");
	else
		printf("\nThe number is not palidrome.");
	printf("\nNumber of digits= %d",i);
	printf("\nSum of digits= %d",sum);

	return 0;
}