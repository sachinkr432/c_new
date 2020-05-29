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
	int a[3],r=0;
	a[0]=0;a[1]=0;a[2]=0;
	while(*p !='\0')
	{
		if(((*p>64 && *p<91) || (*p>96 && *p<123)) && r==1)
			a[0]--;
		if((*p>64 && *p<91) || (*p>96 && *p<123))
		{
			r=1;
			a[0]++;
			a[1]++;
		}
		else
			r=0;
		if (*p=='.' || *p=='?' || *p=='!')
			a[2]++;

		p++;
	}
	printf("words=%d,characters=%d,lines=%d\n",a[0],a[1],a[2]);
}
