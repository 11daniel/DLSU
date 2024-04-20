#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Assign whole arrays to another directly is impossible in C so this is necessary.
void arrayAssignment(Record *source, Record *destination, int size)
{
	int i;
	
	for (i = 0; i < size; i++)
		destination[i] = source[i];
}

// Prints the array
void testPrint(Record *array, int size)
{
	int i;
	
	system("cls");
	
	for (i = 0; i < size; i++)
		printf("ID Number: %d Name: %s\n", array[i].idNumber, array[i].name);
	
	system("pause");
}

/*
	General Documentation for the SortingAlgorithmMenu Functions:
	
	Note: The structure is the same for all sorting algorithms so this documentation applies to all functions below.
	
	void SortingAlgorithmMenu(Record *random100, Record *random25000, Record *random50000, Record *random75000, Record *random100000, Record *almostsorted, Record *totallyreversed)
		@parameters are the arrays with the unsorted dataset passed from main.
		
		Record *data(number) = malloc(sizeof(Record) * size);
			- The array to store the dataset passed to the function. This is the array to be sorted and its contents will also be shown.
			
		scanf("%d", &dChoice);
			- Prompts user on which dataset the sorting algorithm should be implemented on.
			
		switch(dChoice)
			-checks for the sorting algorithm number to be implemented
		
		case (number):
			arrayAssignment(sourceArray, sourceDestination, size); 
				- assigns the array passed to the function to the array to be sorted.
			
			// the block of code initiates the timer and calls the sorting algorithm.
			startTime = currentTimeMillis();
			nameOfSort(@parameters); 
			endTime = currentTimeMillis();
			
			// computes for the executionTime
			executionTime = endTime - startTime;
			
			// Shows the execution time and prompts if the user wants to inspect the array
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataAlmostsorted, 100000);
				
			break;
		
		
*/
void InsertionMenu(Record *random100, Record *random25000, Record *random50000, Record *random75000, Record *random100000, Record *almostsorted, Record *totallyreversed)
{
	int dChoice;
	long startTime, endTime, executionTime;
	char dYesOrNo;
	Record data100[100];
	Record *data25000 = malloc(sizeof(Record) * 25000);
	Record *data50000 = malloc(sizeof(Record) * 50000);
	Record *data75000 = malloc(sizeof(Record) * 75000);
	Record *data100000 = malloc(sizeof(Record) * 100000);
	Record *dataAlmostsorted = malloc(sizeof(Record) * 100000);
	Record *dataTotallyreversed = malloc (sizeof(Record) * 100000);
	
	
	system("cls");
	printf("Which data set do you want to use insertion sort?\n");
	printf("[1] - Almost Sorted\n");
	printf("[2] - Random 100\n");
	printf("[3] - Random 25000\n");
	printf("[4] - Random 50000\n");
	printf("[5] - Random 75000\n");
	printf("[6] - Random 100000\n");
	printf("[7] - Totally Reversed\n");
	scanf("%d", &dChoice);
	
	switch(dChoice)
	{
		case 1:
			arrayAssignment(almostsorted, dataAlmostsorted, 100000); 
			
			startTime = currentTimeMillis();
			insertionSort(dataAlmostsorted, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataAlmostsorted, 100000);
				
			break;
			
		case 2:
			arrayAssignment(random100, data100, 100);
			
			startTime = currentTimeMillis();
			insertionSort(data100, 100);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data100, 100);
			
			break;
			
		case 3:
			arrayAssignment(random25000, data25000, 25000);
			
			startTime = currentTimeMillis();
			insertionSort(data25000, 25000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data25000, 25000);

			break;
		
		case 4:
			arrayAssignment(random50000, data50000, 50000);
			
			startTime = currentTimeMillis();
			insertionSort(data50000, 50000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data50000, 50000);
			
			break;
		
		case 5:
			arrayAssignment(random75000, data75000, 75000);
			
			startTime = currentTimeMillis();
			insertionSort(data75000, 75000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data75000, 75000);
			break;
		
		case 6:
			arrayAssignment(random100000, data100000, 100000); 
			
			startTime = currentTimeMillis();
			insertionSort(data100000, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data100000, 100000);
			break;
			
		case 7:
			arrayAssignment(totallyreversed, dataTotallyreversed, 100000); 
			
			startTime = currentTimeMillis();
			insertionSort(dataTotallyreversed, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataTotallyreversed, 100000);
			
			break;
		
		default:
			printf("INVALID INPUT\n");
			system("pause");
	}
}

