// Tim Sort
// 
// Uses Insertion Sort and Merge Sort for improved efficiency
//
// Based on the description on: https://hackernoon.com/timsort-the-fastest-sorting-algorithm-youve-never-heard-of-36b28417f399
//
// timSort:	actual algorithm
// ascTimSort:	sorts in ascending order
// descTimSort:	sorts in descending order

#include "tim.h"

#define BARRIER 64	// For lengths below this number, Tim Sort performs an Insertion Sort

void timSort (int * arr, int length, bool order)
{
	if (length < BARRIER) insertionSort (arr, length, order);
	else
	{
		
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
