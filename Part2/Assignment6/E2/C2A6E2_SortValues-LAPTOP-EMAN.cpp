/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/23/2016
 * C2A6E2_SortValues.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * The bubble sort algorithm is used here to sort a set
 * of floating pointer values in descending order.
 */
#include <cstdlib>

float *SortValues(float *first, size_t elements)
{
   float temp, isSwap, *current, *afterCurrent;
   current = first, afterCurrent = first;

   do
   {
      for (isSwap = 0, current = first; current != NULL; ++current)
      {
         ++afterCurrent;
         if (current > afterCurrent)
         {
            temp = *current;
            *current = *afterCurrent;
            *afterCurrent = temp;
            isSwap = 1;
         }
      }
   } while (isSwap);

   return first;
}
