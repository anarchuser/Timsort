// Header of Merge Sort

#include <stdbool.h>
#include <math.h>

// Sorts an int array by reference
// argv[1]: Pointer to this array
// argv[2]: Length of array
// argv[3]: True for ascending, False for descending
void mergeSort (int * arr, int length, bool order);

// Divides arr in subarrays left..middle and middle..right and sorts them
void divide (int * arr, int left, int right, bool order);

// Merges two (sorted) subarrays together
void merge (int * arr, int left, int middle, int right, bool order);

// Sorts an array by reference, in ascending order
void ascMergeSort (int * arr, int length);

// Sorts an array by reference, in descending order
void descMergeSort (int * arr, int length);
