/*
	gcc -Wall -Wextra 05_arrayStringLoop.c -o 05_arrayStringLoop

	By Mohammad Mayyan
	June 14, 2023

	Function:

*/

#include <stdio.h>

int main()
{
	char array[] = {'H', 101, 108, 'l', 'o', 32, 'W', 'o', 'r', 'l', 'd', '!', 0};
	char string[] = "Hello World!";
	printf("array[%llu] = %s\n", sizeof(array), array);
	printf("string[%llu] = %s\n", sizeof(string), string);

	printf("string[%llu] = ", sizeof(string));
	unsigned long long ind;
	for (ind = 0; ind < sizeof(string); ind++)
	{
		unsigned char myChar = string[ind];
		printf("%c", myChar);
	}
	printf("\n");
	return 0;
}