#include <win51.h>

#define     SELECT     (*( unsigned char *)(0x2fC48))

unsigned char var = 0;

void delayMS(unsigned int timeMS)
{
    unsigned int x, y;
    for( x=0; x<timeMS; x++)
        for( y=0; y<1275; y++) ;
}



void main(void)
{
	
	SELECT = 0x7F;
	while(1)
	{
		//***************************************************
		// sawtooth wave
		var++;
		P1 = var;
		delayMS(1);
	}
}

