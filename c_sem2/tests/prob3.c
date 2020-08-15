#include<stdio.h>
#include<math.h>

int main()
{
	double x=45,y1=0,y2=0,y3=0,a,b,temp=0,e=10;
	a=-1.105656895;
	b=0.06980194;
	printf("\nDay\t\tExp. tot case\tDay Increase");
	y1=a+b*x;
	y1=pow(10,y1);
	temp=y1;
	while(x<=92)
	{
		//y1=2209989000 + (139.1339 - 2209989000)/(1+pow((x/190.4012),12.60183));
		//y1=610997400+(361.3028-610997400)/(1+pow((x/242.7446),45.31191));
		y1=a+b*x;
		y1=pow(10,y1);
		//y2=1025.692 + (47.99802-1025.692)/(1+pow((x/64.58875),26.14636));
		printf("\n%2.0f\t\t%.0lf\t\t",x,y1);
		temp=y1;
		//printf("\nExpected on the day: %lf",y2);
		//printf("\nExpected total death: %lf",y3);
		x++;
	}
	return 0;
}