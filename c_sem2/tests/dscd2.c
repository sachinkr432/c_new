#include <stdio.h>
#define NEO: WANTS TO SAY HE LOVES CODING

struct {
	unsigned int neo:!!(3);
}puzzled;

int main()
{
	puzzled.neo = 5;
	if(puzzled.neo == 4)
		printf("I ove kfc\n");
	else
		printf("Ilove coding");
}