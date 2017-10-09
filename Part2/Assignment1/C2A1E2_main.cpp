/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 01/20/2016
 * C2A1E2_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * This program exercises the C++ programming language. It displays the use of
 * structures, pointers, method overloading, and special ways to print out values
 * of different types.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

const double PRINT_DEFAULT = 10.0;

const double TEST_PRINT_DOUBLE = 23.4;
const float TEST_PRINT_FLOAT = 1825e-1;
const char * const TEST_PRINT_CHAR_POINTER = "Hello world!";

struct PersonInfo
{
private: 
   int age;
protected:
   bool error;
   void DoNothing(double **ppDbl) const;
public:
   int GetAge(int const *pInt) const
   {
      return(age + *pInt);
   }
};

PersonInfo *DeclareCppStruct()
{
   PersonInfo *person = {0};

   return person;
}

void PrintSomething(double param = PRINT_DEFAULT)
{
   cout << param << "\n";
}

void PrintSomething(float param) 
{
   cout << param << "\n";
}

void PrintSomething(char const *param)
{
   cout << param << "\n";
}

// Below utilized the above function
// to test method overloading.
void TestPrintSomething()
{
   PrintSomething();
   PrintSomething((double)TEST_PRINT_DOUBLE);
   PrintSomething((float)TEST_PRINT_FLOAT);
   PrintSomething(TEST_PRINT_CHAR_POINTER);
}

// Displays the integral part of a value
// in decimal, octal and hexadecimal
long DisplayBases(double value)
{
   // Fractional part is trancated when value
   // is casted to long
   long longValue = (long)value;
   // longValue is displayed in different bases
   cout << dec << longValue << "\n" << oct << longValue << "\n" << hex << longValue << "\n";

   return longValue;
}

void DisplayCharValues()
{
   const char CHAR_ONE = 'E';
   const char CHAR_TWO = 'A';
   const char CHAR_THREE = 'C';

   // chars are cast to int to display its decimal form.
   cout << int(CHAR_ONE) << "\n" << int(CHAR_TWO) << "\n" << int(CHAR_THREE) << "\n";
}

int main()
{
   cout << "Assignment 1 Exercise 2 Complete!";

   return(EXIT_SUCCESS);
}
