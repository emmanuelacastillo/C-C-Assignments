/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 03/07/2016
 * C2A8E2_OpenFileBinary.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * OpenFileBinary attempts to open
 * a binary file in read only mode.
 * If it is unsuccessful and error occurs
 * and program terminates.
 */
#include <stdio.h>
#include <stdlib.h>

FILE *OpenFileBinary(const char *fileName)
{
   FILE *file;
   // Opens a binary file in read mode.
   if ((file = fopen(fileName, "rb")) == NULL)
   {
      // Errors out if the file did not open successfully.
      fputs("Error opening file\n", stderr);
      exit(EXIT_FAILURE);
   }
   return file;
}
