#include<stdio.h>

int main()
{
	int i,j,rad,count=0;
	printf("Please Enter radius: ");
	scanf("%d",&rad);
	for(i=rad,j=0;i>=0;i--)
	{
		for(;i*i+j*j<=rad*rad;j++)
		{
			if(i*i+j*j==rad*rad)
				if(i==0)
				{
					count+=2;
					printf("\n%d,%d",0,j);
					printf("\n%d,%d",0,-j);
				}
				else if(j==0)
				{
					count+=2;
					printf("\n%d,%d",i,0);
					printf("\n%d,%d",-i,0);
				}
				else
				{
					count+=4;
					printf("\n%d,%d",i,j);
					printf("\n%d,%d",-i,j);
					printf("\n%d,%d",-i,-j);
					printf("\n%d,%d",i,-j);
				}
		}
	}
	printf("\nTotal integer coordinates: %d",count);
	return 0;
}