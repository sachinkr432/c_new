#include<stdio.h>
#include<ctype.h>
int main()
{
	int n,i=0;
	char p1[100],ch;
	printf("enter the string\n");
	gets(p1);
	char *p=p1;
	printf("1.change to upper case\n2.change to lower case\n");
	scanf("%d",&n);
	if(n==1)
	{
		while(p[i]!='\0')
		{
			p[i]=toupper(p[i]);
			i++;
		}
		printf("%s",p);
	}
	else if(n==2)
	{
		while(p[i]!='\0')
		{
			p[i]=tolower(p[i]);
			i++;
		}
		printf("%s",p);
	}
	else
		printf("Invalid Choice. Terminated\n");
	return 0;
}