void SelectionMenu(Record *random100, Record *random25000, Record *random50000, Record *random75000, Record *random100000, Record *almostsorted, Record *totallyreversed)
{
	int dChoice;
	long startTime, endTime, executionTime;
	char dYesOrNo;
	Record data100[100];
	Record *data25000 = malloc(sizeof(Record) * 25000);
	Record *data50000 = malloc(sizeof(Record) * 50000);
	Record *data75000 = malloc(sizeof(Record) * 75000);
	Record *data100000 = malloc(sizeof(Record) * 100000);
	Record *dataAlmostsorted = malloc(sizeof(Record) * 100000);
	Record *dataTotallyreversed = malloc(sizeof(Record) * 100000);
	
	system("cls");
	printf("Which data set do you want to use selection sort?\n");
	printf("[1] - Almost Sorted\n");
	printf("[2] - Random 100\n");
	printf("[3] - Random 25000\n");
	printf("[4] - Random 50000\n");
	printf("[5] - Random 75000\n");
	printf("[6] - Random 100000\n");
	printf("[7] - Totally Reversed\n");
	scanf("%d", &dChoice);
	
	switch(dChoice)
	{
		case 1:
			arrayAssignment(almostsorted, dataAlmostsorted, 100000);
			
			startTime = currentTimeMillis(); 
			selectionSort(dataAlmostsorted, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataAlmostsorted, 100000);
				
			break;
			
		case 2:
			arrayAssignment(random100, data100, 100);
			
			startTime = currentTimeMillis();
			selectionSort(data100, 100);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data100, 100);
			
			break;
			
		case 3:
			arrayAssignment(random25000, data25000, 25000);
			
			startTime = currentTimeMillis();
			selectionSort(data25000, 25000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data25000, 25000);
			break;
		
		case 4:
			arrayAssignment(random50000, data50000, 50000);
			
			startTime = currentTimeMillis();
			selectionSort(data50000, 50000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data50000, 50000);
				
			break;
		
		case 5:
			arrayAssignment(random75000, data75000, 75000);
			
			startTime = currentTimeMillis();
			selectionSort(data75000, 75000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data75000, 75000);
				
			break;
		
		case 6:
			arrayAssignment(random100000, data100000, 100000);
			
			startTime = currentTimeMillis(); 
			selectionSort(data100000, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data100000, 100000);
				
			break;
			
		case 7:
			arrayAssignment(totallyreversed, dataTotallyreversed, 100000);
			
			startTime = currentTimeMillis(); 
			selectionSort(dataTotallyreversed, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataTotallyreversed, 100000);
				
			break;
		
		default:
			printf("INVALID INPUT\n");
			system("pause");
	}
}

void MergeMenu(Record *random100, Record *random25000, Record *random50000, Record *random75000, Record *random100000, Record *almostsorted, Record *totallyreversed)
{
	int dChoice;
	long startTime, endTime, executionTime;
	char dYesOrNo;
	
	Record data100[100];
	Record *data25000 = malloc(sizeof(Record) * 25000);
	Record *data50000 = malloc(sizeof(Record) * 50000);
	Record *data75000 = malloc(sizeof(Record) * 75000);
	Record *data100000 = malloc(sizeof(Record) * 100000);
	Record *dataAlmostsorted = malloc(sizeof(Record) * 100000);
	Record *dataTotallyreversed = malloc(sizeof(Record) * 100000);
	
	system("cls");
	printf("Which data set do you want to use merge sort?\n");
	printf("[1] - Almost Sorted\n");
	printf("[2] - Random 100\n");
	printf("[3] - Random 25000\n");
	printf("[4] - Random 50000\n");
	printf("[5] - Random 75000\n");
	printf("[6] - Random 100000\n");
	printf("[7] - Totally Reversed\n");
	scanf("%d", &dChoice);
	
	switch(dChoice)
	{	
		case 1:
			arrayAssignment(almostsorted, dataAlmostsorted, 100000);
			
			startTime = currentTimeMillis();
			mergeSort(dataAlmostsorted, 0, 100000-1);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;

			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataAlmostsorted, 100000);
			
			break;
			
		case 2:
			arrayAssignment(random100, data100, 100);
			
			startTime = currentTimeMillis();
			mergeSort(data100, 0, 99);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;

			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data100, 100);
			
			break;
			
		case 3:
			arrayAssignment(random25000, data25000, 25000);
			
			startTime = currentTimeMillis();
			mergeSort(data25000, 0, 25000-1);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;

			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data25000, 25000);
			
			break;
		
		case 4:
			arrayAssignment(random50000, data50000, 50000);
			
			startTime = currentTimeMillis();
			mergeSort(data50000, 0, 50000-1);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;

			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data50000, 50000);
			
			break;

		case 5:
			arrayAssignment(random75000, data75000, 75000);
			
			startTime = currentTimeMillis();
			mergeSort(data75000, 0, 75000-1);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;

			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data75000, 75000);
			
			break;
			
		case 6:
			arrayAssignment(random100000, data100000, 100000);
			
			startTime = currentTimeMillis();
			mergeSort(data100000, 0, 100000-1);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;

			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data100000, 100000);
			
			break;
		
		case 7:
			arrayAssignment(totallyreversed, dataTotallyreversed, 100000);
			
			startTime = currentTimeMillis();
			mergeSort(dataTotallyreversed, 0, 100000-1);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;

			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataTotallyreversed, 100000);
			
			break;
		
		default:
			printf("INVALID INPUT\n");
			system("pause");
	}
}

