/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/01/2015
 * C1A5E3_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This program grabs two decimal numeric values and utilizes the 
 * functions to return either the minimum or maximum between the two.
 * The arguments passed to the functions are reference type so it 
 * can be handled by the functions expected parameter types.
 * A prototype is included to access the implementation files that
 * contains the logic for the functions.
 */
#include <iostream>
#include <cstdlib>

using namespace std;

// Prototypes for existing functions defined in their implementation files
double *ComputeMinimum(const double *val1, const double *val2);
double *ComputeMaximum(const double *val1, const double *val2);

int main()
{
   // Input values are grabbed as double data type to properly use in the above prototype functions
   cout << "Please enter any space-separated pair of decimal numeric values\n";
   
   double val1, val2;
   cin >> val1 >> val2;

   // Minimum value is displayed to the console below
   cout << "ComputeMinimum(&" << val1 << ", &" << val2 << ") return &" 
         << *ComputeMinimum(&val1, &val2) << "\n";

   // Maximum value is displayed to the console below
   cout << "ComputeMaximum(&" << val1 << ", &" << val2 << ") return &" 
         << *ComputeMaximum(&val1, &val2) << "\n";

   return(EXIT_SUCCESS);
}
