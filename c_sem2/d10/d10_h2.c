#include<stdio.h>
void convert(int dec);
int main()
{
	int dec=0;
	printf("enter a decimal no.\n");
	scanf("%d",&dec);
	convert(dec);
	return 0;
}
void convert(int dec)
{
	int hex=0;
	if(dec!=0)
	{
		hex=dec%16;
		convert(dec/16);
	}
	else
		return ;
	if(hex<9)
		printf("%d",hex);
	else
		printf("%c",'A'+(hex-10));	
}
