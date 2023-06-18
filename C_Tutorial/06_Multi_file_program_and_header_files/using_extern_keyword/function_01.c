/*
	By Mohammad Mayyan
	June 18, 2023

   gcc -Wall -Wextra main_01.c function_01.c
   
*/

#include <stdio.h>

float x = 0;

float mySimpleFuncByValue(
   int iloc,
   float xloc
   )
{
   return (float)iloc * xloc;
}

float mySimpleFuncByReference(
   int * iPtr,
   float * xPtr
   )
{
   return (float)(*iPtr) * (*xPtr);
}

void modifyArray( 
   int * array,  
   int * iPtr,
   float * xPtr
   )
{

   array[0] = *iPtr;
   array[1] = 2*(* xPtr);

}

