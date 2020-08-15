#include<stdio.h>

int main()
{
	int num,temp,numsq,rev,revsq;
	for(num=10;num<=100;num++)
	{
		if(num%10<num/10)
			continue;
		rev=0;
		numsq=num*num;
		temp=num;
		while(temp)
		{
			rev*=10;
			rev+=temp%10;
			temp/=10;
		}
		temp=numsq;
		revsq=0;
		while(temp)
		{
			revsq*=10;
			revsq+=temp%10;
			temp/=10;
		}
		if(rev*rev==revsq)
			printf("\n%d , %d",num,rev);
	}
	return 0;
}