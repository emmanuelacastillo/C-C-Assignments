/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/25/2016
 * C2A6E3_DisplayClassStatus.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * The below utilizes qsort and bsearch to properly
 * search and compare sets of student names.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compare(const void *elemA, const void *elemB)
{
   // A comparison of expected pointers to arrays to chars
   // is done using strcmp.
   return strcmp(*(char **)elemA, *(char **)elemB);
}

void SortStudents(const char *studentList[], size_t studentCount)
{
   // qsort handles the sorting of the students based on the
   // Compare method.
   qsort(studentList, studentCount, sizeof(const char *), Compare);
}

void DisplayClassStatus(const char *registrants[], size_t registrantCount,
                        const char *attendees[], size_t attendeeCount)
{
   int regIndex, attendeeIndex;

   printf("Not present:\n");
   // Each registrant is search through the attendees
   // and the ones not found are displayed.
   for (regIndex = 0; regIndex < (int)registrantCount; regIndex++)
   {
      char *item = (char *)bsearch(&registrants[regIndex], attendees,
                                sizeof(attendees) / sizeof(attendees[0]), 
                                sizeof(attendees[0]), Compare);

      if (item == NULL)
         printf("%s\n", registrants[regIndex]);
   }

   printf("Not registered:\n");
   // Each attendee is search through the registrants
   // and the ones not found are displayed.
   for (attendeeIndex = 0; attendeeIndex < (int)attendeeCount; attendeeIndex++)
   {
      char *item = (char *)bsearch(&attendees[attendeeIndex], registrants,
         sizeof(registrants) / sizeof(registrants[0]),
         sizeof(registrants[0]), Compare);

      if (item == NULL)
         printf("%s\n", attendees[attendeeIndex]);
   }
}
