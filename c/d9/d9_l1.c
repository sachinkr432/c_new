#include<stdio.h>
#include<stdlib.h>
int comp(char *p,char *q);
char* concat(char *p,char *q);
int palin(char *p,int len);
int slen(char *p);
int main()
{
	int s1,s2,i,ch,n;
	printf("enter the length of string 1 & string 2\n");
	scanf("%d%d",&s1,&s2);
	char p1[s1],q1[s2];
	printf("enter string 1\n");
	getchar();
	gets(p1);
	printf("enter string 2\n");
	gets(q1);
	char *p=p1;
	char *q=q1;
	printf("enter your choice\n1.compare\n2.concat\n3.palin\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case (1):
		n=comp(p,q);
		if(n==0)
			printf("both strings are same\n");
		else
			printf("return value=:%d\n",n);
		break;
		case 2:
		concat(p,q);
		printf("%s",p);
		break;
		case 3:
		n=palin(p,s1);
		if(n==1)
			printf("string 1 is a palindrome\nreturn value:%d",n);
		else
			printf("string 1 is  not a palindrome\nreturn value:%d",n);
		printf("\nOperation is not done on string 2\n");
		break;
		default:
		printf("invalid choice\n");
	}
	return 0;
}
int comp(char *p,char *q)
{
	while(*p==*q)
	{
		if(*p=='\0'||*q=='\0')
			break;
		p++;
		q++;
	}
	if(*p=='\0' && *q=='\0')
		return 0;
	else
		return (*p-*q);
}
char* concat(char *p,char *q)
{
	while(*p!='\0')
		p++;
	while(*q!='\0')
	{
		*p=*q;
		p++;
		q++;
	}
	*p='\0';
	return p;
}
int palin(char *p,int len)
{
	char *rev;
	rev=p;
	p+=(len-1);
	while(p>rev)
	{
		if(*p==*rev)
		{
			p--;
			rev++;
		}
		else
			break;
	}
	if(rev>p)
		return 1;
	else
		return 0;
}
