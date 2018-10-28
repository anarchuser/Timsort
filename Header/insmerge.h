// Header of Hybrid Insertion + Merge Sort

#include "stdsort.h"
#include "insertion.h"

#include <stdbool.h>

#define BOUNDARY 16

// Sorts an int array by reference
// argv[1]: Pointer to this array
// argv[2]: Length of array
// argv[3]: True for ascending, False for descending
void IMSort (int * arr, int length, bool order);

// Divides arr in subarrays left..middle and middle..right and sorts them
void divide (int * arr, int left, int right, bool order);

// Merges two (sorted) subarrays together
void merge (int * arr, int left, int middle, int right, bool order);

// Sorts an array by reference, in ascending order
void ascIMSort (int * arr, int length);

// Sorts an array by reference, in descending order
void descIMSort (int * arr, int length);
