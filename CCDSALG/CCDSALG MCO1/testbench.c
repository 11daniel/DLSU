/*
	Notes:
	1. struct record is size 504 bytes.
*/

#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// group-defined functions:
#include "groupfunctions.c"


int main ()
{
	Record arr[5];
	
	readFile(arr, "test.txt");
	
	selectionSort(arr, 5);
	
	testPrint(arr, 5);
	
	return 0;
}
