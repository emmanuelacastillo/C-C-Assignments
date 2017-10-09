/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/06/2015
 * C1A1E2_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * The code exercises the use of the cout and cin class within the iostream library.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
   int userInput;

   cout << "Please enter any decimal integer numeric value\n";
   cin >> userInput;
   cout << userInput << " decimal = " 
        << oct << userInput << " octal = " 
        << hex << userInput << " hexadecimal";

   return(EXIT_SUCCESS);
}
