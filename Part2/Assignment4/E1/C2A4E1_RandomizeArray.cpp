/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/09/2016
 * C2A4E1_RandomizeArray.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * RandomizeArray utilizes rand() to randomly initialize
 * the 4-dimensional array parameter with random int values.
 */
#include <cstdlib>
#include <ctime>
#include "C2A4E1_ArraySize.h"

void RandomizeArray(float (*randArray)[DIM1][DIM2][DIM3])
{
   // Below initializes srand to allow a more random
   // set of values to be outputted when calling rand().
   // time(0) is used as a seed to refer to use the
   // current time.
   srand((unsigned)time(0));

   // Each element is traverse through setting a random
   // int value.
   for (float *pointer = (float *)randArray; pointer < (float *)randArray + TOTAL_ELEMENTS; ++pointer)
      *pointer = (float)rand();
}
