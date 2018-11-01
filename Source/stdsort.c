// Implementation of general functions related to sorting algorithms
//
// See header file for detailed explanation

#include "../Header/config.h"
#include "../Header/stdsort.h"
/*
void initStack (Stack stack, int index, int runSize)
{
	stack.index = index;
	stack.length = runSize;
}

void push (Run run, Stack stack)
{
	stack [stack.index] = run;
	index++;
}
*/
void swap (int * a, int * b)
{
	int tmp = * a;
	* a = * b;
	* b = tmp;
}

void pprint (int * arr, int length)
{
	printf("{");
	for (int i = 0; i < length; i++)
	{
		printf("%i", arr [i]);
		if (i < length - 1) printf(", ");
	}
	printf("}\n");
}

void cpyArr (int * source, int length, int * target)
{
	for (int i = 0; i < length; i++)
	{
		target [i] = source [i];
	}
}

int strToInt (char * str, int length)
{
	int sum = 0;
	int factor = 1;

	for (int i = length - 2; i >= 0; i--)
	{
		sum += factor * (str [i] - 48);
		factor = factor * 10;
	}
	return sum;
}		

void getRandArr (int * arr, int length, bool refresh)
{
	if (refresh) initRandNum (length);

	// Open that file for read
	FILE * fp = fopen ("randNums.txt", "r");
	
	// Max length (32768) of int in string representation
	char number [6];
	int numIndex = 0;
	int arrIndex = 0;

	// Iterate over it and add the ints to the arr
	for (char c = fgetc (fp); c != EOF; c = fgetc (fp)) 
	{
		if (c >= '0' && c <= '9')
		{
			number [numIndex] = c;
			numIndex++;
		}
		else if (c == '\n')
		{
			// Add word to arr
			arr [arrIndex] = strToInt (number, 6);
			arrIndex++;
			
			// Reset word
			number [0] = '\0';
			numIndex = 0;
		}
	}
}

void initRandNum (int amount)
{
	// Use BASH to generate random ints inside randNums.txt
	system ("echo $RANDOM > randNums.txt");
	for (int i = 0; i < amount - 2; i++)
	{
		system("echo $RANDOM >> randNums.txt");
	}
}

// TODO Add Boundaries
int getRandNum ()
{
	int * tmp;
	getRandArr (tmp, 1, true);
	return tmp [0];
}
