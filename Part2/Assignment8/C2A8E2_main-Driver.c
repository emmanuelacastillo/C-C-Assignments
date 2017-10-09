
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
   int a = 1, b = 1, c = 1;
   int count = 0;
   while (count == 0)
   {
      int b = 2, c = 2, d = 2;
      
      printf("b = %d, c = %d, d = %d", b, c, d);

      while (count == 0)
      {
         int c = 3, d = 3, e = 3;
         count++;
      }
      printf("b = %d, c = %d, d = %d", b, c, d);
   }
   printf("b = %d, c = %d", b, c);
   return EXIT_SUCCESS;
}