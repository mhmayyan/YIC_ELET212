/*
	gcc -Wall -Wextra 03_addTwoIntegers.c -o 03_addTwoIntegers
	
	By Mohammad Mayyan
	June 14, 2023

	Function:
*/

#include <stdio.h>

int main()
{
	int a, b, c;
	printf("Enter two numbers to add\n");
	scanf("%d%d",&a,&b);
	c = a + b;
	printf("Sum of entered numbers = %d\n",c);
	return 0;
}