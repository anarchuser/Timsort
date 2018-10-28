// Header of Tim Sort

#include "stdsort.h"
#include "insertion.h"
#include "merge.h"

#include <stdbool.h>

// Sorts an int array by reference, using Insertion Sort and Merge Sort
// argv[1]: Pointer to this array
// argv[2]: Length of array
// argv[3]: True for ascending, False for descending
void timSort (int * arr, int length, bool order);

// Sorts an array by reference, in ascending order
void ascTimSort (int * arr, int length);

// Sorts an array by reference, in descending order
void descTimSort (int * arr, int length);

