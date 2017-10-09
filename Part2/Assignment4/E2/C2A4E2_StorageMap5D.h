/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/09/2016
 * C2A4E2_StorageMap5D.h
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * The below macro, StorageMap5D defines a storage map formula
 * for a 5-dimensional array of any type.
 */
#ifndef C2A4E2_STORAGEMAP5D_H
#define C2A4E2_STORAGEMAP5D_H

// The below macro returns the value of an element defined by the indexs of the array
// from idx0 to idx4. The macro's function pieces are split into the proceeding lines
// for readability.
#define StorageMap5D(ptr, idx0, idx1, idx2, idx3, idx4, dim1, dim2, dim3, dim4)\
(*((ptr) + (idx0)*(dim1)*(dim2)*(dim3)*(dim4)\
+ (idx1)*(dim2)*(dim3)*(dim4)\
+ (idx2)*(dim3)*(dim4)\
+ (idx3)*(dim4)\
+ (idx4)))

#endif
