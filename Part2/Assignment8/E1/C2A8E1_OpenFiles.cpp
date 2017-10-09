/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 03/07/2016
 * C2A8E1_OpenFiles.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * OpenFiles attempts to open a number of files based on the
 * parameter count. If any of them fail, the program terminates.
 */
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

ifstream *OpenFiles(char * const fileNames[], size_t count)
{
   ifstream *files = new ifstream[count];
   
   // Each element of the ifstream array attempts to
   // open a file based on its corresponding file name
   for (size_t fileNum = 0; fileNum < count; fileNum++)
   {
      files[fileNum].open(fileNames[fileNum]);
      // If file was not opened properly an error is sent out
      // and the program terminates.
      if (!files[fileNum].is_open())
      {
         cerr << "Couldn't open file " << fileNames[fileNum] << '\n';
         exit(EXIT_FAILURE);
      }
   }
   return files;
}
