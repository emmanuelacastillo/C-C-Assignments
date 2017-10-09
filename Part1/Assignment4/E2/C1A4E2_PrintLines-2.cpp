/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/24/2015
 * C1A4E2_PrintLines-2.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This implementation file displays the first parameter in the same line as many times
 * as defined in the second parameter.
 */
#include <iostream>

using namespace std;

void PrintLines(int displayVal, int numOfDisplay)
{
   // For loop is used to display the input character 
   // a specific number of times on the same line.
   for (int displayCount = 0; displayCount < numOfDisplay; displayCount++)
      cout << char(displayVal);

   cout << "\n";
}
