/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/23/2016
 * C2A6E2_GetValues.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * GetValues obtains the floating point inputs from
 * a user. Each input is than stored in a floating
 * point pointer array. The first pointer of the
 * input set is than returned.
 */
#include <iostream>
#include <cstdlib>

using namespace std;

float *GetValues(float *first, size_t elements)
{
   cout << "Please enter whitespace-separated floating point values:\n";
   float *values = first;
   
   while (cin >> *values)
   {
      values++;
   }
   return first;
}
