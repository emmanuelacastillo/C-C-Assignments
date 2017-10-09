/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 03/02/2016
 * C2A7E2_ListHex.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * ListHex displays the file contents in hexadecimal
 * values. Each line contains the number bytes
 * specified from bytesPerLine.
 */
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void ListHex(ifstream &inFile, int bytesPerLine)
{
   int byteCount = 0;

   // Add padding of '0' if the specified
   // width is not met. Also, set output
   // to be in hexadecimal.
   cout << setfill('0') << hex;

   // Place holder for current byte
   // in file.
   char currentByte;

   // Loops through file until EOF.
   while (!inFile.eof())
   {
      // Current file content is stored in a char.
      // If content fails to store data
      // the loop is ended.
      if (!inFile.get(currentByte))
         break;

      // Type cast to get correct hexadecimal value
      int hexValue = (int)((unsigned char)currentByte);

      // Current file content is print out.
      cout << setw(2) << hexValue << " ";

      byteCount++;

      // If byte count is met, the next set of
      // bytes are displayed on the next line.
      if (byteCount == bytesPerLine)
      {
         byteCount = 0;
         cout << "\n";
      }
   }
}
