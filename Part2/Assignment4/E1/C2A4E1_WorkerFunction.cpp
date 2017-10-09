/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/09/2016
 * C2A4E1_WorkerFunction.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * WorkerFunction declares a 4-dimensional array and uses it
 * as well as 2 pointers to float parameters to utilize the
 * RandomizeArray and ComputeAverages functions.
 */
#include "C2A4E1_ArraySize.h"
void RandomizeArray(float (*randArray)[DIM1][DIM2][DIM3]);
void ComputeAverages(float (*computeArray)[DIM1][DIM2][DIM3], float *nestedAvg, float *linearAvg);

void WorkerFunction(float *nestedAvg, float *linearAvg)
{
   float testArray[DIM0][DIM1][DIM2][DIM3];
   RandomizeArray(testArray);
   ComputeAverages(testArray, nestedAvg, linearAvg);
}
