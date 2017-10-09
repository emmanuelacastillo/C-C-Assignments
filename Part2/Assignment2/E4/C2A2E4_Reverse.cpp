/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 01/27/2016
 * C2A2E4_Reverse.cpp
 * Win7
 * Visual C++ 11.0
 *
 * The below function uses recursion to read through a text file
 * and displays the individual chars in reverse order after a
 * separator is detected.
 *
 */
#include <fstream>
#include <iostream>

using namespace std;

int Reverse(ifstream &inFile, const int level)
{
   int thisChar = inFile.get();

   // Recursion continues until a separator is grabbed
   // that signals the end of this function.
   if (isspace(thisChar))
      return thisChar;

   // The separator through the recursion calls
   // is stored here and will be returned to the caller.
   // EOF is initialize for the separator because
   // it signifies the end of a file which corresponds
   // to the end of this function.
   int thisSeparator = EOF;
   if (thisChar != '\n' && thisChar != EOF)
      thisSeparator = Reverse(inFile, level + 1);

   // After separator is grabbed, each char is printed
   // where the last char in the reverse order
   // is shown as upper case.
   if (level == 1)
      thisChar = toupper(thisChar);

   if (thisChar != EOF)
      cout.put((char)thisChar);

   return thisSeparator;
}
