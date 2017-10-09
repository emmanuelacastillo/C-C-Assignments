/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 03/07/2016
 * C2A8E2_DisplayModifiedSingleReals.c
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * DisplayModifiedSingleReals processes binary values that
 * represents floating points and grabs 4 bytes at a time. From those bytes, a
 * single real value is obtained. It is than evaluated
 * whether it is a normalized, denormalized, zero, infinity
 * or a NAN value. After, it file content and its type
 * is displayed.
 */
#include <stdio.h>
#include <math.h>
#include <limits.h>

 // Single Real Types
#define F_NORM    1
#define F_DENORM  2
#define F_PZERO   3
#define F_NZERO   (-F_PZERO)
#define F_PINF    4
#define F_NINF    (-F_PINF)
#define F_PNAN    5
#define F_NNAN    (-F_PNAN)

// Single Real Names
#define NORM   "Normal"
#define DENORM "Denormal"
#define ZERO   "Zero"
#define PINF   "+INF"
#define NINF   "-INF"
#define PNAN   "+NAN"
#define NNAN   "-NAN"
#define OTHER  ""

// Single Real Constants
// is determining the single
// real type
#define SIGN_MASK 0x80000000uL
#define EXP_MASK  0x7FC00000uL
#define FRAC_MASK 0x003FFFFFuL
#define FRAC_BITS 22
#define EXP_NBIAS 255
#define EXP_DBIAS 254
#define EXP_MAX   511
#define READ_BYTES 4
#define BASE 2.0

void DisplayPatternInfo(unsigned long allBytes);
int EvalSingleReal(unsigned long pattern, double *result);

void DisplayModifiedSingleReals(FILE *inFile)
{
   // separateBytes is placed as a buffer for the
   // bytes in the file that represents a floating point.
   unsigned char separateBytes[READ_BYTES];
   // allBytes will hold the current set of 4 bytes
   // from separateBytes.
   unsigned long allBytes = 0;

   // The file is read until EOF
   while (fread(&separateBytes, READ_BYTES, 1, inFile) > 0)
   {
      int byteIndex;

      // If the number of bytes is less than the expected
      // number of read bytes, a message is displayed
      // and the file read ends.
      if (sizeof(separateBytes) < READ_BYTES)
      {
         printf("Unexpected EOF");
         break;
      }

      // If a 4 byte read was successful, the bytes are
      // placed in a long data type (allBytes).
      for (byteIndex = 0; byteIndex < READ_BYTES; ++byteIndex)
      {
         allBytes <<= CHAR_BIT;
         allBytes |= separateBytes[byteIndex];
      }

      // The bytes are evaluated and displayed.
      DisplayPatternInfo(allBytes);
   }
   // File is closed after all 4 sets of bytes are read.
   fclose(inFile);
}

void DisplayPatternInfo(unsigned long allBytes)
{
   // Place holder of the evaluated real value
   // of the provided bytes.
   double singleRealValue;
   // Place holder for the name of the real value type.
   char *singleRealName;

   // The set of 4 byptes are evaluated for its actual value
   // and single real type.
   int singleRealType = EvalSingleReal(allBytes, &singleRealValue);

   // A name is specified base on the set of bytes real type.
   switch (singleRealType)
   {
      case F_NORM:
         singleRealName = NORM;
         break;
      case F_DENORM:
         singleRealName = DENORM;
         break;
      case F_PZERO:
      case F_NZERO:
         singleRealName = ZERO;
         break;
      case F_PINF:
         singleRealName = PINF;
         break;
      case F_NINF:
         singleRealName = NINF;
         break;
      case F_PNAN:
         singleRealName = PNAN;
         break;
      case F_NNAN:
         singleRealName = NNAN;
         break;
      default:
         singleRealName = OTHER;
   }

   // Normalized, denormalized and zero types are displayed weith its actual value
   if (singleRealName == NORM || singleRealName == DENORM || singleRealName == ZERO)
      printf("%#010lx  %+e  %s\n", allBytes, singleRealValue, singleRealName);
   else
      // Otherwise, it only displays its name because the actual value is too large
      printf("%#010lx  %s\n", allBytes, singleRealName);
}

int EvalSingleReal(unsigned long pattern, double *result)
{
   // Evaluates the sign of the set of bytes used for its calculation.
   int signIsNegative = !!(SIGN_MASK & pattern);
   // Determines the exponent of the bytes used for its calculation.
   int exponent = (EXP_MASK & pattern) >> FRAC_BITS;
   // Determines the fraction of the bytes used for its calculation.
   long fraction = FRAC_MASK & pattern;
   int status;

   // When an exponent or fraction is zero
   // it signifies the value as a zero type
   if (exponent == 0 && fraction == 0)
   {
      status = signIsNegative ? F_NZERO : F_PZERO;
      *result = 0;
   }
   // When an exponent meets the max and the fraction is zero
   // it signifies the value as infinity
   else if (exponent == EXP_MAX && fraction == 0)
      status = signIsNegative ? F_NINF : F_PINF;
   // When an exponent meets the max and the fraction is not zero
   // it signifies the value as not a number (NAN)
   else if (exponent == EXP_MAX && fraction != 0)
      status = signIsNegative ? F_NNAN : F_PNAN;
   // Otherwise, the value is either normalized or denormalized.
   else
   {
      int bias;
      // The initial calculates occur that are both required
      // for normalized and denormalized types.
      *result = fraction * pow(BASE, -FRAC_BITS);

      // If exponent is not 0, it signifies
      // a normalized type.
      if (exponent != 0)
      {
         bias = EXP_NBIAS;
         status = F_NORM;
         // The result is incremented
         // to take inconsideration of the
         // implicit 1 for normalize type.
         ++*result;
      }
      else
      {
         bias = EXP_DBIAS;
         status = F_DENORM;
      }
      // Final calculates occur to determine
      // the actual value.
      *result *= pow(BASE, exponent - bias);

      // The result's actual sign is placed
      // before it returns.
      if (signIsNegative)
         *result = -*result;
   }
   return(status);
}
