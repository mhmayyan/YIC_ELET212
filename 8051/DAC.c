#include <win51.h>

#define     SELECT     (*( unsigned char *)(0x2fC48))

unsigned char var = 0;

void delayMS(unsigned int timeMS)
{
    unsigned int cntr, cntr2;
    for( cntr=0; cntr<timeMS; cntr++)
        for( cntr2=0; cntr2<1275; cntr2++) ;
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

