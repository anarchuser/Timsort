// Header of standard sort functions

#include <math.h>
#include <stdlib.h>

// Swaps the value of two int pointers
void swap (int * a, int * b);

// Returns the pointer to an array of random integers in the range of min to max, with specified length
// argv[1]: Number of elements in the array
// argv[2]: Minimum possible value
// argv[3]: Maximum possible value
void getRandArr (int * arr, int min, int max);

// Returns a random integer in the range of min to max
// argv[1]: Minimum possible value
// argv[2]: Maximum possible value
int getRandNum (int min, int max);
