#include <stdio.h>

#define S1 1000
#define S2 10

void strcheck(char str[], char src[], int beg, int end);

int main()
{
	char str[S1]={"This is Sachin. Sachin is a good boy. Sachin has good knowledge of books. He study hard. Sachin is from Bihar."};
	char src[S2]={"Sachin"};
	printf("%s\n\n", str );
	for (int i = 0, j=0; str[i]!='\0'; ++i)
	{
		if (str[i]=='.' || str[i]=='?' || str[i]=='!')
		{
			strcheck( str, src, j, i);
			j=i+2;
		}
	}
	return 0;
}

void strcheck(char str[], char src[], int beg, int end)
{
	for (int j=beg,k; j < end; ++j)
		if (src[0]==str[j])
		{
			for(k=1,j++; src[k]==str[j]; k++,j++);
			if (src[k]=='\0')
			{				
				for (; beg <= end; ++beg)
					printf("%c", str[beg]);
				printf("\n");
				break;
			}
		}
	
}