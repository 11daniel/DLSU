/*
    HANDS-ON #1
    PROBLEM: STRING COUNTRIES
	
    NAME: <TO-DO: Write Lastname, Firstname>
    SECTION:
*/


/* Make sure that you read and understand the contents of the countries.h header file. */
#include "countries.h"

/*
    TO DO: 
    
    Implement the  functions defined in the countries.h header file. 
	
	You may define other functions if you want, which can be called by one or more of the 
	required functions.
	
	RESTRICTIONS:
	1. Make sure to follow the function prototypes specified in countries.h
	2. Use only the library function that we discussed in class.  Non-compliance with 
	   this restriction will make your answer incorrect, and therefore will result
	   into a score of 0.
	3. Do NOT define a main() function in this file.  The main() function definition 
	   is already in the file main.c.
	4. Do NOT add any other header files.
	
    See for example the function below...
*/


/*
 * TO DO #1
 * Write the implementation for this function. (5 points)
 * This function should get input to fill up nRows and nCols of data.
 * 
 * @param str - 2D array of strings to contain countries
 * @param nRows - number of rows to initialize with inputs
 * @param nCols - number of columns to initialize with inputs
 * 
 * Requirement/Restriction:
 * - assume there are no space in inputs
 * - inputs initialize 2D array in row-major accessing
 * - do not use printf() in this function. 
*/
void 
InputString(Str20 str[ROWS][COLS], int nRows, int nCols)
{
	
}

/*
 * TO DO #2
 * Write the implementation for this function. (5 points)
 * This function should allow the user to search a country from the elements in 1D array
 * 
 * @param array - 1D array of strings to contain countries
 * @param nElem - number of initialized elements in array
 * @param search - the key value to be searched from a2D 
 * @return the index where the key is found, otherwise return -1
 *
 * Requirements/Restrictions:
 * - use of string functions aside from the four (4) discussed in class is not allowed
 * - No printf() in this function allowed.
 * - contents in array should not be modified within the function
 */
int 
Search1D(Str20 array[], int nElem, char *search)
{

}

/*
 * TO DO #3
 * Write the implementation for this function. (10 points)
 * This function should allow the user to search a country from the elements in 2D array
 * 
 * @param a2D - 2D array of strings to contain countries
 * @param nRows - number of initialized rows in a2D
 * @param nCols - number of initialized columns in a2D
 * @param search - the key value to be searched from a2D 
 * @param rowIndexFound - address where the row index should be stored in
 * @param colIndexFound - address where the column index should be stored in
 *
 * Requirements/Restrictions:
 * - use of string functions aside from the four (4) discussed in class is not allowed
 * - No printf() in this function allowed.
 * - contents in a2D should not be modified within the function
 */
void 
SearchCountry(Str20 a2D[ROWS][COLS], int nRows, int nCols, char *search, 
              int *rowIndexFound, int *colIndexFound)
{

}

/*
 * TO DO #4
 * Write the implementation for this function. (10 points)
 * This function should generate the frequency of the string (country names) in 2D array
 * 
 * @param a2D - 2D array of strings to contain countries
 * @param nRows - number of initialized rows in a2D
 * @param nCols - number of initialized columns in a2D
 * @param array - 1D array to contain the unique countries
 * @param freq - one-dimensional array of integer of size ROWS*COLS
 * @param pElem - address where the number of initialized elements in array is stored
 *
 * Requirements/Restrictions:
 * - use of string functions aside from the four (4) discussed in class is not allowed
 * - No printf() in this function allowed.
 * - contents in a2D should not be modified within the function
*/
void 
WordFrequency(Str20 a2D[ROWS][COLS], int nRows, int nCols, Str20 array[], int freq[], int *pElem)
{

}

/*
 * TO DO #5
 * Write the implementation for this function. (15 points)
 * This function should sort the content of the array per row only
 * 
 * @param a2D - 2D array of strings to contain countries to be sorted
 * @param nRows - number of initialized rows in a2D
 * @param nCols - number of initialized columns in a2D
 * 
 * Requirements/Restrictions:
 * - use of string functions aside from the four (4) discussed in class is not allowed
 * - sort each row of the 2D array element, not the entire array elements
*/
void 
SortRowWiseString(Str20 a2D[ROWS][COLS], int nRows, int nCols)
{
	

}

/*

    DO NOT define a main() function in this file!!!
	    
    The main() function for testing your solution is already in another file named
	main.c file.

*/