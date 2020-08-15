#include<stdio.h>
#include<math.h>

int main()
{
	int a;
	do
	{
		printf("Enter your marks: ");
		scanf("%d",&a);
	}while(a<0 || a>100);

	printf("Your grade is: ");
	(a>90)	? printf("O")
			:(a>80)	? printf("E")
					:(a>70)	? printf("A")
							:(a>60)	? printf("B")
									:(a>50)	? printf("C")
											:(a>40)	? printf("D")
													: printf("FAIL");

	return 0;
}