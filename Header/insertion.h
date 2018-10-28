// Header of Insertion Sort

#include "stdsort.h"

#include <stdbool.h>

// Sorts an int array by reference
// argv[1]: Pointer to this array
// argv[2]: Length of array
// argv[3]: True for ascending, False for descending
void insertionSort (int * arr, int length, bool order);

// Sorts an array by reference, in ascending order
void ascInsSort (int * arr, int length);

// Sorts an array by reference, in descending order
void descInsSort (int * arr, int length);
