#include    <win51.h>
#define     SELECT     (*(unsigned char*)(0x2fC48))
unsigned char   led;
void    main( void )
{
        SELECT = 0x9e;
        led = 0xfe;

        TMOD = 0x10;
        TH1 = 0;
	TL1 = 0;
        P1 = led;

        ET1 = 1;
        EA = 1 ;
        TR1 = 1;
        
        while(1);
}
void TIMER1(void) interrupt 3
{
        led = (led << 1) | 0xf1;
        if ( led == 0xff ) led = 0xfe;
        P1 = led;   /* led on */
}
