#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	char name[10];
	int roll;
	int physics;
	int chemistry;
	int mathematics;
	int total;
}s;
void total(s *p,int n);
void sort(s *p,int n);
int main()

{
	int i,n;
	printf("enter no. of students\n");
	scanf("%d",&n);
	getchar();
	s *pt=(s *)malloc(n*sizeof(s));
	for(i=0;i<n;i++)
	{
		printf("enter name:");
		gets(pt[i].name);
		printf("enter roll:");
		scanf("%d",&pt[i].roll);
		printf("enter marks in physics:");
		scanf("%d",&pt[i].physics);
		printf("enter marks in chemistry:");
		scanf("%d",&pt[i].chemistry);
		printf("enter marks in mathematics:");
		scanf("%d",&pt[i].mathematics);
		printf("--------------------------\n");
		getchar();
	}
	total(pt,n);
	sort(pt,n);
	printf("ROLL	NAME	MARKS\n");
	for(i=0;i<n;i++)
		printf("%d	%s	%d\n",pt[i].roll,pt[i].name,pt[i].total);
	free(pt);	
	return 0;
}
void total(s *p,int n)
{
	int i;
	for(i=0;i<n;i++)
		p[i].total=p[i].physics+p[i].chemistry+p[i].mathematics;
}
void sort(s *p,int n)
{
	int i,j;
	s t;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(p[j].total<p[j+1].total)
			{
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;
			}
}
