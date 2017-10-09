/*
* Emmanuel A. Castillo, U06580067
* emmanuec@gmail.com
* C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
* 01/20/2016
* C2A1E2_main.cPP
* Win7
* Visual C++ 11.0
*
* The code exercises the use of printf and the special way to handle certain characters.
*/

#include <stdio.h>
#include <stdlib.h>

#define REQ_ARGS 3
#define FILE_INDEX 1 // File name argument index
#define LINE_INDEX 2 // Number of lines to extract from file argument index
#define INVALID_ARGS "Invalid number of arguments"
#define BUFFSIZE 256

void ErrorAndDie(const char *errorMsg)
{
   perror(errorMsg);
   exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
   char *textFile, buff[BUFFSIZE];
   int numOfLines, count;
   FILE *file;

   // Verifies that the correct number of arguments are provided
   if (argc != REQ_ARGS)
      ErrorAndDie(INVALID_ARGS);

   textFile = argv[FILE_INDEX];
   // String number is converted to an int value
   numOfLines = atoi(argv[LINE_INDEX]);

   if ((file = fopen(textFile, "r")) == NULL)
      ErrorAndDie(textFile);

   // Lines are displayed per group based on number of lines set
   count = 0;
   while (fgets(buff, sizeof(buff), file))
   {
      printf("%s", buff);
      count++;

      // If first group meets its line limit, user is expected
      // to press enter to see the next group of lines
      if (count == numOfLines)
      {
         // Verfies that user clicks enter
         // If not, next group of lines are not read
         if (getchar() != '\n')
            break;

         // Reset to continue through another group of lines
         count = 0;
      }
   }

   fclose(file);
   
   return(EXIT_SUCCESS);
}
