/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/25/2016
 * C2A6E2_GetValues.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * The below method returns a pointer to the first
 * floating point number from the provided inputs.
 */
#include <iostream>
#include <cstdlib>

using namespace std;

float *GetValues(float *first, size_t elements)
{
   cout << "Please enter whitespace-separated floating point values:\n";
   float *input = first;

   // input is populated with the values based on the expected
   // element size of the pointer to a float.
   for (size_t count = 0; count < elements; ++count, ++input)
      cin >> *input;

   return first;
}
