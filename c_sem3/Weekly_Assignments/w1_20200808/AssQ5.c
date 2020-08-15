//#SACHIN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compNo
{
	int re;
	int im;
};

void plusComplex(struct compNo num1, struct compNo num2);
void minusComplex(struct compNo num1, struct compNo num2);
void multiplyComplex(struct compNo num1, struct compNo num2);

int main()
{
	float time_in_sec;
	clock_t start, end;
	start = clock();

	struct compNo num1, num2;

		printf("\nEnter 'a' and 'b' where a+ib is 1st complex Number: ");
		scanf("%d%d", &num1.re, &num1.im);
		printf("\nEnter 'c' and 'd' where c+id is 2nt complex Number: ");
		scanf("%d%d", &num2.re, &num2.im);
		printf("\nEnter choice:\n 1. Add\n 2.Subtract\n 3. Multiply\t");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: plusComplex(num1, num2);
					break;
			case 2: minusComplex(num1, num2);
					break;
			case 3: multiplyComplex(num1, num2);
					break;
			default: printf("Undefined choice!!\n");
		}


	end = clock();
	time_in_sec = (float)(end-start)/CLOCKS_PER_SEC;
	printf("\nThe execution time is %f",time_in_sec);
	return 0;
}

void plusComplex(struct compNo num1, struct compNo num2)
{
	printf("Number after addition is: \nRe: %d\nIm: %d", num1.re + num2.re, num1.im + num2.im);
}

void minusComplex(struct compNo num1, struct compNo num2)
{
	printf("Number after subtraction is: \nRe: %d\nIm: %d", num1.re - num2.re, num1.im - num2.im);
}

void multiplyComplex(struct compNo num1, struct compNo num2)
{
	int real, imaginary;
	real = (num1.re * num2.re) - (num1.im * num2.im);
	imaginary = (num1.re * num2.im) + (num1.im * num2.re);
	printf("Number after multiplication is: \nRe: %d\nIm: %d", real, imaginary);
}
