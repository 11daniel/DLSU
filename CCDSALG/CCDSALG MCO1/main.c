/*
	Documentation:
	
	Record *random(size) = malloc(sizeof(Record) * size);
		- Dynamically allocates the memory to the variable due to limitations of C.
		
	readFile(random(size), "random(size).txt")
		- Opens the text files and assigns it to the variable.
		
	SortingAlgorithm(random100, random25000, random50000, random75000, random100000, almostsorted, totallyreversed);
		- Calls the menu of the chosen sorting algorithm and passes the data stored in these variables for copying.
		
	This main program is the main menu that initiates the variables which will serve as containers for the data to be passed to other functions for sorting but these variables
	will never change. Instead, they will be copied to a function's local variable. The main menu also allows the user to choose the sorting algorithm and will loop until user
	decides to quit.	
*/

#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>

// group-defined functions:
#include "groupfunctions.c"

int main()
{
	int dChoice, dFlag = 0;

	// Unsorted array. DO NOT CHANGE/SORT ITS CONTENTS!
	Record random100[100];
	Record *random25000 = malloc(sizeof(Record) * 25000);
	Record *random50000 = malloc (sizeof(Record) * 50000);
	Record *random75000 = malloc (sizeof(Record) * 75000);
	Record *random100000 = malloc (sizeof(Record) * 100000);
	Record *almostsorted = malloc (sizeof(Record) * 100000);
	Record *totallyreversed = malloc (sizeof(Record) * 100000);
	
	// Reads a text file and stores them into the arrays.
	readFile(random100, "random100.txt");
	readFile(random25000, "random25000.txt");
	readFile(random50000, "random50000.txt");
	readFile(random75000, "random75000.txt");
	readFile(random100000, "random100000.txt");
	readFile(almostsorted, "almostsorted.txt");
	readFile(totallyreversed, "totallyreversed.txt");
	
	// Loops until user decides to quit.
	do
	{
		system("cls");
		
		printf("CCDSALG MCO1\n");
		printf("SORTING ALGORITHMS\n\n");
		printf("CHOOSE YOUR ALGORITHM:\n");
		printf("[1] - Insertion Sort\n");
		printf("[2] - Selection Sort\n");
		printf("[3] - Merge Sort\n");
		printf("[4] - Comb Sort\n");
		printf("[5] - Exit\n");
		
		scanf("%d", &dChoice);
		
		// Checks for which sorting algorithm the user chooses.
		switch(dChoice)
		{
			// Calls the sorting algorithm menu if the input is valid.
			case 1:
				InsertionMenu(random100, random25000, random50000, random75000, random100000, almostsorted, totallyreversed);
				break;
			case 2:
				SelectionMenu(random100, random25000, random50000, random75000, random100000, almostsorted, totallyreversed);
				break;
			case 3:
				MergeMenu(random100, random25000, random50000, random75000, random100000, almostsorted, totallyreversed);
				break;
			case 4:
				CombMenu(random100, random25000, random50000, random75000, random100000, almostsorted, totallyreversed);
				break;
			
			// Makes the condition in while false, terminating the loop.
			case 5:
				dFlag = 1;
		}
	
	} while (dFlag == 0);
	
    return 0;
}
