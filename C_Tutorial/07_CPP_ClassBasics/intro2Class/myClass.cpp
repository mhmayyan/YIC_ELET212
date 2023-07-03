/*
	By Mohammad Mayyan
	July 3, 2023

   g++ -Wall -Wextra main.cpp myClass.cpp
   
*/

#include "myLibrary.h"

myClass::myClass(){}

myClass::myClass(
   int providedInt, 
   float providedFloat
   )
{
   intVar = providedInt;
   floatVar = providedFloat;
}

void myClass::setInt(int providedInt)
{
   intVar = providedInt;
}
int myClass::getInt(void)
{
   return intVar;
}
void myClass::setfloat(float providedFloat)
{
   floatVar = providedFloat;
}
float myClass::getfloat(void)
{
   return floatVar;
}