/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 01/26/2016
 * C2A2E2_CountIntBitsF.cpp
 * Win7
 * Visual C++ 11.0
 *
 * The below function shifts a bit value for an int type until it hits its bit limit.
 * The number of shifts determine the number of bits that exists in an
 * int type for any machine.
 */

int CountIntBitsF()
{
   int bitCount;
   unsigned int bitShifter = 1;
   // The 1 is shifted to the left until it hits the maximum
   // bits in an unsigned int type. The number of shifts
   // determines the number of bits for the machine that
   // runs this program.
   for (bitCount = 0; bitShifter != 0; bitCount++)
      bitShifter <<= 1;

   return bitCount;
}
