/**
 * @file
* @brief bbFloorDiv contains functions for integer division, rounding toward negative infinity.
*/
#include "headers/bbSystemIncludes.h"
#include "headers/bbPrintf.h"

/** Calculate the largest integer not greater than a/b */
static int32_t bbFloorDiv (int32_t a , int32_t b){

	if (b == 0) {
		bbDebug("divide by 0\n");
		return INT32_MIN;
	}

	int32_t c = a / b;

	if (a % b == 0) return c;

	if ((a < 0 && b > 0) || (a > 0 && b < 0)) return (c - 1);

	return c;

}

/** Calculate the largest integer not greater than a/b if b > 0*/
static int32_t bbFloorDivPlus (int32_t a , int32_t b){

	if (b == 0) {
		bbDebug("divide by 0\n");
		return INT32_MIN;
	}

	int32_t c = a / b;

	if (a % b == 0) return c;

	if (a < 0) return (c - 1);

	return c;

}




#ifndef FLOORDIV
#ifndef FLOORDIV



