/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/25/2016
 * C2A6E2_SortValues.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * The below sorts a pointer to a float in descending order
 * based on the expected number of elements in the pointer to a float.
 */
#include <cstdlib>
#include <cstring>

float *SortValues(float *first, size_t elements)
{
   bool isSwap = false;

   do
   {
      // curr and next are used to traverse and compare
      // the values provided from first
      float *curr = first, *next = first;

      // The full set of values are traversed and compared
      for (size_t eleCount = 0; eleCount < elements - 1; eleCount++)
      {
         // The next address location is incremented so it represents
         // the value after the current value
         next++;
         // If the current value is less than the next
         // they are swapped below
         if (*curr < *next)
         {
            float temp = *curr;
            *curr = *next;
            *next = temp;
            isSwap = true;
         }
         // The current becomes the next value
         // and later the next becomes its proceeding
         // value.
         curr++;
      }
      // After one go through, the latest element should be in
      // the correct position so it is not traversed again.
      --elements;
   } while (isSwap && elements != 0);

   return first;
}
