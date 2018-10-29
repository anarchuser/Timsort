#include "Header/stdsort.h"
#include "Header/insertion.h"
#include "Header/insmerge.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>

double calculate(const struct rusage *b, const struct rusage *a);

int main (int argc, char * argv [])
{
	char * prgm = argv [0];
	if (argc != 4)
	{
		printf("Syntax: %s [algorithm] [arrLength] [sortingOrder]\n", prgm);
		return 1;
	}

	char * length = argv [2];
	int LENGTH = strToInt (length, 6);

	int arr [LENGTH];
	getRandArr(arr, LENGTH);
	
	//pprint (arr, LENGTH);
	
	char * sort = argv [1];
	bool order = argv[3];

	printf("Starting '%s' algorithm...\n", sort);

	struct rusage before, after;

	getrusage (RUSAGE_SELF, & before);

	if (strcmp(sort, "insertion") == 0) insertionSort (arr, LENGTH, order);
	else if (strcmp(sort, "merge") == 0) mergeSort (arr, LENGTH, order);
	else if (strcmp(sort, "insmerge") == 0) IMSort (arr, LENGTH, order);
	else printf("%s not found\n", sort);//timSort (arr, LENGTH, order);
	
	getrusage (RUSAGE_SELF, & after);

	printf("Time in seconds: %lf\n", calculate (& before, & after));

	//pprint (arr, LENGTH);

	return 0;
}

// Taken from cs50's pset5 speller.c implementation
double calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                  (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                 ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                  (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}
