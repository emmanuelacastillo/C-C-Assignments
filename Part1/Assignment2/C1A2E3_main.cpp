/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/10/2015
 * C1A2E3_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * The code prints a leading character, 1 less the row number and a diagonal character after.
 * A diagonal character exists even if a leading character does not.
 * Essentially, a right angle triangle is produced.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const char LEADER_CHAR = '.';
const char DIAGONAL_CHAR = '%';

int main()
{
   cout << "Please enter any positive decimal integer value:\n";

   //The inputted integer determines the max row that will be print out
   int maxRows;
   cin >> maxRows;
   
   //Each row will have one diagonal character at a column number that is the same as the row number
   for (int row = 0; row < maxRows; row++)
   {
      //For each row, a leading character will print out for each column before the diagonal character.
      //Essentially, the amount of leading character outputted is 1 less the row number.
      for (int column = 0; column < row; column++)
      {
         cout << LEADER_CHAR;
      }
      cout << DIAGONAL_CHAR << "\n";
   }

   return(EXIT_SUCCESS);
}
