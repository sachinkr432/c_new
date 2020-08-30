// created by SACHIN
// This program implements pow function using function recursion

#include <stdio.h>
#include <stdlib.h>

long power( int num, int pow);

int main()
{
	int num, pow;
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("Enter power: ");
	scanf("%d", &pow);
	printf("%d^%d = %ld", num, pow, power(num,pow));
	return 0;
}

long power( int num, int pow)
{
	if(pow != 1)
		if(pow%2)
			return power(num*num, pow/2) * num;
		else
			return power(num*num, pow/2);
	else
		return num;
}