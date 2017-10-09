/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 11/08/2015
 * C1A6E2_MyStrcmp.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This implementation takes in two strings and compares each char
 * value at their corresponding pointer location. An int value is
 * returned signifying whether they are equal or not.
 * Below are the type of values expected to be returned:
 * 1) string 1 equals string 2 returns 0
 * 2) string 1 is greater than string 2 returns value greater than 0
 * 3) string 1 is greater than string 2 returns value less than 0
 */
int MyStrcmp(const char *s1, const char *s2)
{
   // Both strings are compared until their chars do not match
   // or if either one results in a null value
   while ((*s1 == *s2) && (*s1 || *s2))
   {
      s1++;
      s2++;
   }

   // The difference between the pointer is return to
   // signify their relationship (equal or not equal)
   // as mentioned on description above.
   return((int)(*s1 - *s2));
}
