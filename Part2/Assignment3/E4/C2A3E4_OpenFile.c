/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/03/2016
 * C2A3E4_OpenFile.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * OpenFile simply does what is says, opens a file.
 * It only opens a file in read mode because this program
 * only requires reading a file.
 */
#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
   FILE *file;
   // Opens a file in read mode.
   if ((file = fopen(fileName, "r")) == NULL)
   {
      // Errors out if the file did not open successfully.
      fputs("Error opening file\n", stderr);
      exit(EXIT_FAILURE);
   }
   return file;
}
