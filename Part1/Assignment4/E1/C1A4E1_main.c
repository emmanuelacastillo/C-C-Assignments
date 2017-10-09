/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/24/2015
 * C1A4E1_main.c
 * Win7
 * Visual C++ 11.0
 *
 * This program grabs two decimal numeric values and utilizes the 
 * functions to return either the minimum or maximum between the two.
 * A prototype is included to access the implementation files that
 * contains the logic for the functions.
 */
#include <stdio.h>
#include <stdlib.h>

// Prototypes for existing functions defined in their implementation files
double ComputeMinimum(double val1, double val2);
double ComputeMaximum(double val1, double val2);

int main(void)
{
   double val1, val2, min, max;

   // Input values are grabbed as double data type to properly use in the above prototype functions
   printf("Please enter any space-separated pair of decimal numeric values\n");
   scanf("%lf %lf", &val1, &val2);
   
   // Minimum and Maximum is determined by calling the functions below
   min = ComputeMinimum(val1, val2);
   max = ComputeMaximum(val1, val2);

   // Results are displayed to the console
   printf("ComputeMinimum(%f, %f) return %f\n", val1, val2, min);
   printf("ComputeMaximum(%f, %f) return %f\n", val1, val2, max);

   return(EXIT_SUCCESS);
}
