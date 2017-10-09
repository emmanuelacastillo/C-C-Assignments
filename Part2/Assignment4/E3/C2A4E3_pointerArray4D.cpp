/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts, 112912, Raymond L. Mitchell
 * 02/10/2016
 * C2A4E3_pointerArray4D.cpp
 * Win7
 * Visual C++ 11.0
 *
 * Description:
 * This file defines external variables for index values for a
 * 4-dimensional pointer array. It also defines an external
 * variable for the 4-dimensional pointer array. The construction
 * of the 4-dimensional pointer array is encapsulated in this file.
 */

extern const int DIM0 = 2;
extern const int DIM1 = 3;
extern const int DIM2 = 4;
extern const int DIM3 = 5;

// Sets up the 4-dimensional array by declaring
// each dimensional block until the final one.

// First dimension set up.
static float a1[DIM3], a2[DIM3], a3[DIM3], a4[DIM3], a5[DIM3], a6[DIM3];
static float a7[DIM3], a8[DIM3], a9[DIM3], a10[DIM3], a11[DIM3], a12[DIM3];
static float a13[DIM3], a14[DIM3], a15[DIM3], a16[DIM3], a17[DIM3], a18[DIM3];
static float a19[DIM3], a20[DIM3], a21[DIM3], a22[DIM3], a23[DIM3], a24[DIM3];

// Second dimension set up.
static float *b1[DIM2] = {a1, a2, a3, a4}, *b2[DIM2] = {a5, a6, a7, a8};
static float *b3[DIM2] = {a9, a10, a11, a12}, *b4[DIM2] = {a13, a14, a15, a16};
static float *b5[DIM2] = {a17, a18, a19, a20}, *b6[DIM2] = {a21, a22, a23, a24};

// Third dimension set up.
static float **c1[DIM1] = {b1, b2, b3}, **c2[DIM1] = {b4, b5, b6};

float ***pointerArray4D[DIM0] = {c1, c2};
