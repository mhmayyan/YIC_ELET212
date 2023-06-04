/*
* Blink pin 0 on port 1 at two different flashing rates based on an input switch
*/

#include    <WIN51.H>

#define     SELECT     (*( unsigned char *)(0x2fC48))

sbit LED = P1^0;
sbit SW = P1^4;

void    delay( unsigned long del )
{
    while(del) del--;
}

void    main( void )
{
    unsigned char   led = 0xfe;

    SELECT = 0x9e;

    while(1)  
    {
       LED ^= 1;    //LED = ~LED;
       if(SW) delay(3000);
       else delay(10000);
    }
}





