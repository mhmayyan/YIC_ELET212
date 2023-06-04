/*
* shift an LED from P1.0 to P1.3 repeatedly
*/

#include    <WIN51.H>

#define     SELECT     (*( unsigned char *)(0x2fC48))

void    delay( int  del )
{
    while(del--);
}

void    main( void )
{
    unsigned char   led = 0xfe;

    SELECT = 0x9e;

    do  {
       P1 = led;
       delay(30000);
       led <<= 1;
       led |= 0xf1;
       if( led == 0xff ) led = 0xfe;
    } while(1);
}





