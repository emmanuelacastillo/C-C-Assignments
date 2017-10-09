/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/23/2016
 * C2A6E1_GetPointers.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This file exercises the use of function pointers,
 * It contains methods that returns standard library
 * functions of printf and puts.
 */
#include <stdio.h>

static int (*GetPrintfPointer(void))(const char *format, ...)
{
   // Declares and initializes a function pointer
   // to the stdlib printf function
   static int (*pPrintf)(const char *format, ...) = printf;
   return pPrintf;
}

static int (*GetPutsPointer())(const char *str)
{
   // Declares and initializes a function pointer
   // to the stdlib puts function
   static int (*pPuts)(const char *str) = puts;
   return pPuts;
}
