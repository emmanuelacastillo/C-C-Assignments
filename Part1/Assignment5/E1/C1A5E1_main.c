/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/01/2015
 * C1A5E1_main.c
 * Win7
 * Visual C++ 11.0
 *
 * This program collects data of user rating values on a particular product.
 * It contains a maximum amount of respondents as well as a range of rating values.
 * Lastly, it contains a maximum of out of range values until the survey is ended.
 * An array is used to collect the user rating data.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_RESPONDENTS 5
#define MIN_RESPONSE_VALUE 1
#define MAX_RESPONSE_VALUE 100
#define OUT_OF_RANGE_LIMIT 3
#define RESPONSE_VALUES (MAX_RESPONSE_VALUE - MIN_RESPONSE_VALUE + 1)

int main(void)
{
   int responseCount = 1, ratingCounters[RESPONSE_VALUES] = {0}, currentResponse,
      consecutiveRangeErrors = 0, ratingCount;

   // Below is the loop to handle the survey response.
   while (responseCount <= MAX_RESPONDENTS && consecutiveRangeErrors < OUT_OF_RANGE_LIMIT)
   {
      printf("[Respondant %d] Please rate the product between the range %d and %d:\n", 
            responseCount, MIN_RESPONSE_VALUE, MAX_RESPONSE_VALUE);

      scanf("%d", &currentResponse);

      // Validates the user input
      if (currentResponse >= MIN_RESPONSE_VALUE && currentResponse <= MAX_RESPONSE_VALUE)
      {
         // If user input is valid, it adds a count to the rating value and reinitialize the error count to 0
         // Response value is subtracted by min response value so that the array
         // can properly handle any min and max values
         ratingCounters[currentResponse - MIN_RESPONSE_VALUE]++;
         consecutiveRangeErrors = 0;
         // Additionally, it continues to the next respondent by adding a count to the response count
         responseCount++;
      } 
      else 
      {
         // If user input is out of range, the same respondent is asked for a different input.
         printf("%d is out of range.\n", currentResponse);
         // Also, the range error count is increased
         consecutiveRangeErrors++;
      }
   }

   // Survey results is shown below of the rating values and the number of responses.
   for (ratingCount = 0; ratingCount < RESPONSE_VALUES; ratingCount++)
   {
      printf("Rating     Responses\n");
      printf("------     ---------\n");
      // Min response value is added to rating count to display the correct rating value
      printf("%4d%12d\n", ratingCount + MIN_RESPONSE_VALUE, ratingCounters[ratingCount]);
   }

   return(EXIT_SUCCESS);
}
