/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/03/2016
 * C2A3E3_RecordOpinions.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * RecordOpinions tallies response data from an input source. The response
 * data is an int value that is only acceptable for a specified range.
 * The program ends after a terminate indicator is inputted and the results
 * of the tally is displayed.
 */
#include <stdio.h>
#include <stdlib.h>

#define ENDPOINT 7
#define TERMINATE 8

void RecordOpinions(void)
{
   // recordCount will hold twice the number of values + 1 of the endpoint
   // to consider negative numbers. It will all initialize with 0.
   // The pointer is used to traverse around
   // the addresses that recordCount contains to display the negative value
   // responses.
   int recordCount[(2 * ENDPOINT + 1)] = { 0 }, *pointer, response, index;

   // Below tallies the response data until the TERMINATE
   // value is entered.
   do
   {
      printf("Enter a response int between %d and %d\n", -ENDPOINT, ENDPOINT);
      scanf("%d", &response);
      
      // The response will determine which index will be added from the array
      // relative to the ENDPOINT. This will allow negative responses.
      if (response >= -ENDPOINT && response <= ENDPOINT)
         ++recordCount[ENDPOINT + response];

   } while (response != TERMINATE);

   // Below, the response data is displayed.
   // Response value to the left and the number
   // of response to the right.
   printf("Rating   Response\n");
   printf("------   --------\n");

   // The pointer will point to the middle point
   // of the recordCount to start at the middle point between
   // the negative and positive part of the ENDPOINT.
   pointer = &recordCount[ENDPOINT];
   for (index = -ENDPOINT; index <= ENDPOINT; ++index)
   {
      printf("%2d %13d\n", index, *(pointer + index));
   }
}
