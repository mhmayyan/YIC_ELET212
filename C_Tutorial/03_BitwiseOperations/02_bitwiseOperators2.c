/*
	By Mohammad Mayyan
	June 14, 2023

 * gcc -Wall -Wextra bitwiseOperators2.c -o bitwiseOperators2
*/
#include <stdio.h>
#include <stdint.h> // for uint8_t

int main()
{
   
	uint8_t var = 0b00111100; // 0x3C
	/********************************************/
	// CLEAR BIT NUMBER 4 AND 6 OF THE VARIABLE VAR
	// The three following lines are equivalent.
	var = var & 0b11010111;
	printf("%u\n", var);
	var = 0b00111100;
	var &= 0b11010111;
	printf("%u\n", var);
	var = 0b00111100;
	var &= ~(1<<5 | 1<<3);
	printf("%u\n", var);
	/********************************************/
	// SET BIT NUMBER 4 AND 6 OF THE VARIABLE VAR
	// The three following lines are equivalent.
	var = 0b00111100;
	var = var | 0b00101000;
	printf("%u\n", var);
	var = 0b00111100;
	var |= 0b00101000;
	printf("%u\n", var);
	var = 0b00111100;
	var |= 1<<5 | 1<<3;
	printf("%u\n", var);
	/********************************************/
	// TOGGLE BIT NUMBER 4 AND 6 OF THE VARIABLE VAR
	// The three following lines are equivalent.
	var = 0b00111100;
	var = var ^ 0b00101000;
	printf("%u\n", var);
	var = 0b00111100;
	var ^= 0b00101000;
	printf("%u\n", var);
	var = 0b00111100;
	var ^= 1<<5 | 1<<3;
	printf("%u\n", var);



   return 0;

}
