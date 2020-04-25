#include<stdio.h>
#define SIZE 50

int strlen(char str[]);
int strcmp(char str1[], char str2[]);
void strcpy(char str1[], char str2[]);
void strrev(char str1[], char str2[]);
void strcat(char str1[], char str2[]);

int main()
{
	char str1[SIZE],str2[SIZE];
	int i=0;
	printf("Enter strings:\n1: ");
	do
	{
		scanf("%c",&str1[i]);
	}while(str1[i++]!='\n');
	str1[i-1]='\0';

	// i=0;
	// printf("2: ");
	// do
	// {
		// scanf("%c",&str2[i]);
	// }while(str2[i++]!='\n');
	// str2[i-1]='\0';

	// printf("\nNo. of char: in 1: %d\t2: %d\n",strlen(str1),strlen(str2));

	// if(strcmp(str1,str2))
		// printf("Strings are not same\n");
	// else
		// printf("Strings are same\n");

	// strcpy(str1,str2);

	// strrev(str1,str2);

	// strcat(str1,str2);

	for (i = 0; str1[i]!='\0'; ++i)
	{
		printf("%c",str1[i] );
	}
	return 0;
}

int strlen(char str[])
{
	int i;
	for(i=0;str[i]!='\0';++i);
	return i;
}

int strcmp(char str1[], char str2[])
{
	int i;
	for (int i = 0; str1[i]!='\0' || str2[i]!='\0'; ++i)
	{
		if(str1[i]-str2[i])
			return str1[i]-str2[i];
	}
	return 0;
}

void strcpy(char str1[], char str2[])
{
	int i;
	for (i = 0; str1[i]!='\0'; ++i)
		str2[i]=str1[i];
	str2[i]='\0';
}

void strrev(char str1[], char str2[])
{
	int i,len;
	len = strlen(str1);
	for (i = 0; i < len; ++i)
		str2[i]=str1[len-i-1];
	str2[i]='\0';
}

void strcat(char str1[], char str2[])
{
	int i,len;
	len = strlen(str1);
	for (i = 0; str2[i]!='\0'; ++i,++len)
		str1[len]=str2[i];
	str1[len]='\0';
}