/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 01/24/2016
 * C2A2E1_CountBitsM.h
 * Win7
 * Visual C++ 11.0
 *
 * This header file contains the macro to determine
 * the number of bits of an object or type for any machine
 * it runs on.
 */

#ifndef C2A2E1_COUNTBITSM_H
#define C2A2E1_COUNTBITSM_H

#include <limits.h>

// CHAR_BIT is used to determine the number of bytes in a bit 
// for any machine that runs this program
#define CountBitsM(objectOrType) (CHAR_BIT*(int)sizeof(objectOrType))

#endif
