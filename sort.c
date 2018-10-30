#include "Header/config.h"

#include <sys/resource.h>
#include <sys/time.h>

double calculate(const struct rusage *b, const struct rusage *a);

int main (int argc, char * argv [])
{
	struct rusage before, after;

	char * prgm = argv [0];
	if (argc != 4 && argc != 3)
	{
		printf("Syntax: %s [algorithm] [arrLength] [sortingOrder]\nOR %s [arrLength] [sortingOrder]\n", prgm, prgm);
		return 1;
	}
	else if (argc == 4)
	{
		char * length = argv [2];
		int LENGTH = strToInt (length, 9);

		int arr [LENGTH];
		getRandArr (arr, LENGTH, true);	
	
		//pprint (arr, LENGTH);
	
		// Getting arguments
		char * sort = argv [1];
		bool order = argv[3];
		printf("Starting '%s' algorithm...\n", sort);
	
		getrusage (RUSAGE_SELF, & before);	// Save time before start
		if (strcmp(sort, "insertion") == 0) insertionSort (arr, LENGTH, order);
		else if (strcmp(sort, "merge") == 0) mergeSort (arr, LENGTH, order);
		else if (strcmp(sort, "insmerge") == 0) IMSort (arr, LENGTH, order);
		else printf("%s not found\n", sort);//timSort (arr, LENGTH, order);
		getrusage (RUSAGE_SELF, & after);	// Save time after start
	
		printf("Time in seconds: %lf\n", calculate (& before, & after));
	}
	else
	{
		char * length = argv [1];
		int LENGTH = strToInt (length, 6);
		bool order = argv [2];
		int arr [LENGTH];
		getRandArr (arr, LENGTH, false);
		
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
				case 0:
					printf("Testing Merge Sort...\n");
					getrusage (RUSAGE_SELF, &before);
					mergeSort (arr, LENGTH, order);
					getRandArr (arr, LENGTH, false);
					break;
				/*case 1:
					printf("Testing Insertion Sort...\n");
					getrusage (RUSAGE_SELF, &before);
					insertionSort (arr, LENGTH, order);
					getRandArr (arr, LENGTH, false);
					break;*/
				case 2:
					printf("Testing Insertion-Merge - Hybrid...\n");
					getrusage (RUSAGE_SELF, &before);
					IMSort (arr, LENGTH, order);
					getRandArr (arr, LENGTH, false);
					break;
			}
			getrusage (RUSAGE_SELF, &after);
			printf("Time in seconds: %lf\n", calculate (& before, & after));
		}
	}

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
