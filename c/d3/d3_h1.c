#include<stdio.h>
#include<math.h>

int main()
{
	int a,b,c;
	printf("Enter values of a,b,c: ");
	scanf("%d%d%d",&a,&b,&c);

	int d;
	d = b*b-4*a*c;
	if (d<0)
	{
		printf("Roots are imaginary\n");
		printf("x1= %f+%fi\n",-0.5*b/a,0.5*sqrt(-d)/a);
		printf("x2= %f%fi",-0.5*b/a,-0.5*sqrt(-d)/a);
	}
	else
	{
		printf("Roots are real\n");
		printf("x1= %f\n",(-0.5*b+0.5*sqrt(d))/a);
		printf("x2= %f",(-0.5*b-0.5*sqrt(d))/a);
	}
}