#include <stdio.h>

int main()
{
	char ch;
	for (int i = 0; i < 240; ++i)
	{
		ch=i;
		printf("%d  %c\n",i,  ch);
	}
	printf("\n\n\n");
	printf("%c %c\n", ch, ch+88);
	return 0;
}