#include    <win51.h>

#define     SELECT     (*( unsigned char*)(0x2fc48))

unsigned char   led;

void    main( void )
{
       SELECT = 0x9c;
       led = 0xfe;
       P1 = led;
       IT1 = 1; // hi to low (falling) edge
       EX1 = 1;
       EA = 1 ;
       while(1);
}

void EXINT1(void) interrupt 2
{
        led = (led << 1) | 0xf1;
        if ( led == 0xff ) led = 0xfe;
        P1 = led;   /* led on */
}
