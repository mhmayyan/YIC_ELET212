/*
	By Mohammad Mayyan
	June 18, 2023

   gcc -Wall -Wextra main_02.c function_02.c
   
*/

#include "myLibrary_02.h"


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

