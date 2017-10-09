/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/08/2015
 * C1A6E2_main.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This application exercises the string comparison function from the string.h library
 * as well as its own implementation. Two string is inputted from a user. '\n' are than
 * removed from the string. After, string.h and the applications comparison functions
 * are used to display a value that represents the equality between the strings.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Below is used to define the maximum length of
// a string size within a char array.
#define LENGTH 129

int MyStrcmp(const char *s1, const char *s2);

int main(void)
{
   char strOne[LENGTH], strTwo[LENGTH];
   size_t newLineIndex;

   printf("Please enter first string for comparison:\n");
   fgets(strOne, LENGTH, stdin);

   // Below is used to remove newline from inputString1
   newLineIndex = strlen(strOne) - 1;
   if (strOne[newLineIndex] == '\n')
      strOne[newLineIndex] = '\0';

   printf("Please enter second string for comparison:\n");
   fgets(strTwo, LENGTH, stdin);
   // Below is used to remove newline from inputString2
   newLineIndex = strlen(strTwo) - 1;
   if (strTwo[newLineIndex] == '\n')
      strTwo[newLineIndex] = '\0';

   printf("strcmp(\"%s\", \"%s\") returned %d\n", strOne, strTwo, strcmp(strOne, strTwo));
   printf("MyStrcmp(\"%s\", \"%s\") returned %d\n", strOne, strTwo, MyStrcmp(strOne, strTwo));

   return(EXIT_SUCCESS);
}
