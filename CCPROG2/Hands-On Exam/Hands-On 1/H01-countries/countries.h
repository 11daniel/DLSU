/* 
   Header file for the COUNTRIES problem.
   
   DO NOT CHANGE THE CONTENTS OF THIS FILE. 
*/

//size of the arrays 
#define ROWS 10
#define COLS 5
#define SIZE 20

typedef char Str20[21];

/* Function prototypes for the functions to be implemented. */

// Function to get input (name of the countries) from the user 
void InputString(Str20 a2D[ROWS][COLS], int nRows, int nCols);

// Function to search a string (country name) and return index where it is found. Otherwise, return -1
int Search1D(Str20 array[], int nElem, char *search);

// Function to search a string (country name) in a2D and updates via the parameter the indices where it is found
void SearchCountry(Str20 a2D[ROWS][COLS], int nRows, int nCols, char *search, int *rowIndexFound, int *colIndexFound);

// Function to get the unique countries and their frequency 
void WordFrequency(Str20 a2D[ROWS][COLS], int nRows, int nCols, Str20 array[], int freq[], int *pElem);

// Function to sort the 2D array of strings by row 
void SortRowWiseString(Str20 a2D[ROWS][COLS], int nRows, int nCols);
