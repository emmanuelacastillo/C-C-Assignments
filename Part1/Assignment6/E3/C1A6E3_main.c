/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/08/2015
 * C1A6E3_main.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This application utilizes a substring function to obtain a string sub set
 * from a given string. The substring is based on a user provided
 * start position and number of chars after.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Below is used to define the maximum length of
// a string size within a char array.
#define LENGTH 256

char *GetSubstring(const char source[], int start, int count, char result[]);

int main(void)
{
   char source[LENGTH], result[LENGTH] = {'\0'};
   int start, count;
   size_t newLineIndex;

   printf("Please enter a source string:\n");
   fgets(source, LENGTH, stdin);

   // Below is used to remove newline from the source string
   newLineIndex = strlen(source) - 1;
   if (source[newLineIndex] == '\n')
      source[newLineIndex] = '\0';

   printf("Please enter a substring start and count separated by a space:\n");
   scanf("%d %d", &start, &count);

   printf("\"%s\", %d, %d, extracts \"%s\"",
      source, start, count, GetSubstring(source, start, count, result));
   
   return(EXIT_SUCCESS);
}
