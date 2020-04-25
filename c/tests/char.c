#include <stdio.h>

int main()
{
	char ch;
	for (int i = 0; i < 256; ++i)
	{
		ch=i;
		printf("%d  %c\n",i,  ch);
	}
	return 0;
}