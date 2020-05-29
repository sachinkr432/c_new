#include<stdio.h>
#include<stdlib.h>
char* encode(char *p,int n1,int n2,int r);
int main()
{
	int n1,n2,r;
	char p1[100];
	printf("Enter the string\n");
	gets(p1);
	char *p=p1;
	printf("Enter the lower and upper limit in ascii value\n");
	scanf("%d%d",&n1,&n2);
	printf("Enter random variable\n");
	scanf("%d",&r);
	encode(p,n1,n2,r);
	printf("%s",p);
	return 0;
}
char* encode(char *p,int n1,int n2,int r)
{
	int i=0,a[100];
	while(p[i]!='\0')
	{
		a[i]=(int)p[i];
		i++;
	}
	a[i]=0;
	for(i=0;a[i]!=0;i++)
	{
		a[i]=a[i]+r;
		if(a[i]>n2)
			a[i]=((a[i]-n1)%(n2-n1+1))+n1;
	}
	for(i=0;a[i]!=0;i++)
	{
		*p=(char)a[i];
		p++;
	}
	return p;
}
