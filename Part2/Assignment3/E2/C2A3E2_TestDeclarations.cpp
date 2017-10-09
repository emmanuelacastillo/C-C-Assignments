/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/03/2016
 * C2A3E2_TestDeclarations.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This program exercises the declarations of
 * sentences that utilizes the Right-Left rule
 * to describe itself.
 */

const int INDEX = 9;

void TestDeclarations()
{
   // 1: vp is a pointer to void that is initialized to 0
   void *vp = 0;
   // 2: fcnA is a function returning an int and having 
   // one int parameter named val
   int fcnA(int val);
   // 3: ppa is a pointer to a pointer to an array of INDEX floats
   float (**ppa)[INDEX];
   // 4: rppa is a reference to a pointer to a pointer 
   // to an array of INDEX floats that is initialized
   // to ppa
   float (**&rppa)[INDEX] = ppa;
   // 5: ppa is assigned to vp type cast to a 
   // pointer to a pointer to an array of INDEX floats
   ppa = (float (**)[INDEX])vp;
}
