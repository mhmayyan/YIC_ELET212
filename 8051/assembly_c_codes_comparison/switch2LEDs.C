/*
* switch LEDs P1.0 through P1.3 ON/OFF with switches P14 through P17
*/

#include    <win51.h>

#define     SELECT     (*(unsigned char*)(0x2fc48))

void    main( void )
{
        unsigned char   sw;

        SELECT = 0x9e;

        do  {
            sw = P1;
            P1 = ( sw >> 4 ) | 0xf0;
        } while(1);
}




