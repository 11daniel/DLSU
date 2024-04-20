#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.c"

// Header file for comb sort
#include <stdbool.h>

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

/*
	Please see Group Report for Proper References of the original/unmodified sorting algorithm codes.
*/
void merge(Record *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    Record *L = malloc(sizeof(Record)*n1);
	Record *R = malloc(sizeof(Record)*n2);
 
    // Copy data to temp arrays
    // L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back
    // into arr[l..r]
    // Initial index of first subarray
    i = 0;
 
    // Initial index of second subarray
    j = 0;
 
    // Initial index of merged subarray
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].idNumber <= R[j].idNumber)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements
    // of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }	
}

// Website for Insertion Sort Code: https://www.geeksforgeeks.org/c-program-for-insertion-sort/
// 									https://www.programiz.com/dsa/insertion-sort
void insertionSort(Record *arr, int n)
{
	int i, j;
	Record key;

	for (i = 1; i < n; i++)
	{
		key = arr[i];
		
		j = i - 1;
		
		// Compare key with each element on the left of it until an element smaller
		// than it is found.
		while (j >= 0 && arr[j].idNumber > key.idNumber)
		{
			arr[j+1] = arr[j];
			j = j - 1;
		}
		
		arr[j+1] = key; 
	}
}

// Website for Selection Sort: https://www.geeksforgeeks.org/selection-sort/
void selectionSort(Record *arr, int n) 
{
	int i, j, min;
	Record temp;
	
	for (i = 0; i < n-1; i++)
	{
		// minimum index
		min = i;
		
		// traverse array to find minimum value
		for(j = i+1; j < n; j++)
		{
			if(arr[j].idNumber < arr[min].idNumber)
				min = j;
		}
		
		// swap if minimum value is not the same as starting value
		if (min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

// Website for Merge Sort: https://www.geeksforgeeks.org/c-program-for-merge-sort/
void mergeSort(Record arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/

// Website for Comb Sort: https://www.programmingalgorithms.com/algorithm/comb-sort/c/
// https://www.youtube.com/watch?v=n51GFZHXlYY
void combSort(Record *arr, int n)
{
	// gap is the size
	double gap = n;
	
	// swaps is initiated to true
	bool swaps = true;
	
	// counter variables
	int igap, i;
	
	// temporary array
	Record temp;
	
	while (gap > 1 || swaps)
	{
		
		// computes for gap
		gap /= 1.247330950103979;
		
		// gap is 1 if it is less than 0
		if (gap < 1)
			gap = 1;
		
		// initializes i to 0 like normal bubble sort and swaps to false.
		i = 0;
		swaps = false;
		
		while (i + gap < n)
		{
			igap = i + (int) gap;
			
			// swaps if idNumber of array index i is greater than the array index gap
			if (arr[i].idNumber > arr[igap].idNumber)
			{
				temp = arr[i];
				arr[i] = arr[igap];
				arr[igap] = temp;
				swaps = true;
			}
			
			i++;
		}
	}
}









#endif
