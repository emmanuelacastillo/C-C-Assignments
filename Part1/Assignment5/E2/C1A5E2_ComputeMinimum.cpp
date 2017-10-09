/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/01/2015
 * C1A5E2_ComputeMinimum.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This implementation file takes in two values and returns the smallest one.
 */
double &ComputeMinimum(const double &val1, const double &val2)
{
   return (double &)(val1 < val2 ? val1 : val2);
}
