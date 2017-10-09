/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 01/26/2016
 * C2A2E2_Rotate.cpp
 * Win7
 * Visual C++ 11.0
 *
 * The below function rotates an unsigned object based on the provided
 * number of counts. Bits of the object moves either left or right. Any
 * that goes beyond the number of bits of the data type is moved to the other
 * end of the bits.
 *
 */
int CountIntBitsF();

unsigned Rotate(unsigned object, int count)
{
   // If count is less than one, the object is rotated left, so it is shifted left.
   // An OR operation is used on a mask that represents the bits that would have
   // rotated to the other end of the number of bits. The bits that would have
   // rotated is the same as shifting the object right the amount based on
   // the total bit minus the amount of shifts that occurred on the left.
   // This is the mask used to obtain the rotated bits of the object.
   if (count < 0)
      return((object << (-count)) | (object >> (CountIntBitsF() - (-count))));
   // Below uses the same concept except vice versa for counts greater than 0.
   if (count > 0)
      return((object >> count) | (object << (CountIntBitsF() - count)));

   // If count is neither less or greater than 0, the object
   // will not be shifted and itself is returned.
   return object;
}
