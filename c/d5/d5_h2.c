#include<stdio.h>

int main()
{
	int i,j,k,l,lim;
	printf("Enter value of l: ");
	scanf("%d",&lim);
	for(i=1;i<=lim/3;i++)
		for(j=i+1;j<=lim/2;j++)
			for(k=j+1;k<=lim;k++)
				for(l=k+1;l<=lim;l++)
					if(i+j+k==l)
					{
						printf("\n%d %d %d %d",i,j,k,l);
						break;
					}
}