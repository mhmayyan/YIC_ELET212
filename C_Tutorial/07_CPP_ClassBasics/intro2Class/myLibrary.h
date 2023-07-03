/*
	By Mohammad Mayyan
	July 3, 2023
*/


#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include <stdio.h>

class myClass
{
public:
   // class constructors
   myClass(); 
   myClass(int providedInt, float providedFloat);
   
   // class destructor
   ~myClass(){} 

   void setInt(int);
   int getInt(void);
   void setfloat(float);
   float getfloat(void);

private:
   int intVar = 100;
   float floatVar = 20.2f;

};



#endif // MYLIBRARY_H