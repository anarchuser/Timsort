// Header of Hybrid Insertion + Merge Sort

#ifndef INSMERGE_H_
#define INSMERGE_H_

#include "config.h"

#define BOUNDARY 32

// Sorts an int array by reference
// argv[1]: Pointer to this array
// argv[2]: Length of array
// argv[3]: True for ascending, False for descending
void IMSort (int * arr, int length, bool order);

// Divides arr in subarrays left..middle and middle..right and sorts them
void split (int * arr, int left, int right, bool order);

// Sorts an array by reference, in ascending order
void ascIMSort (int * arr, int length);

// Sorts an array by reference, in descending order
void descIMSort (int * arr, int length);

#endif
