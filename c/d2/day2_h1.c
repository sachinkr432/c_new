#include<stdio.h>
#include<math.h>

int main(void)
{
	float p;
	int r,t;
	printf("Enter principle,rate,time ");
	scanf("%f %d %d",&p,&r,&t);
	float si,ciy,cihy,ciqy,cim,cid;
	si = p*r*t/100;
	ciy = p*pow(1+r/100.0,t) - p;
	cihy = p*pow(1+r/200.0,2*t) - p;
	ciqy = p*pow(1+r/400.0,4*t) - p;
	cim = p*pow(1+r/1200.0,12*t) - p;
	cid = p*pow(1+r/36500.0,365*t) - p;

	printf("SI is %f\n",si );
	printf("CI Y is %f\n",ciy );
	printf("CI HY is %f\n",cihy );
	printf("CI QY is %f\n",ciqy );
	printf("CI M is %f\n",cim );
	printf("CI D is %f\n",cid );

	return 0;
}