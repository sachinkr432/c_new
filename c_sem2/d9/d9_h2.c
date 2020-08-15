#include<stdio.h>
char* count(char *p);
int main()
{
	char p1[100];
	int *a;
	printf("enter the string\n");
	gets(p1);
	char *p=p1;
	count(p);
	printf("%s",p);
	return 0;
}
char* count(char *p)
{
	int a[3];
	a[0]=0;a[1]=0;a[2]=0;
	while(*p !='\0')
	{
		if(*p=='\t')
		{
			a[0]++;
			*p='T';
		}
		if(*p==' ')
		{
			a[1]++;
		}
		if(*p=='\n')
		{
			a[2]++;
			*p='N';
		}
		p++;		
	}
	printf("tabs=%d,space=%d,new line=%d\n",a[0],a[1],a[2]);
	return p;
}
