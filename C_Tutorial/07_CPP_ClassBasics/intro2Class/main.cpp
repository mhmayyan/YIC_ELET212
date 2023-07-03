/*
	By Mohammad Mayyan
	July 3, 2023

   g++ -Wall -Wextra main.cpp myClass.cpp
   
*/

#include "myLibrary.h"

myClass mC1;
myClass mC2(20, 0.5f);


int main()
{

   printf("mC1 default values: ");
   printf("myInt = %d, MyFloat = %0.2f \n\n",
   mC1.getInt(),
   mC1.getfloat());

   mC1.setInt(1000);
   mC1.setfloat(0.256f);

   printf("mC1 after change: ");
   printf("myInt = %d, MyFloat = %0.2f \n\n",
   mC1.getInt(),
   mC1.getfloat());


   printf("mC2 values: ");
   printf("myInt = %d, MyFloat = %0.2f \n\n",
   mC2.getInt(),
   mC2.getfloat());

   return 0;

}