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
		if(var<=30) /*shifting*/
		{
			/* turn off all LEDs */
			if(var%5==0)
			{
				bitsState = 0xff;
			}
			/* shift left */
			else if (
				(var>0 && var<5)
				|| (var>10 && var<15)
				|| (var>20 && var<25)
			)
			{
			    if(var%5 == 1) /* in case of 1, 11, and 21 */
				{
					bitsState = 0xfe;
				}
				else
				{
					bitsState <<= 1;
                    bitsState |= 0xF1;
				}
			}
			/* shift right */
			else
			{
				if(var%5 == 1) /* in case of 6, 16, and 26 */
				{
					bitsState = 0xf7;
				}
				else
				{
					bitsState >>= 1;
                    bitsState |= 0xF0;
				}
			}
		}
        else
        {
            if(var&0x01) /* in case of odd number, i.e., 31, 33, and 35 */
            {
                bitsState = 0xf0;
            }
            else
            {
                bitsState = 0xff;
            }

        }

		var++;
		var = var>35?0:var;

        

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


