/*
	By Mohammad Mayyan
	June 14, 2023

	Function:
		Blink LEDs P10 to P13.
*/

#include    <WIN51.H>

#define     SELECT     (*( unsigned char *)(0x2fC48))

sbit P10 = P1^0;
sbit P10 = P1^1;
sbit P10 = P1^2;
sbit P10 = P1^3;

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
		P10 = ~P10;
		P11 = ~P11;
		P12 = ~P12;
		P13 = ~P13;
		delay(10000);
	}
}

