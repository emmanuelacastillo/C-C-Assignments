/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/13/2016
 * C2A5E2_Create2D.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * Below allocates a 2-dimensional pointer array in one contiguous
 * block of memory.
 */
#include "C2A5E2_Type-Driver.h"
#include <stdlib.h>
#include <stdio.h>

// Method below is used to verify that
// there is memory space available with the
// give size. If not, the program will
// terminate.
static void *SafeMalloc(size_t size)
{
   void *mallocPointer;
   // An attempt to allocate memory is done below.
   // If there is not enough memory, the program
   // terminates.
   if ((mallocPointer = malloc(size)) == NULL)
   {
      fputs("Out of memory\n", stderr);
      exit(EXIT_FAILURE);
   }
   return mallocPointer;
}

Type **Create2D(size_t rows, size_t cols)
{
   // Below gets the total size of a block of memory
   // and stores it into *pMem. It is split between the
   // number of rows and the total number of elements
   // defined by Type.
   size_t totalMem = (rows * sizeof(Type *)) + (rows * cols * sizeof(Type));
   Type *pMem = (Type *)SafeMalloc(totalMem);
   // A pointer is pointed to the pointer to
   // the block of memory
   Type **p2D = (Type **)pMem;
   // The first row's col address is
   // set after the last rows address
   Type *pCols = (Type *)&p2D[rows];

   // For each row, its first elements address
   // is set after each row's last column.
   size_t rowCount;
   for (rowCount = 0; rowCount < rows; ++rowCount)
   {
      p2D[rowCount] = pCols;
      pCols += cols;
   }
   return(p2D);
}

// Below frees the block of memory
// that a pointer holds.
void Free2D(void *p)
{
   free(p);
}
