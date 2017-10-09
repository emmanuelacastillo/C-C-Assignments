/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/15/2015
 * C1A7E2_main.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This assignment exercises the use of stuctures and memory allocation.
 * A food structure is utilize to hold data regarding food attributes.
 * These food attributes are set from user input. The name is a special
 * attribute where memory is allocated based on the size of the name and
 * the number of bytes needed to hold it. At the end of the application
 * memory allocation is freed up.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNCH_ITEMS 5
#define LENGTH 129
#define START_ITEM 2

int main(void)
{
   struct Food
   {
      char *name;
      int weight, calories;
   } lunch[LUNCH_ITEMS] = {{"apple", 4, 100}, {"salad", 2, 80}};

   int foodCount;
   // Loop starts at non-initialized lunch item
   for (foodCount = START_ITEM; foodCount < LUNCH_ITEMS; foodCount++)
   {
      char nameInput[LENGTH];
      size_t stringSize;

      printf("Enter food name, weight, and calories:\n");
      scanf("%128s %d %d", nameInput, &lunch[foodCount].weight, &lunch[foodCount].calories);
      
      // String size is used to determine the amount of bytes needed to store name input
      stringSize = strlen(nameInput) + 1;

      // Allocate memory to lunch item based on name input's length
      if ((lunch[foodCount].name = (char*)malloc(stringSize)) == NULL)
      {
         fputs("Out of memory\n", stderr);
         exit(EXIT_FAILURE);
      }
      // Copy memory to Food structure to obtain its own copy
      memcpy(lunch[foodCount].name, nameInput, stringSize);
   }

   printf("NAME            WEIGHT   CALORIES\n");
   printf("----            ------   --------\n");
   for (foodCount = 0; foodCount < LUNCH_ITEMS; foodCount++)
      printf("%-15s%5d%10d\n", lunch[foodCount].name, lunch[foodCount].weight, lunch[foodCount].calories);

   // Free allocated memory
   for (foodCount = START_ITEM; foodCount < LUNCH_ITEMS; foodCount++)
      free(lunch[foodCount].name);

   return(EXIT_SUCCESS);
}
