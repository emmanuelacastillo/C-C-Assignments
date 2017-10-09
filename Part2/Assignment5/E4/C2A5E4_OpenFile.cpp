/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/13/2016
 * C2A5E4_OpenFile.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * OpenFile opens a specified file in readonly mode.
 * If an error occurs the program terminates.
 */
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

void OpenFile(const char *fileName, ifstream &inFile)
{
   inFile.open(fileName);

   // If file was not opened properly an error is sent out
   // and the program terminates.
   if (!inFile.is_open())
   {
      cerr << "Couldn't open file " << fileName << '\n';
      exit(EXIT_FAILURE);
   }
}
