// Header of standard sort functions

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Swaps the value of two int pointers
void swap (int * a, int * b);

// Pretty-prints the given array
void pprint (int * arr, int length);

// Returns a str as an int
int strToInt (char * str, int length);

// Returns the pointer to an array of random integers in the range of min to max, with specified length
// argv[2]: Number of elements in the array
// argv[3]: Specifies wether to refresh the txt file
void getRandArr (int * arr, int length, bool refresh);

// Refreshs txt file randNum.txt containing an array of 'random' numbers
void initRandNum (int amount);

// Returns a random integer in the range of min to max
// argv[1]: Minimum possible value
// argv[2]: Maximum possible value
int getRandNum ();

// Copies 'length' elements from source arr into target location
void cpyArr (int * source, int length, int * target);
