/*
	By Mohammad Mayyan
	June 14, 2023

	Function:
	Print a variable of size one byte in binary 

	gcc -Wall -Wextra 04_printBinary1Byte.c -o 04_printBinary1Byte
*/



#include    <stdio.h>

void printBinary(unsigned char givenNum)
{
	/* print bits from MSB to LSB */
	for(int  indx = 8-1; indx >=0; indx--)
	{
		/****************************************************
		unsigned char index_Of_Bit_To_Print = 1<<indx;
		// mask other bits to zero 
		index_Of_Bit_To_Print = index_Of_Bit_To_Print & givenNum;
		if (index_Of_Bit_To_Print)
		{
			printf("'1");
		} else 
		{
			printf("'0");
		}
		****************************************************/
		printf("%c",givenNum&(1<<indx)?'1':'0');
	}
	printf("\n");
}


int    main( void )
{
	unsigned char var = 0;
	/*****************************/
	/* loop forever */
	while(1)
	{
		printf("Enter a character to print in binary then hit the \"Enter\" key \n");
		scanf("%c", &var);

		printBinary(var);

	}
	return 0;
}


