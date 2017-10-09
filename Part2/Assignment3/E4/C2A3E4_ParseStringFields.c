/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/03/2016
 * C2A3E4_ParseStringFields.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * ParseStringFields reads through a file, line by line and
 * displays every char that is not part of the defined delimiters.
 * It does this by utilizing strtok.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFFSIZE 254
#define DELIMITERS "AEIOUaeiou\n"

void ParseStringFields(FILE *fp)
{
   char buff[BUFFSIZE];

   // Buffers every line in the file.
   while (fgets(buff, sizeof(buff), fp))
   {
      char *currentLine;
      // Grab parts of the line that is separated by the delimiters.
      for (currentLine = buff; currentLine = strtok(currentLine, DELIMITERS); currentLine = NULL)
      {
         // Below removes every leading whitespace.
         while (isspace(*currentLine))
            ++currentLine;

         puts(currentLine);
      }
   }
}
