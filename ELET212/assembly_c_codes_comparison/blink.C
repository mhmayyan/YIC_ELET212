/*
* Blink pin 0 on port 1
*/

#include    <WIN51.H>

#define     SELECT     (*( unsigned char *)(0x2fC48))

sbit P10 = P1^0;

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
       P10 ^= 1;    //P10 = ~P10;
       delay(3000);
    }
}





