/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/24/2015
 * C1A4E2_PrintLines-3.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This implementation file displays the first parameter in the same line as many times
 * as defined in the second parameter. This is repeated as many times defined on the 
 * third parameter.
 */
#include <iostream>

using namespace std;

void PrintLines(int displayVal, int numOfDisplay, int numOfLines)
{
   // First for loop is used to determine the number of times the input 
   // character(s) will be displayed in each line of the console
   for (int lineCount = 0; lineCount < numOfLines; lineCount++)
   {
      // Second for loop is used to determine the amount of times
      // the input character is displayed in the current line
      for (int displayCount = 0; displayCount < numOfDisplay; displayCount++)
         cout << char(displayVal);
      // New line is set for next set of lines.
      cout << "\n";
   }
}
