#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int currency[]={100,50,10,5,2,1};
	int num,not=0,i=0;
	printf("Enter the amount: ");
	scanf("%d",&num);
	while(num)
	{
		not += num/currency[i];
		num = num%currency[i++];
	}
	printf("Total nuber of currency is %d",not);
	//system("pause");
	return 0;
}