/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/08/2015
 * C1A6E3_GetSubstring.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * The substring of an input is determined based on a start position and
 * the number of chars after. The part of a string is copied over to a pointer
 * to char variable and returned.
 */
char *GetSubstring(const char source[], int start, int count, char result[])
{
   char *subString = result;

   // substring start location is determined
   // by the pointer location incremented a
   // number of times based on the start value
   while (*source && start > 0)
   {
      source++;
      start--;
   }

   // the location of the source pointer
   // is copied to the results pointer
   // until the count value is below 0
   // or the source pointer hits a null value
   while (*source && count > 0)
   {
      *result++ = *source++;
      count--;
   }


   // Like a normal string in a pointer
   // to char variable, a null value
   // is added to results
   *result = '\0';

   // value is returned based on a copy of the results pointer
   return(subString);
}
