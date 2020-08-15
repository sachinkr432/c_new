#include <stdio.h>
#include <stdlib.h>

#define N 100

char* concat(char *a, char *b);
int strcmpr(char *a, char *b);
char* strrevrs(char *str);

//PLEASE USE ONE FUNCTIONALITY AT A TIME AS ALL ARE NOT INDEPENDENT AND USES SAME VARIABLE FOR DIFFERENT FUNCTION
//LINES IN MAIN ARE COMPLETELY OPTIONAL
int main()
{
	char *str1, *str2;
	str1 = (char*)malloc(sizeof(char)*N);
	str2 = (char*)malloc(sizeof(char)*N);

	char *cat;

	printf("Enter String 1: ");
	gets(str1);
	printf("Enter string 2: ");
	gets(str2);

	if (strcmpr(str1,str2))
		printf("Both string are not Same.\n");
	else
		printf("Both String Same\n");

	printf("Concatenated String is %s\n", concat(str1,str2));

	char *rev1, *rev2;
	rev1 = strrevrs(str1);
	rev2 = strrevrs(str2);
	printf("Reverse of \nString 1 is: %s\nString 2 is: %s\n",rev1,rev2);

	free(str1);
	free(str2);
	return 0;
}

char* concat(char *a, char *b)
{
	char *ret=a;
	while(*a!='\0')
		a++;
	while(*b!='\0')
		*a++ = *b++;
	*a='\0';
	return ret;
}

int strcmpr(char *a, char *b)
{
	while(*a==*b)
	{
		if (*a=='\0' && *b=='\0')
			return 0;
		a++;
		b++;
	}
	return (*a-*b);
}

char* strrevrs(char *str)
{
	char *rev=str,temp,*rem=str;
	while(*rev!='\0')
		rev++;
	rev--;
	while(str<rev)
	{
		temp=*str;
		*str=*rev;
		*rev=temp;
		str++;
		rev--;

	}
	return rem;
}