void CombMenu(Record *random100, Record *random25000, Record *random50000, Record *random75000, Record *random100000, Record *almostsorted, Record *totallyreversed) 
{
	int dChoice;
	long startTime, endTime, executionTime;
	char dYesOrNo;
	Record data100[100];
	Record *data25000 = malloc(sizeof(Record) * 25000);
	Record *data50000 = malloc(sizeof(Record) * 50000);
	Record *data75000 = malloc(sizeof(Record) * 75000);
	Record *data100000 = malloc(sizeof(Record) * 100000);
	Record *dataAlmostsorted = malloc(sizeof(Record) * 100000);
	Record *dataTotallyreversed = malloc(sizeof(Record) * 100000);
	
	system("cls");
	printf("Which data set do you want to comb sort?\n");
	printf("[1] - Almost Sorted\n");
	printf("[2] - Random 100\n");
	printf("[3] - Random 25000\n");
	printf("[4] - Random 50000\n");
	printf("[5] - Random 75000\n");
	printf("[6] - Random 100000\n");
	printf("[7] - Totally Reversed\n");
	scanf("%d", &dChoice);
	
	switch(dChoice)
	{
		case 1:
			arrayAssignment(almostsorted, dataAlmostsorted, 100000); 
			
			startTime = currentTimeMillis();
			combSort(dataAlmostsorted, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataAlmostsorted, 100000);

			break;
			
		case 2:
			arrayAssignment(random100, data100, 100);
			
			startTime = currentTimeMillis();
			combSort(data100, 100);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data100, 100);
			
			break;
			
		case 3:
			arrayAssignment(random25000, data25000, 25000);
			
			startTime = currentTimeMillis();
			combSort(data25000, 25000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data25000, 25000);
			
			break;
		
		case 4:
			arrayAssignment(random50000, data50000, 50000);
			
			startTime = currentTimeMillis();
			combSort(data50000, 50000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data50000, 50000);
				
			break;
		
		case 5:
			arrayAssignment(random75000, data75000, 75000);
			
			startTime = currentTimeMillis();
			combSort(data75000, 75000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data75000, 75000);
				
			break;
		
		case 6:
			arrayAssignment(random100000, data100000, 100000); 
			
			startTime = currentTimeMillis();
			combSort(data100000, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(data100000, 100000);

			break;
			
		case 7:
			arrayAssignment(totallyreversed, dataTotallyreversed, 100000); 
			
			startTime = currentTimeMillis();
			combSort(dataTotallyreversed, 100000);
			endTime = currentTimeMillis();
			
			executionTime = endTime - startTime;
			
			printf("\nExecution Time: %ld\n\n", executionTime);
			printf("Do you want to see the sorted algorithm? (Press Y for Yes and any other for no)\n");
			
			fflush(stdin);
			
			scanf("%c", &dYesOrNo);
			if (dYesOrNo == 'Y' || dYesOrNo == 'y')
				testPrint(dataTotallyreversed, 100000);

			break;
		
		default:
			printf("INVALID INPUT\n");
			system("pause");
	}
}
