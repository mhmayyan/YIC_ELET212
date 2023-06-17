/*
https://www.rapidtables.com/code/text/ascii-table.html
https://www.geeksforgeeks.org/isalpha-isdigit-functions-c-example/?ref=rp


*/

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
#include <ctype.h>

int main()
{
	char stringArray[] =
	"A microcontroller is a compact integrated circuit "
	"designed to govern a specific operation in an "
	"embedded system. A typical microcontroller includes "
	"a processor, memory and input/output (I/O) peripherals "
	"on a single chip.\n\nSometimes referred to as an "
	"embedded controller or microcontroller unit (MCU), "
	"microcontrollers are found in vehicles, robots, "
	"office machines, medical devices, mobile radio "
	"transceivers, vending machines and home appliances"
	", among other devices. They are essentially simple "
	"miniature personal computers (PCs) designed to "
	"control small features of a larger component, "
	"without a complex front-end operating system (OS).\n\n"
	"The first single-chip microprocessor was the Intel 4004, "
	"released on a single MOS LSI chip in 1971. It was "
	"developed by Federico Faggin, using his silicon-gate "
	"MOS technology, along with Intel engineers Marcian Hoff "
	"and Stan Mazor, and Busicom engineer Masatoshi Shima.";

	printf(
		"The size of the string array string[] is "
		"%llu bytes. "
		"It contains the following text:\n\n\n"
		"%s\n",
		sizeof(stringArray),
		stringArray
		);

	/*
	Find the first period that comes after a digit
	and print the whole number.
	*/
	char myChar;
	for (int ind = 0; ind < (int)strlen(stringArray); ind++)
	{
		myChar = stringArray[ind];
		if(	myChar == '.'
			&& isdigit(stringArray[ind-1])
		)
		{
		    /* scan backwards */
			int bck; /* define outside to keep */
			for (bck = ind-2; bck > 0; bck--)
			{
			    myChar = stringArray[bck];
				if (isdigit(myChar))
					continue;
				break;
			}
			bck++; /* set it to the index of the first digit*/
			printf("\n\nThe number starts at "
			"index %d. The number is ", bck);
			for (; bck <= ind; bck++)
			{
				putchar(stringArray[bck]);
				// printf("%c", stringArray[bck]);
			}
			break;
		}
	}
	printf("\n\n");

	return 0;
}
