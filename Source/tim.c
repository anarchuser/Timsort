// Tim Sort
// 
// Uses Insertion Sort and Merge Sort for improved efficiency
//
// Based on the description on: https://hackernoon.com/timsort-the-fastest-sorting-algorithm-youve-never-heard-of-36b28417f399
//
// timSort:	actual algorithm
// ascTimSort:	sorts in ascending order
// descTimSort:	sorts in descending order

#include "../Header/config"
#include "../Header/tim.h"

void timSort (int * arr, int length, bool order)
{
	if (length < BARRIER) insertionSort (arr, length, order);
	else
	{
		startTimSort (arr, length, order);
	}
		
}

void startTimSort (int * arr, int length, bool order)
{
	// Calculate minRun between 32 and 64 depending on the length of the array
	int minRun = calcMinRun (length);

	// Current position in the array
	int index = 0;

	// Initialize a stack to store runs into
	Stack stack;
	initStack (stack, 0, calcNumOfRuns (length, minRun));

	// Cache. Contains three newest elements
	Stack cache;
	initStack (cache, 0, 3);

	splitNsort (arr, length, order, 
}

// TODO Fix minRun calculation!!
int calcMinRun (int length);
{
	return MIN_RUN;
}

int calcNumOfRuns (int length, int minRun)
{
	return ceil (length / minRun);
}

void run (int * arr, int length, bool order)
{
}

void ascTimSort (int * arr, int length)
{
	timSort (arr, length, true);
}

void descTimSort (int * arr, int length)
{
	timSort (arr, length, false);
}
