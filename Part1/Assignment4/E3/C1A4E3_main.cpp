/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/24/2015
 * C1A4E3_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This code exercises the concept of default function arguments.
 * It grabs three inputs and passes them in four functions of the same
 * name but different argument list. Than it prints out characters based on
 * the function called and the parameters. If an argument value is not set for
 * a particular parameter, the default value is used.
 */
#include <iostream>
#include <cstdlib>

using namespace std;

void PrintLines(int displayVal = 'Z', int numOfDisplay = 1, int numOfLines = 1);

const int NUMBER_OF_REPEAT = 5;

int main()
{
   for (int count = 0; count < NUMBER_OF_REPEAT; count++)
   {
      // Below user is asked for three inputs
      cout << "Please enter...\n"
         "1st: character to display\n"
         "2nd: number of times to display character on each line\n"
         "3rd: number of lines to display\n";

      char displayVal;
      int numOfDisplay, numOfLines;
      // Inputs are set into the 3 variables
      cin >> displayVal >> numOfDisplay >> numOfLines;

      // Function calls occurs with different parameter list
      // Note that the first parameter is cast for type safety
      PrintLines(int(displayVal), numOfDisplay, numOfLines);
      PrintLines(int(displayVal), numOfDisplay);
      PrintLines(int(displayVal));
      PrintLines();
   }
   return(EXIT_SUCCESS);
}
