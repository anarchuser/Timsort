// Header of standard sort functions

#ifndef STDSORT_H_
#define STDSORT_H_

// Structure to store runs in (used by e.g. Tim Sort)
// * ptr:	pointer to where the run is in an array
// length:	length of this run
typedef struct run
{
	int * ptr;
	int length;
} Run;

// Structure to store runs structured >> stack
// * run:	Array of elements in the stack
// index:	Next free index to put an element into
// length:	Max number of elements in stack
typedef struct stack
{
	Run * run;
	int index;
	int length;
} Stack;

// Initializes stack with index as 0
void initStack (Stack stack, int index, int runSize);

// Pushes an element (Run) on top of the stack
void push (Run run, Stack stack);

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

#endif
