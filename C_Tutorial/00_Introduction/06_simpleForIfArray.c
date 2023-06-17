/*
	gcc -Wall -Wextra 06_simpleForIfArray.c -o 06_simpleForIfArray
	
	By Mohammad Mayyan
	June 14, 2023

	Function:
	Program to calculate the sum of positive numbers in an 
	array of integers except the values 5 and 9. Stop the 
	summation if you find a number that is greater than 100.
*/
#include <stdio.h>
int main() {
   int myArray[10] = {5, -5, 9, 3, -10, 6, 8, 9, 7, 1};
   double sum = 0.0;
   for (int i = 1; i <= 10; ++i) {
      if (myArray[i] < 0 || myArray[i] == 5 || myArray[i] == 9) {
         continue;
      }
      if (myArray[i] > 100) break;
      sum += myArray[i]; 
   }
   printf("Sum = %.2lf", sum); // Sum = 25.00
   return 0;
}


