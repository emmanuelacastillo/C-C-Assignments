/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 03/02/2016
 * C2A7E3_ReverseEndian.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 */

#include <stdlib.h>
#include <stdio.h>

void *ReverseEndian(void *ptr, size_t size)
{
   char *head = (char *)ptr;
   char *tail = (char *)ptr + size - 1;
   size_t byteCount;

   for (byteCount = 0; byteCount < size - 1; ++byteCount)
   {
      char temp = *head;
      *head = *tail;
      *tail = temp;
      ++head;
      --tail;
   }

   return head;
}
