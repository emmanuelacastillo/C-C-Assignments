/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 01/20/2016
 * C2A1E1_main.c
 * Win7
 * Visual C++ 11.0
 *
 * This program tests the elements of C programming. It consists of
 * macro-like functions, normal functions, pointers and etc.
 */

#include <stdio.h>
#include <stdlib.h>

#define Sum(addend1, addend2) ((addend1) + (addend2))
#define Elements(arrayDesig) (sizeof(arrayDesig) / sizeof((arrayDesig)[0]))

// The below function creates a pointer to long
// based on the provided element count
long *CreateArray(size_t elementCount)
{
   long *createdArray;

   // Memory allocation is checked and handled if there
   // is insufficient memory
   if ((createdArray = (long *)malloc(elementCount)) == NULL)
   {
      fputs("Out of memory\n", stderr);
      exit(EXIT_FAILURE);
   }
   return(createdArray);
}

// The below function opens a file if it
// exists based on the provided file path
FILE *OpenFile(const char *filePath)
{
   FILE *openedFile;

   // openFile is checked for NULL to make sure the file exists.
   // If it doesn't it is handled.
   if ((openedFile = fopen(filePath, "a+b")) == NULL)
   {
      fprintf(stderr, "Can't open %s\n", filePath);
      exit(EXIT_FAILURE);
   }
   return(openedFile);
}

// The below function copies the pointer to char from a source
// to a specified destination pointer to char
void CopyString(char *destination, const char *source)
{
   *destination = *source;
}

// The below function creates and displays the
// 0 values of each element of the double array.
// The element size of the double array is based
// on the size of a long double type
void DisplayClearedArray()
{
   // The array's elements are all initialized to 0.
   double testArray[(int)sizeof(long double)] = {0};
   int arrayIndex;

   // The contents of the array is displayed.
   for (arrayIndex = 0; arrayIndex < (int)sizeof(long double); arrayIndex++)
      printf("%f\n", testArray[arrayIndex]);
}

int main(void)
{
   printf("Assignment 1 Exercise 1 Complete!");
   
   return(EXIT_SUCCESS);
}
