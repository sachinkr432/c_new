#include<stdio.h>
int count(char *p);
int main()
{
	char p1[100];
	printf("enter the string\n");
	gets(p1);
	char *p=p1;
	count(p);
	return 0;
}
int count(char *p)
{
	int a[2];
	a[0]=0;a[1]=0;
	while(*p !='\0')
	{
		if((*p=='a')||(*p=='e')||(*p=='i')||(*p=='o')||(*p=='u')||(*p=='A')||(*p=='E')||(*p=='I')||(*p=='O')||(*p=='U'))
		{
			a[0]++;
		}
		if((*p>=48)&&(*p<=57))
			a[1]++;
		p++;
	}
	printf("vowels=%d,digits=%d\n",a[0],a[1]);
}
