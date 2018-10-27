// Implementation of general functions related to sorting algorithms
//
// See header file for detailed explanation

#include "stdsort.h"

void swap (int * a, int * b)
{
	int tmp = * a;
	* a = * b;
	* b = tmp;
}

void getRandArr (int * arr, int min, int max)
{
	int length = sizeof(arr) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		arr [i] = getRandNum (min, max);
	}
}

//TODO: Fix random generator
int getRandNum (int min, int max)
{
	return (long long) rand() % (int) fabs((double) (max-min)) + min;
}
