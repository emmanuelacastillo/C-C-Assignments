/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/13/2016
 * C2A5E1_SwapObjects.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This script swaps the address references of
 * two objects that contains the same byte size.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void SwapObjects(void *pa, void *pb, size_t size)
{
   // Allocate memory for pb so that its value
   // can be copied later
   void *objectTemp = (void *)SafeMalloc(size);

   // Set objectTemp to pb so it may be copied
   // later.
   memcpy(objectTemp, pb, size);
   // Swap pb and pa memory addresses
   memcpy(pb, pa, size);
   memcpy(pa, objectTemp, size);

   free(objectTemp);
}
