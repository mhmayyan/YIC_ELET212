/*
 * gcc -Wall -Wextra 04_printBinary4Bytes.c -o 04_printBinary4Bytes
*/

#include <stdio.h>
#include <limits.h>


int main()
{
	const unsigned int givenNum = 1311345372; /*0x4E298ADC*/
	const unsigned char numberOfBitsIn2Bytes = sizeof(unsigned int)*8;

	for(int  number = numberOfBitsIn2Bytes-1; number >=0; number--)
	{
		printf("%c",givenNum&(1<<number)?'1':'0');
	}
	printf("\n");

	return 0;
}