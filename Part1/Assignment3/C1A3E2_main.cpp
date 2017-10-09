/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/14/2015
 * C1A3E2_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This code reverse the digits of a user-entered integer value. It uses the least significant
 * digit to display each reverse number of the inputted number individually. The quotient of the number
 * divided by 10 is used to grab the next LSD to display. Additionally, if a number is negative
 * it is first turned to positive and run the LSD algorithm than a negative sign is displayed after.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const int LSD_MODULO_MULTIPIER = 10;
const int NEW_NUMBER_MULTIPLIER = 10;

int main()
{
   cout << "Plese enter an integer value\n";

   int numberInput;
   cin >> numberInput;

   cout << "\"" << numberInput << "\" in reverse is \"";

   // If number is negative, it will be set as positive so that it can properly
   // use the reverse number algorithm. After, the negative sign will be returned.
   bool isNumberNegative = false;
   if (numberInput < 0)
   {
      isNumberNegative = true;
      numberInput = -numberInput;
   }
      
   // The least significant digit is used to display each reverse number individual.
   do
   {
      int currentLsdNumber = numberInput % LSD_MODULO_MULTIPIER;
      cout << currentLsdNumber;

      // The quotient of the number dividing by NEW_NUMBER_MULTIPLIER 
      // is the next number used to get its least significant digit.
      numberInput /= NEW_NUMBER_MULTIPLIER;
   } while (numberInput != 0);

   // Negative sign is returned.
   if (isNumberNegative == true)
      cout << "-";

   cout << "\"";

   return(EXIT_SUCCESS);
}
