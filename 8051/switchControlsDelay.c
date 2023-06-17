/*
	By Mohammad Mayyan
	June 14, 2023

	Function:
		While blinking LED P10, use the switch P14 to control the delay time.
		We should have different delay time based on the status of the switch 
		P14. The blinking should be faster when P14 reads high.
*/

#include    <WIN51.H>

#define     SELECT     (*( unsigned char *)(0x2fC48))

sbit P10 = P1^0;
sbit P14 = P1^4; /* input switch */

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
		P10 = ~P10;
		if(P14)
		{
			delay(5000);
		}
		else
		{
			delay(20000);
		}
	}
}

