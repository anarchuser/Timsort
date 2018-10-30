// Header of Tim Sort

#ifndef TIM_H_
#define TIM_H_

#define BARRIER 64	// For lengths below this number, perform Insertion Sort
#define MIN_RUN 64	// TODO Delete this.

// Sorts an int array by reference, using Insertion Sort and Merge Sort
// argv[1]: Pointer to this array
// argv[2]: Length of array
// argv[3]: True for ascending, False for descending
void timSort (int * arr, int length, bool order);

// Actual algorithm
void startTimSort (int * arr, int length, bool order);

// Algorithm to calculate the MinRun Size
int calcMinRun (int length);

// Calc number of runs depending on the length of the array and MinRun
int calcNumOfRuns (int length, int minRun);

// looks for strictly decreasing/increasing subarrays + reverses them
void run (int * arr, int length, bool order);

// Sorts an array by reference, in ascending order
void ascTimSort (int * arr, int length);

// Sorts an array by reference, in descending order
void descTimSort (int * arr, int length);

#endif
