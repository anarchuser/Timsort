#include "Header/stdsort.h"
#include "Header/insertion.h"
#include "Header/merge.h"

#include <stdio.h>

#define LENGTH 36

int main ()
{
	//int arr [LENGTH] = {8,6,4,2,7,5,3,1};
	int arr [LENGTH] = {4,35,76,34,12,10,3,98,8,67,58,17,26,39,75,86,14,36,97,48,76,38,16,24,28,68,75,94,55,17,33,21,11,99,17,31};
	//int arr [LENGTH];
	//getRandArr (& arr [0], 0, 100);
	
	printf("{");
	for (int i = 0; i < LENGTH; i++)
	{
		printf("%i, ", arr[i]);
	}
	printf("}\n");
	
	//ascInsSort (arr, LENGTH);
	ascMergeSort (arr, LENGTH);
	
	printf("{");
	for (int i = 0; i < LENGTH; i++)
	{
		printf("%i, ", arr[i]);
	}
	printf("}\n");

	return 0;
}
