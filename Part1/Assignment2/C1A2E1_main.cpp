/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/10/2015
 * C1A2E1_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This code translates an uppercase character to a lowercase character from a user input.
 *
 * Answers to Q1 & Q2:
 * 1. When a user enters anything other than an uppercase character no translation occur
 *    and the input itself is represented as the lowercase representation. The reason no
 *    translation occurs is because the input character is not within the uppercase char 
 *    decimal value range. Thus, it does not have a lowercase representation.
 *
 * 2. cin.get allows a user to send input until a /n is entered. For this reason, a whitespace,
 *    assuming it is not a newline whitespace, will be read and the program will not proceed 
 *    to the next line of code until a /n is entered. Although, what is set to the variable is only 
 *    the first input character.
 */


#include <iostream>
#include <cstdlib>

using namespace std;

const char TO_LOWER_CONVERSION = 'a' - 'A';

int main()
{
   cout << "Please enter any character\n";
   char userInput = char(cin.get());

   char lowerCaseValue = userInput + TO_LOWER_CONVERSION;

   cout << "The lowercase equivalent of "
        "\'" << userInput << "\'"
        " is "
        "\'" << lowerCaseValue << "\'";

   return(EXIT_SUCCESS);
}
