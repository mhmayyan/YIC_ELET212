/*
 * gcc -Wall -Wextra logicalOperators.c -o logicalOperators
*/


#include <stdio.h>
int main()
{
    int a = 5, b = 5, c = 10, result;

    result = (a == b) && (c > b);
    printf("(a == b) && (c > b) is %d \n", result);

    result = (a == b) && (c < b);
    printf("(a == b) && (c < b) is %d \n", result);

    result = (a == b) || (c < b);
    printf("(a == b) || (c < b) is %d \n", result);

    result = (a != b) || (c < b);
    printf("(a != b) || (c < b) is %d \n", result);

    result = !(a != b);
    printf("!(a != b) is %d \n", result);

    result = !(a == b);
    printf("!(a == b) is %d \n", result);
	
	/* Compare numbers with the same data type. 
	Comparison of a signed and unsigned numbers is wrong 
	*/
	int zero = 0;
	unsigned char unsignedNumber = 1;
	unsigned char unsignedByte = unsignedNumber-2;
	printf("(unsigned char)1-2 < 0 is %d (false) because (unsigned char)1-2 is %u \n", 
	unsignedNumber-2 < zero, unsignedByte);

    return 0;
}
