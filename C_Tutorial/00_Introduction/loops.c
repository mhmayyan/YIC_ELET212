/*
 * gcc -Wall -Wextra loops.c -o loops
*/
#include <stdio.h>

#define ARRAY_SIZE   5

int main()
{

   int i; // we'll use i as an index within a for loop
   int x[ARRAY_SIZE];

   printf("\n\n");
   
   for ( i=0; i<ARRAY_SIZE ; i++ ) {
      x[i] = i * 10;
      printf("i: %d x[i]: %d\n",i,x[i]);
   }
   printf("\n\n");

   // while loops are useful in certain situations as well
   int y = 0;
   while ( y < 50 ) {
      y += 12;
      printf("y: %d\n",y);
   }

   printf("\n\n");

   // and do-while loops, use these instead of while loops
   // if you want the code block executed before evaluation
   // of a condition (rather than vice versa, as is done with
   // a normal while loop)
   y = 0;
   do {
      y += 12;
      printf("y: %d\n",y);
   }
   while ( y < 50 );

   return 0;

}
