#include<stdio.h>
#include<math.h>
#define SIZE 32

double avg(int arr[],int sz);

int main()
{
	int i;
	int x[SIZE];
	for(i=0;i<SIZE;i++)
		x[i]=i+35;

	int y[SIZE]={28,30,31,34,39,48,63,70,82,91,107,113,127,146,171,199,258,334,403,505,571,657,735,886,1029,1139,1347,1635,2059,2545,3108,3501};
	for(i=0;i<SIZE;i++)
			y[i]=log10(y[i]);
	float x_avg,y_avg;
	x_avg=avg(x,SIZE);
	y_avg=avg(y,SIZE);
	double alpha,beta;
	float num=0,den=0;
	for(i=0;i<SIZE;i++)
		num+=(x[i]-x_avg)*(y[i]-y_avg);
	for(i=0;i<SIZE;i++)
		den+=(x[i]-x_avg)*(x[i]-x_avg);
	beta=num/den;
	alpha=y_avg-beta*x_avg;
	alpha=pow(10,alpha);
	printf("Function is: a = %lf  , b = %lf ",alpha,beta);
	return 0;
}

double avg(int arr[],int sz)
{
	int i;
	double sum=0;
	for(i=0;i<sz;i++)
		sum+=arr[i];
	return sum/sz;
}