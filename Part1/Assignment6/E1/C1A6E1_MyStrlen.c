/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/08/2015
 * C1A6E1_MyStrlen.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This implementation simulates what occurs in string.h own strlen function. Essentially,
 * a pointer is set to the null position of a paramater pointer that contains a string.
 * A difference between the pointer at the null position with the parameter pointer
 * determines the length of the string due to the char size difference between the two pointers.
 */
#include <stdlib.h>

size_t MyStrlen(const char *s1)
{
   const char *strDiff = s1;

   // strDiff is incremented to the null ('\0') position of the string
   while (*strDiff)
      strDiff++;

   // typecast to size_t to avoid compiler warning
   return((size_t)(strDiff - s1));
}
