/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/25/2016
 * C2A6E4_List.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * The below methods does the following:
 * 1. Creates a list based on a text file.
 * 2. Displays items in the list.
 * 3. Frees memory form a list.
 */
#include <stdio.h>
#include <stdlib.h>
#include "C2A6E4_List-Driver.h"

#define BUFFSIZE 254
#define DELIMITERS " \n\t"

 // Method below is used to verify that
 // there is memory space available with the
 // give size. If not, the program will
 // terminate.
static void *SafeMalloc(size_t size)
{
   void *mallocPointer;
   // An attempt to allocate memory is done below.
   // If there is not enough memory, the program
   // terminates.
   if ((mallocPointer = malloc(size)) == NULL)
   {
      fputs("Out of memory\n", stderr);
      exit(EXIT_FAILURE);
   }
   return mallocPointer;
}

List *CreateList(FILE *fp)
{
   char buff[BUFFSIZE];
   List *current, *head;
   head = current = NULL;

   // Buffers every line in the file.
   while (fgets(buff, sizeof(buff), fp))
   {
      char *currentLine;

      // The current line will be read through for each white space
      // seperated string
      for (currentLine = buff; currentLine = strtok(currentLine, DELIMITERS); currentLine = NULL)
      {
         // A node is created that will be use to either add
         // or update an existing node
         List *node = (List *)SafeMalloc(sizeof(List));
         node->str = currentLine;
         node->count = 1;
         node->next = NULL;

         // If head is null, a new node will need to be
         // created based on the defined node.
         if (head == NULL)
         {
            current = head = node;
         }
         else
         {
            List *listPos = head;

            // Each existing list item is looked through
            // to see if a string match occurs
            do
            {
               // If string match occurs, that node
               // will only update its count
               if (listPos->str == node->str)
               {
                  listPos->count++;
                  break;
               }
               ++listPos;
            } while (listPos->next != NULL);

            // If no match occurs a new node
            // is created using the previously
            // defined node.
            if (listPos)
            {
               current = current->next = node;
            }
         }
         // The next string in the line is
         // looked through
         ++currentLine;
         puts(currentLine);
      }
   }
   fclose(fp);

   return head;
}

void PrintList(const List *head)
{
   int pos;
   // Each item in the list is displayed
   // starting at the first element.
   for (pos = 1; head != NULL; head = head->next, ++pos)
   {
      printf("%s %d ea\n", head->str, head->count);
   }
}

void FreeList(List *head)
{
   // Each item in the list
   // frees its memory.
   while (head != NULL)
   {
      List *ptr = head;
      head = ptr->next;
      free(ptr);
   }
}
