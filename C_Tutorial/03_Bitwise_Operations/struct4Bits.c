/*

gcc -Wall -Wextra struct4Bits.c -o struct4Bits

*/


#include <stdio.h>
#include <stdint.h>


void printBinary(unsigned char givenNum)
{
	/* print bits from MSB to LSB */
	for(int  indx = 8-1; indx >=0; indx--)
	{
		printf("%c",givenNum&(1<<indx)?'1':'0');
	}
	printf("\n");
}


int main()
{

typedef struct test
{
uint8_t var1:1;
uint8_t var2:1;
uint8_t var3:1;
uint8_t var4:1;
uint8_t var5:1;
uint8_t var6:1;
uint8_t var7:1;
uint8_t var8:1;

} bins;


union Data {
   bins _bins;
   uint8_t byte;
} data;

bins _bins;
_bins.var1 = 1;
_bins.var2 = 1;
_bins.var3 = 0;
_bins.var4 = 1;
_bins.var5 = 1;
_bins.var6 = 0;
_bins.var7 = 1;
_bins.var8 = 0;


printf("sizeof(_bins) = %lu\n", sizeof(_bins));

data._bins = _bins;

printf("_bins = %u\n\n", data.byte);

printBinary(data.byte);

return 0;
}
