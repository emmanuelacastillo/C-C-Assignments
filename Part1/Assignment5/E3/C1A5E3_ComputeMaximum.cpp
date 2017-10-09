/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/01/2015
 * C1A5E3_ComputeMaximum.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This implementation file takes in two pointer to const double values and returns the largest one.
 */
double *ComputeMaximum(const double *val1, const double *val2)
{
   return (double *)(*val1 > *val2 ? val1 : val2);
}
