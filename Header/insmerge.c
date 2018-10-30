// Hybrid Insertion + Merge Sort
//
// > Splits array into smaller subarrays until they are smaller than BOUNDARY, at which point the halves are sorted by insertion sort
//
// IMSort:	actual algorithm
// ascIMSort:	sorts in ascending order
// descIMSort:	sorts in descending order
//
// Adaption from https://www.geeksforgeeks.org/merge-sort/
//
// See header file for detailed explanations

#include "config.h"
#include "insmerge.h"

void IMSort (int * arr, int length, bool order)
{
	// Calls with left- and rightmost index of arr
	divide (arr, 0, length - 1, order);
}

void split (int * arr, int left, int right, bool order)
{
	// Calculates middle between left and right boundary
	int middle = 0.5 * (left + right);
	
	if (right - left <= BOUNDARY)
	{
		// Sort the two halves with insertion sort
		insertionSort (& arr [left], middle - left + 1, order);
		insertionSort (& arr [middle + 1], right - middle, order);
	}
	else
	{
		// Splits arr recursively in half
		split (arr, left, middle, order);
		split (arr, middle + 1, right, order);
	}

	// Merges the halves together, backwards
	merge (arr, left, middle, right, order);
}

void ascIMSort (int * arr, int length)
{
	IMSort(arr, length, true);
}

void descIMSort (int * arr, int length)
{
	IMSort(arr, length, false);
}
