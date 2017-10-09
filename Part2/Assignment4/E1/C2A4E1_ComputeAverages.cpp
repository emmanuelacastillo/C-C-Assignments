/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/09/2016
 * C2A4E1_ComputeAverages.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * ComputerAverages does an intuitive and efficient way in traversing
 * through a 4-dimensional array. At the same time, it is calculating
 * the average of the array element values and saving it into two place
 * holder pointer to float parameters. One is for the inituitive calculation,
 * the other for the efficient way.
 */
#include "C2A4E1_ArraySize.h"

void ComputeAverages(float (*computeArray)[DIM1][DIM2][DIM3], float *nestedAvg, float *linearAvg)
{
   // Below, the intuitive way is used to traverse through the 4-dimensional array
   // and calculate the average of all its values.

   // Initialize nestedAvg to 0 so it may add itself
   // with the computeArray element values.
   *nestedAvg = 0;

   for (int index0 = 0; index0 < DIM0; ++index0)
      for (int index1 = 0; index1 < DIM1; ++index1)
         for (int index2 = 0; index2 < DIM2; ++index2)
            for (int index3 = 0; index3 < DIM3; ++index3)
               *nestedAvg += computeArray[index0][index1][index2][index3];

   *nestedAvg /= TOTAL_ELEMENTS;

   // Below, the more efficient way is used to compute the average of all the
   // elements in the 4-dimensional array.

   // Initialize linearAvg to 0 so it may add itself
   // with the computeArray element values.
   *linearAvg = 0;

   // A pointer to float is used to traverse through the 4-dimensional
   // float array because each element takes up a float memory size.
   for (float *pointer = (float *)computeArray; pointer < (float *)computeArray + TOTAL_ELEMENTS; ++pointer)
      *linearAvg += *pointer;

   *linearAvg /= TOTAL_ELEMENTS;
}
