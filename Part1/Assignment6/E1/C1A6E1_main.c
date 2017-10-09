/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/08/2015
 * C1A6E1_main.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This application inputs a string value from the console and displays
 * the string length returned from string.h implementation of strlen
 * and this application's implementation of MyStrlen.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Below is used to define the maximum length of
// a string size within a char array.
#define LENGTH 129

size_t MyStrlen(const char *s1);

int main(void)
{
   char inputString[LENGTH];
   size_t strLenValue, myStrLenValue, newlineIndex;

   printf("Please enter a string (empty or with space):\n");
   fgets(inputString, LENGTH, stdin);

   strLenValue = strlen(inputString);
   myStrLenValue = MyStrlen(inputString);

   // If newline exist, remove from string and exclude from count
   newlineIndex = strLenValue - 1;
   if (inputString[newlineIndex] == '\n')
   {
      strLenValue--;
      myStrLenValue--;
      inputString[newlineIndex] = '\0';
   }

   // strlen return value is cast for portability
   printf("strlen(\"%s\") returned %u\n", inputString, (unsigned int)strLenValue);
   // MyStrlen return value is cast for portability
   printf("MyStrlen(\"%s\") returned %u\n", inputString, (unsigned int)myStrLenValue);

   return(EXIT_SUCCESS);
}
