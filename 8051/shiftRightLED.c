/*
	By Mohammad Mayyan
	June 14, 2023

	Function:
		Shift right an LED while assuring that all switches 
		P14-P17 can still be read correctly.
*/

#include    <WIN51.H>

#define     SELECT     (*( unsigned char *)(0x2fC48))
#define INITIAL_VALUE 0xF7

unsigned char var = INITIAL_VALUE;

void    delay( unsigned long  del )
{
    while(del) del--; // del = del -1;
}

void    main( void )
{
	/* startup settings */
	SELECT = 0x9e;
	P1 = 255;  /* to turn off all LEDs and  to assure correct reading of the pin logical status when reading switches */
	

	/*****************************/
	/* loop forever */
	while(1)
	{
		var >>= 1; /* shift right */
		var |= 0x80; /* mask the HSB to assure correct readings of switches P14-P17 */
		/* 
			start over when all LEDs are off
		*/
		if(var == 0xFF ) 
			var = INITIAL_VALUE; 
		/* write var to port 1 */
		P1 = var;
		delay(10000);
	}
}

