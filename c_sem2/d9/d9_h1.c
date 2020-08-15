#include<stdio.h>
char* encode(char *p,int n);
int main()
{
	int n;
	char p1[100];
	printf("enter the string\n");
	gets(p1);
	char *p=p1;
	printf("enter the no. to be added to the string:");
	scanf("%d",&n);
	encode(p,n);
	printf("%s",p);
	return 0;
}
char* encode(char *p,int n)
{
	while(*p!='\0')
	{
		*p=*p+n;
		p++;
	}
	return p;
}
