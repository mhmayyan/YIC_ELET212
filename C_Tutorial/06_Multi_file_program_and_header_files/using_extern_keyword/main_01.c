/*
	By Mohammad Mayyan
	June 18, 2023

   gcc -Wall -Wextra main_01.c function_01.c

*/

#include <stdio.h>


extern float mySimpleFuncByValue(
   int iloc,
   float xloc
   );

extern float mySimpleFuncByReference(
   int * iPtr,
   float * xPtr
   );

extern void modifyArray( 
   int *, 
   int *, 
   float *
   );


int main()
{

   int i = 20;
   extern float x;
   x = 0.5f;

   // i and x are both passed by value,
   // meaning a copy of each of these variables
   // is passed to mySimpleFunc
   float y = mySimpleFuncByValue(i,x);
   printf("i: %d x: %10.5f y: %10.5f\n",i,x,y);
   // Now i and x are both being passed by reference
   // (Notice the & symbol)
   // This means that the actual memory location of 
   // i and x are being passed, so any modifications
   // to the values i and x within the function will
   // propogate to main() 
   y = mySimpleFuncByReference(&i,&x);
   printf("i: %d x: %10.5f y: %10.5f\n",i,x,y);

   int myArray[2] = { 0, 0 };
   printf("Before function call, myArray[0]: %d myArray[1]: %d\n",myArray[0],myArray[1]);
   modifyArray(myArray, &i, &x);
   printf("After function call, myArray[0]: %d myArray[1]: %d\n",myArray[0],myArray[1]);

   return 0;

}