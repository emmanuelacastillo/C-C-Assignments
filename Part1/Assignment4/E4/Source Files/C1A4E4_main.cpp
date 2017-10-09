/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/24/2015
 * C1A4E4_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This main file utilizes the header file "C1A4E4_MaxOf.h" to
 * call macro and inline functions in determining the maximum of 3
 * user input values.
 */
#include <iostream>
#include <cstdlib>
#include "C1A4E4_MaxOf.h"

using namespace std;

int main()
{
   cout << "Please enter three space-separated decimal numeric values:\n";
   
   // Long double data types are used to grab user input values.
   long double val1, val2, val3;
   cin >> val1 >> val2 >> val3;

   // The input values are passed into a macro function and inline function,
   // set in the C1A4E4MaxOf.h header file to determine the max
   // between the values.
   long double mmaxof, fmaxof;
   mmaxof = mMaxOf3(val1, val2, val3);
   fmaxof = fMaxOf3(val1, val2, val3);

   // The results are displayed to the user.
   cout << "mMaxOf3(" << val1 << ", " << val2 << ", " << val3 << ") returned " << mmaxof 
        << "\nfMaxOf3(" << val1 << ", " << val2 << ", " << val3 << ") returned " << fmaxof << "\n";

   return(EXIT_SUCCESS);
}
