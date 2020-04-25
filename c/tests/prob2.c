#include<stdio.h>

#define COUNT 100

int main()
{
	char arr[COUNT];
	int i=0;
	arr[0]=1;
	do
	{
		scanf("%c",&arr[i]);
	} while (arr[i++]!='\n');
	arr[i-1]='\0';
	for (i = 0;arr[i]!='\0'; ++i)
	{
		printf("%c",arr[i]);
	}
	scanf("%d",i);
	return 0;
}