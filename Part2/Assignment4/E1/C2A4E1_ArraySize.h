/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/09/2016
 * C2A4E1_ArraySize.h
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This file contains the array size information of a 4-dimensional array.
 * There is a element count for each dimension and a total elements of
 * all dimensions.
 */
#ifndef C2A4E1_ARRAYSIZE_H
#define C2A4E1_ARRAYSIZE_H

const int DIM0 = 10;
const int DIM1 = 7;
const int DIM2 = 6;
const int DIM3 = 8;
// The total elements is based on a formula that gets the amount of
// elements for each array set within an array. This formula
// allows for scalability because the dimensions can easily be changed
// and the total elements will not have to and still have the correct
// value.
const int TOTAL_ELEMENTS = DIM0 * DIM1 * DIM2 * DIM3;

#endif
