/*
	By Mohammad Mayyan
	June 18, 2023
*/


#ifndef MYLIBRARY_02_H
#define MYLIBRARY_02_H

#include <stdio.h>

/*
only variable declaration is allowed 
in header files. do not define variables
in header files.
*/
//int i = 20; // error. 
int i; // to be defined in a source file
float x; // to be defined in a source file

float mySimpleFuncByValue(
   int iloc,
   float xloc
   );

float mySimpleFuncByReference(
   int * iPtr,
   float * xPtr
   );

void modifyArray( 
   int *, 
   int *, 
   float *
   );

#endif // MYLIBRARY_02_H