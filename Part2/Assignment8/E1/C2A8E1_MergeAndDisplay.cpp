/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 03/07/2016
 * C2A8E1_MergeAndDisplay.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * MergeAndDisplay displays the contents of the provided files
 * line by line. Each file is gone through for each line before
 * displaying the next lines.
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Buffer size to hold the contents of the files.
const int BUFFSIZE = 511;
const int SAFEBUFF = BUFFSIZE - 1;

void MergeAndDisplay(ifstream files[], size_t count)
{
   // buff is used to store the current files
   // contents of the current line.
   char buff[BUFFSIZE];
   // fileCloseCount determines
   // when all files are closed
   // to exit the loop.
   size_t fileCloseCount = 0;
   // fileIndex will be used
   // to iterate through each files.
   size_t fileIndex = 0;

   while (fileCloseCount < count)
   {
      // If the current file is open
      // it will either close the file
      // or display its contents.
      if (files[fileIndex].is_open())
      {
         // The current file's line
         // is grabbed below
         files[fileIndex].getline(buff, SAFEBUFF);

         // If the file is at its end of file
         // the loop continues and nothing is displayed.
         // A counter is incremented to notify
         // that a file has been closed.
         if (files[fileIndex].eof())
         {
            files[fileIndex].close();
            ++fileCloseCount;
            continue;
         }

         // If end of file is not reach
         // the files line content is displayed.
         cout << buff << "\n";
      }
      fileIndex++;

      // Once all file lines are displayed
      // for its current line, it goes
      // through the files again for its next
      // line by changing the index back to 0.
      if (fileIndex >= count)
         fileIndex = 0;
   }
}
