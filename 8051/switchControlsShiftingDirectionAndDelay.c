/*
	By Mohammad Mayyan
	June 14, 2023

	Function:
		Use switch P15 to control the shifting direction of the LEDs.
		Use switch P14 to control the delay time.
*/

#include    <WIN51.H>

#define     SELECT     (*( unsigned char *)(0x2fC48))
#define INITIAL_VALUE_4_RIGHT_SHIFTING 0xF7
#define INITIAL_VALUE_4_LEFT_SHIFTING 0xFE


sbit P14 = P1^4; /* input switch for delay time */
sbit P15 = P1^5; /* input switch for shifting direction */

unsigned char var;


void    delay( unsigned long  del )
{
    while(del) del--; // del = del -1;
}

void    main( void )
{
	/* startup settings */
	SELECT = 0x9e;
	P1 = 255;  /* to turn off all LEDs and  to assure correct reading of the pin logical status when reading switches */
	
	if(P15)
		var = INITIAL_VALUE_4_RIGHT_SHIFTING;
	else
		var = INITIAL_VALUE_4_LEFT_SHIFTING;
	/*****************************/
	/* loop forever */
	while(1)
	{
		P1 = var;
		/* check switch P15 for shifting direction */
		if(P15)
		{
			var >>= 1; /* shift right */
			var |= 0x80; /* mask the HSB to assure correct readings of switches P14-P17 */
			/* 
				start over when all LEDs are off
			*/
			if(var == 0xFF ) 
				var = INITIAL_VALUE_4_RIGHT_SHIFTING; 
		}
		else
		{
			var <<= 1; /* shift left */
			var |= 1; /* mask the LSB to switch off LED P10 */
			/* 
				start over when all LEDs are off and a zeo is 
				shifted to bit number 4, i.e., switch P14
			*/
			if(var == 0xEF ) 
				var = INITIAL_VALUE_4_LEFT_SHIFTING; 
		}
		/* check switch P14 for the delay time */
		if(P14)
			delay(5000);
		else
			delay(20000);
	}
}

