// Insertion Sort
//
// insertionSort:	actual algorithm
// ascInsSort: 		sorts in ascending order
// descInsSort:		sorts in descending order
//
// See header file for detailed explanations

#include "../Header/config.h"
#include "../Header/insertion.h"

void insertionSort (int * arr, int length, bool order)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if ((arr[j] < arr[j - 1]) == order)
			{
				swap(& arr[j], & arr[j - 1]);
			}
		}
	}
}

void ascInsSort (int * arr, int length)
{
	insertionSort(arr, length, true);
}

void descInsSort (int * arr, int length)
{
	insertionSort(arr, length, false);
}
