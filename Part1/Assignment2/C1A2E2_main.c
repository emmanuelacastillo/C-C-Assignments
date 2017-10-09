/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/10/2015
 * C1A2E2_main.c
 * Win7
 * Visual C++ 11.0
 *
 * The code prints a leading character, 1 less the row number and a diagonal character after.
 * A diagonal character exists even if a leading character does not.
 * Essentially, a right angle triangle is produced.
 */

#include <stdio.h>
#include <stdlib.h>

#define LEADER_CHAR '.'
#define DIAGONAL_CHAR '%'

int main(void)
{
   int maxRows, row;

   printf("Please enter any positive decimal integer value:\n");
   scanf("%d", &maxRows);

   for (row = 0; row < maxRows; row++)
   {
      int column;
      //For each row, the number of leading character is one less the row number.
      for (column = 0; column < row; column++)
      {
         //because the small amount of characters used, putchar is used for efficiency.
         putchar(LEADER_CHAR);
      }
      //putchar is still used for consistency and also b/c of the limited amount of character outputted.
      putchar(DIAGONAL_CHAR);
      putchar('\n');
   }

   return(EXIT_SUCCESS);
}
