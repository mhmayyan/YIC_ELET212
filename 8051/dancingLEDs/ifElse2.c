/*
	By Mohammad Mayyan
	June 14, 2023

	Function:
		Shift LEDs left then right repeatedly three times then
		blink all LEDs three times. Repeat this pattern.
		Use switch P14 to control the delay time.

11111111
11111110
11111101
11111011
11110111
11111111
11110111
11111011
11111101
11111110
11111111
11111110
11111101
11111011
11110111
11111111
11110111
11111011
11111101
11111110
11111111
11111110
11111101
11111011
11110111
11111111
11110111
11111011
11111101
11111110
11111111
11110000
11111111
11110000
11111111
11110000
11111111

*/

// https://iq.opengenus.org/detect-operating-system-in-c/

#if defined(_WIN32) || defined(__linux__)
#include    <stdio.h>
	void printBinary(unsigned char givenNum)
	{
		for(int  number = 8-1; number >=0; number--)
		{
			printf("%c",givenNum&(1<<number)?'1':'0');
		}
		printf("\n");
	}
#else
#include    <WIN51.H>
#define     SELECT     (*( unsigned char *)(0x2fC48))
#endif


#if !(defined(_WIN32) || defined(__linux__) )
	sbit P14 = P1^4; /* input switch for delay time */
#endif



unsigned char var = 0;
unsigned char bitsState = 0xFF;

void    delay( unsigned long  del )
{
    while(del) del--; // del = del -1;
}

int    main( void )
{
	/* startup settings */
#if !(defined(_WIN32) || defined(__linux__) )
	SELECT = 0x9e;
	P1 = 255;  /* to turn off all LEDs and  to assure correct reading of the pin logical status when reading switches */
#endif

	/*****************************/
	/* loop forever */
	while(1)
	{
		/* shift right */
		if(var<6 && !(var&0x01))
		{
			if(bitsState == 0xFF)
			{
				bitsState = 0xF7;
			} 
			else
			{
				bitsState >>= 1;
				bitsState |= 0xF0;
			}
			if(bitsState == 0xFF)
			{
				var++;
			}
		}
		/* shift left */
		else if(var<6 && (var&0x01))
		{
			if(bitsState == 0xFF)
			{
				bitsState = 0xFE;
			} 
			else
			{
				bitsState <<= 1;
				bitsState |= 0xF1;
			}
			if(bitsState == 0xFF)
			{
				var++; 
			}
		}
		/* blink */
		else if(var >= 6)
		{
			if(bitsState == 0xFF)
			{
				bitsState = 0xF0;
			} 
			else
			{
				bitsState = 0xFF;
			}
			var++;
			if(var == 0x06+0x06)
			{
				var = 0; /* start over */
				bitsState = 0xFF;
			}
		} 

		/******************************************/
#if defined(_WIN32) || defined(__linux__)
		printBinary(bitsState);
#else
		P1 = bitsState;
		/* check switch P14 for the delay time */
		if(P14)
		{
			delay(5000);
		}
		else
		{
			delay(20000);
		}
#endif


	}
}


