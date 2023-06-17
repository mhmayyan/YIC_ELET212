/*
	By Mohammad Mayyan
	June 14, 2023

	Function:
		Shift LEDs left then right repeatedly three times then
		blink all LEDs three times. Repeat this pattern.
		Use switch P14 to control the delay time.
		0b11111111	0
		0b11111110	1
		0b11111101	2
		0b11111011	3
		0b11110111	4
		0b11111111	5
		0b11110111	6
		0b11111011	7
		0b11111101	8
		0b11111110	9
		0b11111111	10

		0b11110000	31
		0b11111111	32

		var values
		(0,5,10,15,20,25,30) = LEDs are off
		(1-4,11-14,21-24) shift left
		(6-9,16-19,26-29) shift right
		(31-36) blinking
		37 --> reset var to 0

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
		switch(var)
		{
			/* turn off LEDs */
			case 0:
			case 5:
			case 10:
			case 15:
			case 20:
			case 25:
			case 30:
			{
				bitsState = 0xFF;
				break;
			}
			/* shift left */
			case 1:
			case 2:
			case 3:
			case 4:
			case 11:
			case 12:
			case 13:
			case 14:
			case 21:
			case 22:
			case 23:
			case 24:
			{
				switch(var)
				{
					case 1:
					case 11:
					case 21:
					{
						bitsState = 0xFE;
						break;
					}
					case 2:
					case 12:
					case 22:
					{
						bitsState = (unsigned char)(0xFE<<1) | 0x01;
						break;
					}
					case 3:
					case 13:
					case 23:
					{
						bitsState = (unsigned char)(0xFE<<2) | 0x03;
						break;
					}
					case 4:
					case 14:
					case 24:
					{
						bitsState = (unsigned char)(0xFE<<3) | 0x07;
						break;
					}
					default:
					break;
				}
				break;
			}
			/* shift right */
			case 6:
			case 7:
			case 8:
			case 9:
			case 16:
			case 17:
			case 18:
			case 19:
			case 26:
			case 27:
			case 28:
			case 29:
			{
				switch(var)
				{
					case 6:
					case 16:
					case 26:
					{
						bitsState = (unsigned char)(0xFE<<3) | 0x07;
						break;
					}
					case 7:
					case 17:
					case 27:
					{
						bitsState = (unsigned char)(0xFE<<2) | 0x03;
						break;
					}
					case 8:
					case 18:
					case 28:
					{
						bitsState = (unsigned char)(0xFE<<1) | 0x01;
						break;
					}
					case 9:
					case 19:
					case 29:
					{
						bitsState = 0xFE;
						break;
					}
					default:
					break;
				}
				break;
			}
			/* blinking */
			case 31:
			case 33:
			case 35:
			{
				bitsState = 0xF0;
				break;
			}
			case 32:
			case 34:
			//case 36:
			{
				bitsState = 0xFF;
				break;
			}
			default:
				bitsState = 0xFF;
				var = 0;
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


