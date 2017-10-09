/*
 * Emmanuel A. Castillo, U06580067
 * emmanuec@gmail.com
 * C/C++ Programming I : Fundamental Programming Concepts, 111643, Raymond L. Mitchell
 * 10/24/2015
 * C1A4E4_MaxOf.h
 * Win7
 * Visual C++ 11.0
 *
 * This header file contains 2 macro functions and 2 "inline" functions
 * to determine the max between 3 values. Within a macro and inline function,
 * one of them utilize the other function to determine its max. Long double
 * is the precision of the functions. Additionally, include guards
 * are used to prevent multi inclusion of this library file throughout an
 * application.
 */

#ifndef C1A4E4_MAXOF_H
#define C1A4E4_MAXOF_H

// The maximium is determined from the macro below.
#define mMaxOf2(A,B) ((A)>(B) ? (A):(B))
// The macro utilized the above macro to determine the maximum.
#define mMaxOf3(A,B,C) (mMaxOf2(mMaxOf2((A),(B)),(C)))

// The maximium is determined from the inline function below.
long double fMaxOf2(long double val1, long double val2)
{
   return(val1 > val2 ? val1 : val2);
}
// The inline function utilized the above inline function to determine the maximum.
long double fMaxOf3(long double val1, long double val2, long double val3)
{
   return fMaxOf2(fMaxOf2(val1, val2), val3);
}

#endif
