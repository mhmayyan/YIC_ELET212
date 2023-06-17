/*
 * gcc -Wall -Wextra 04_dataTypeExample.c -o 04_dataTypeExample
*/
#include <stdio.h>
int main() {
  // Create variables
  int myNum = 15;              // Integer (whole number)
  float myFloatNum = 5.99;     // Floating point number
  char myLetter = 'D';         // Character
  // Print variables
  printf("%d\n", myNum);
  printf("%f\n", myFloatNum);
  printf("%c\n", myLetter);
  // constants
  const int minutesPerHour = 60;
  const float PI = 3.14;
  printf("m/h = %d, PI = %0.3f\n", minutesPerHour, PI);
  // arrays
  int myNumbers[4] = {25, 50, 75, 100};
  printf("%d\n", myNumbers[0]);  // Outputs 25
  // multidimensional arrays
  int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
  matrix[0][2] = 55; // modifying an array element
  printf("%d\n", matrix[0][2]);  // Outputs 55
  // strings
  char greetings[] = "Hello World!";
  // a string is an array of data type char elemnts and ends with zero 
  char greetings2[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', 0};
  printf("%s\n", greetings);
  printf("%s\n", greetings2);
  printf("%c\n", greetings[0]);
  printf("%llu\n", sizeof(greetings));   // Outputs 13
  printf("%llu\n", sizeof(greetings2));  // Outputs 13
  return 0;
}