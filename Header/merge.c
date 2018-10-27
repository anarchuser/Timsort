// Merge Sort
//
// mergeSort:		actual algorithm
// ascMergeSort:	sorts in ascending order
// descMergeSort:	sorts in descending order
//
// Adaption from https://www.geeksforgeeks.org/merge-sort/
//
// See header file for detailed explanations

#include "stdsort.h"
#include "merge.h"

#include <stdio.h>

void mergeSort (int * arr, int length, bool order)
{
	divide(arr, 0, length - 1, order);
}

void divide (int * arr, int left, int right, bool order)
{

	return;/*
	// Check wether the right boundary is larger than the left one; otherwise length(arr) equals one
	if (left < right)
	{
		// Gets middle of arr as start of first and end of second subarray
		int middle = ceil(0.5 * (left + right));

		// Divide arr recoursively into smaller subarrays
		divide (arr, left, middle, order);
		divide (arr, middle + 1, right, order);
		
		// Merges the subarrays together
		merge(arr, left, middle, right, order);
	}*/
}
void merge (int * arr, int left, int middle, int right, bool order)
{
	// Length of the subarrays and the main one
	int len1 = middle - left;
	int len2 = right - (middle + 1);
	int lenMain = right - left;

	// temporary subarrays
	int sub1 [len1], sub2 [len2];

	// Copying of the subsequences of arr to the temporary ones
	for (int a = 0; a < len1; a++)
	{
		sub1 [a] = arr [left + a];
	}
	for (int b = 0; b < len2; b++)
	{
		sub2 [b] = arr [(middle + 1) + b];
	}
	
	// Indices of the two temp. subarrays to iterate over
	int ind1 = 0;
	int ind2 = 0;

	// Iterating over both subarrays; choosing the smaller/larger element
	for (int indMain = left; indMain < lenMain; indMain++)
	{
		// Chooses from which stack to take element from. Takes element from sub1 if:
		// There are elements avaible AND
		// the next element from sub1 is larger/smaller than the one of sub2 or
		// there is no element left in sub2
		if (ind1 < len1 && (((sub1 [ind1] > sub2 [ind2]) == order) || ind2 >= len2))
		{
			arr [indMain] = sub1 [ind1];
			ind1++;
		}
		else
		{
			arr [indMain] = sub2 [ind2];
			ind2++;
		}
	}
}

void ascMergeSort (int * arr, int length)
{
	mergeSort(arr, length, true);
}

void descMergeSort (int * arr, int length)
{
	mergeSort(arr, length, false);
}
