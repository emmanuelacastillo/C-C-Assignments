/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/17/2015
 * C1A3E3_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This code display each number, including negative sign into words. This is determined
 * by grabbing the most significant digit of the number, displaying it in words
 * than grabbing the next most significant digit until all number is displayed. The negative
 * sign is displayed and removed before the algorithm.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const int DIVISOR_MULTIPIER = 10;
const int DIVIDEND_MULTIPLIER = 10;
const int END_OF_ALGORITHM_NUMBER = 0;

int main()
{
   cout << "Plese enter an integer value\n";

   int numberInput;
   cin >> numberInput;

   cout << "\"" << numberInput << "\" in words is \"";

   // If number is negative, it will be set as positive so that it can properly
   // use the number to word algorithm. The negative sign will be displayed
   // as minus right away.
   if (numberInput < 0)
   {
      numberInput = -numberInput;
      cout << "minus ";
   }

   // The least significant digit is used to display each reverse number individual.
   int divisor = 1;
   int dividend = numberInput;

   while (dividend > (DIVISOR_MULTIPIER - 1))
   {
      divisor *= DIVISOR_MULTIPIER;
      dividend /= DIVIDEND_MULTIPLIER;
   }

   do
   {
      // msd is the most significant digit that is used 
      // to display parts of the number one by one
      int msd = numberInput / divisor;

      switch (msd)
      {
         case 0:
            cout << "zero";
            break;
         case 1:
            cout << "one";
            break;
         case 2:
            cout << "two";
            break;
         case 3:
            cout << "three";
            break;
         case 4:
            cout << "four";
            break;
         case 5:
            cout << "five";
            break;
         case 6:
            cout << "six";
            break;
         case 7:
            cout << "seven";
            break;
         case 8:
            cout << "eight";
            break;
         case 9:
            cout << "nine";
            break;
         default:
            cout << "Invalid Number";
      }

      // The 2 steps below are used to determine the MSD if divisor is greater than 0
      numberInput -= msd * divisor;
      divisor /= DIVISOR_MULTIPIER;

      // Below space is used to provide a space between each following number string
      if (divisor > END_OF_ALGORITHM_NUMBER)
         cout << " ";

   } while (divisor > END_OF_ALGORITHM_NUMBER);


   cout << "\"\n";

   return(EXIT_SUCCESS);
}
