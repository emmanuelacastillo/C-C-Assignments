/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/14/2015
 * C1A3E1_main.c
 * Win7
 * Visual C++ 11.0
 *
 * This code calculates the factorial of a number that is inputted from a user.
 * 
 * ABOVE 12! ISSUE EXPLANATION:
 * ---------------------------------------------------------------------------------------------
 * ISSUE - When the factorial of 13 or higher is calculated the values are incorrect. The reason
 * is the memory allocation that the data type we are using, long int. Long int is 32 bits
 * which has a range of 0L - 2147483647L. This is below the expected value for 13! and above.
 *
 * SOLUTION - One main solution is using a different data type that holds are higher amount of bits.
 * A long long int data type will be sufficient but again, there will be a point where 
 * the factorial of a number will surpass the data type's maximum number of bits and start
 * producing invalid values.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   long factorialMulti, currentMulti, multiResult;

   printf("Enter any integer value greater than 0\n");
   scanf("%ld", &factorialMulti);

   printf("nbr         nbr!\n");
   printf("----------------\n");

   //Factorial of inputted integer is calculated.
   for (currentMulti = 1, multiResult = 1; currentMulti <= factorialMulti; currentMulti++)
   {
      multiResult *= currentMulti;

      printf("%2ld%13ld\n", currentMulti, multiResult);
   }

   return(EXIT_SUCCESS);
}
