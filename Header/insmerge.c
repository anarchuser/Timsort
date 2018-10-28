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

#include "insmerge.h"

void IMSort (int * arr, int length, bool order)
{
	// Calls with left- and rightmost index of arr
	divide (arr, 0, length - 1, order);
}

void divide (int * arr, int left, int right, bool order)
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
		divide (arr, left, middle, order);
		divide (arr, middle + 1, right, order);
	}

	// Merges the halves together, backwards
	merge (arr, left, middle, right, order);
}
void merge (int * arr, int left, int middle, int right, bool order)
{
	// Calculate length of subarrays
	int len1 = middle - left + 1;
	int len2 = right - middle;
	
	// Create temp. copies of the subarrays
	int sub1 [len1];
	int sub2 [len2];
	cpyArr (& arr [left], len1, sub1);
	cpyArr (& arr [middle + 1], len2, sub2);

	// Initialize iterable variables for the subarrays and the main section (sub1 + sub2)
	int ind1 = 0;
	int ind2 = 0;
	int indMain = left;

	// Copy elements from the subarrays back into the main one, in accordance to order
	while (ind1 < len1 && ind2 < len2)
	{
		if ((sub1 [ind1] < sub2 [ind2]) == order)
		{
			arr [indMain] = sub1 [ind1];
			indMain++;
			ind1++;
		}
		else
		{
			arr [indMain] = sub2 [ind2];
			indMain++;
			ind2++;
		}
	}

	// Copy remaining elements from either sub1 or sub2 into arr
	if (ind1 >= len1) cpyArr (& sub2 [ind2], len2 - ind2, & arr [indMain]);
	else cpyArr (& sub1 [ind1], len1 - ind1, & arr [indMain]);
}

void ascIMSort (int * arr, int length)
{
	IMSort(arr, length, true);
}

void descIMSort (int * arr, int length)
{
	IMSort(arr, length, false);
}
