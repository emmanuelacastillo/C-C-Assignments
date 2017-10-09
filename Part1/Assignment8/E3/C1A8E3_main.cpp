/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/20/2015
 * C1A8E3_main.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This program reads a text file and replaces every instance of a string to replace.
 * The string its finds is replaced and written in a new file. This occurs until the
 * end of the file of the original text file.
 */
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

const int REQ_ARGS = 5;
const int SEARCH_FILE = 1;
const int RESULT_FILE = 2;
const int SEARCH_STRING = 3;
const int REPLACE_STRING = 4;
const int LINE_SIZE = 256;

void ErrorAndDie(const char *errorMsg)
{
   cerr << "\"" << *errorMsg;
   exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
   // Verify correct amount of arguments are supplied
   if (argc != REQ_ARGS)
      ErrorAndDie("Invalid number of arguments");

   ifstream searchFile(argv[SEARCH_FILE]);
   if (!searchFile.is_open())
      ErrorAndDie("Error opening search file");

   ofstream replaceFile(argv[RESULT_FILE]);
   if (!replaceFile.is_open())
      ErrorAndDie("Error opening result file");

   char buff[LINE_SIZE],
      *searchString = argv[SEARCH_STRING],
      *replaceString = argv[REPLACE_STRING];

   // Search string length will be used constantly
   // to assist in the string replace
   size_t searchStringLength = strlen(searchString);

   // Grabs each line from file and searches for string to replace
   while (searchFile.getline(buff, sizeof(buff)))
   {
      char *cp1;
      // Replaces every instance of search string with replace string
      for (cp1 = buff; char *cp2 = strstr(cp1, searchString);)
      {
         replaceFile.write(cp1, cp2 - cp1);
         replaceFile << replaceString;
         cp1 = cp2 + searchStringLength;
      }
      // Any remainder string after search string is replaced
      // is included along side a new line.
      replaceFile << cp1 << '\n';
   }

   // Verifies search file was fully read through
   if (!searchFile.eof())
      ErrorAndDie("File did not read end of file");

   searchFile.close();
   replaceFile.close();

   return(EXIT_SUCCESS);
}
