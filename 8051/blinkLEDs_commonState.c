/*
	By Mohammad Mayyan
	June 14, 2023

	Function:
		Blink LEDs P10 to P13. Assure that they all have the same logical level.
*/

#include    <WIN51.H>

#define     SELECT     (*( unsigned char *)(0x2fC48))

sbit P10 = P1^0;
sbit P11 = P1^1;
sbit P12 = P1^2;
sbit P13 = P1^3;

bit state = 1;

void    delay( unsigned long  del )
{
    while(del) del--; // del = del -1;
}

void    main( void )
{
	/* startup settings */
	SELECT = 0x9e;
	P1 = 255;  /* to turn off all LEDs and  to assure correct reading of the pin logical status when reading switches */

	/* loop forever */
	while(1)
	{
		state ^=1; /* toggle state */
		/* use the same state for all LEDs */
		P10 = state;
		P11 = state;
		P12 = state;
		P13 = state;
		delay(10000);
	}
}

