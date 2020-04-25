#include<stdio.h>
int entry_check(int n, int b);
int to_decimal(int n,int b);
int fr_decimal(int n,int b);



int main()
{
	int num,base,ch;
	do
	{
		printf("Enter number(>=0) and base(2,8,10): ");
		scanf("%d%d",&num,&base);
	} while (entry_check(num,base));
	printf("Conversions are: \n");
	num = to_decimal(num,base);
	switch(base)
	{
		case 2: do
				{
					printf("1.to Octal\n2. to Decimal\nEnter your choice: ");
					scanf("%d",&ch);
				}while(ch!=1 && ch!=2);
				if(ch==1)
					num = fr_decimal(num,8);
				break;
		case 8: do 
				{
					printf("1.to Binary\n2. to Decimal\nEnter your choice: ");
					scanf("%d",&ch);
				}while(ch!=1 && ch!=2);
				if(ch==1)
					num = fr_decimal(num,2);
				break;
		case 10: do 
				{		
					printf("1.to Binary\n2. to Octal\nEnter your choice: ");
					scanf("%d",&ch);
				}while(ch!=1 && ch!=2);
				if(ch==1)
					num = fr_decimal(num,2);
				if(ch==2)
					num = fr_decimal(num,8);
				break;
	}

	printf("\nYour result is %d\n",num);
	return 0;
}

int entry_check(int n,int b)
{
	if(n<0)
	{
		printf("\nEnter a valid number\n");
		return 1;
	}
	if(b!=2 && b!=8 && b!=10)
	{
		printf("\nEnter a valid base\n");
		return 1;
	}
	while(n)
	{
		if(n%10>=b)
		{
			printf("\nEnter a valid number\n");
			return 1;
		}
		n/=10;
	}
	return 0;
}

int to_decimal(int n, int b)
{
	int i=1,temp=0;
	while(n)
	{
		temp += ((n%10)*i);
		i*=b;
		n/=10;
	}
	return temp;
}

int fr_decimal(int n, int b)
{
	int i=1,temp=0;
	while(n)
	{
		temp += (n%b)*i;
		n/=b;
		i*=10;
	}
	return temp;
}