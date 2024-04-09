/*
    HANDS-ON #1
    PROBLEM: STRING MATRIX
	
    NAME: <TO-DO: Write Lastname, Firstname>
    SECTION:
*/


/* Make sure that you read and understand the contents of the matrix.h header file. */
#include "matrix.h"


/*
    TO DO: 
    
    Implement the 5 functions declared in the matrix.h header file. 
	
	You may define other functions if you want, which should be called by one or more of the 
	required functions.
	
	RESTRICTIONS:
	1. Make sure that you follow the function prototypes specified in matrix.h
	2. Do NOT use any display statements like printf() in any of the required function implementation.
	3. Use of input statements like scanf() can only be in the getMatrix()
	4. Use only the library function that we discussed in class and in the course notes.  Non-compliance with 
	   this restriction will make your answer incorrect, and therefore will result
	   into a score of 0.
	5. Do NOT define a main() function in this file.  The main() function definition 
	   is already in the file main.c.
	6. Do NOT add any other header files.
*/


/*
 * TO DO #1
 * Write the implementation for this function. (5 points)
 * This function should accept / read string elements given the input size.
 * There is only one input size which will be the size of both row and column.
 * Example: if s is 3, then the function will be populating the first 
 *          3 rows and first 3 columns of A.
 * 
 * @param A - square matrix where each element is a String20
 * @param s - refers to the number of rows and the number of columns to fill in A
 * 
 * Requirements/Restrictions:
 * - only this function can have a scanf()
 * - do not put any printf() statements 
 * - assume there are no space or special characters in the inputs 
     (input will only be 1 word each).  Inputs are in small letters
*/
void
getMatrix(String20 A[][SIZE], int s)
{
	/* declare your own local variables and define the body of this function. */

}

/*
 * TO DO #2
 * Write the implementation for this function. (5 points)
 * This function should transpose the given square matrix.
 * NOTE: Transpose means to change rows into columns OR columns into rows.
 * 
 * @param A - square matrix containing String20 [DO NOT MODIFY CONTENTS]
 * @param B - square matrix to store the transpose of A
 * @param s - refers to the number of initialized rows and columns in A
 *
 * Requirements/Restrictions:
 * - No printf() in this function.
 * - Contents of A should still be same after the function
*/
void
generateTranspose(String20 A[][SIZE], String20 B[][SIZE], int s)
{

}

/*
 * TO DO #3
 * Write the implementation for this function. (10 points)
 * This function should access the original square matrix and reverse all the strings in it.
 * NOTE: Reverse here will reverse each string in matrix, not the whole matrix.
 * Example: "apple" -> "elppa"
 * 
 * @param A - square matrix containing String20 [DO NOT MODIFY CONTENTS]
 * @param B - square matrix to store the reversed strings of A
 * @param s - refers to the number of initialized rows and columns in A
 * 
 * Requirements/Restrictions:
 * - use of string functions aside from the four (4) discussed in class is not allowed
 * - No printf() in this function.
 * - Contents of A should still be same after the function
**/
void
generateReverse(String20 A[][SIZE], String20 B[][SIZE], int s)
{

}

/*
 * TO DO #4
 * Write the implementation for this function. (15 points)
 * This function should access the original square and reversed matrix, check for palindromes, and store & count them.
 * 
 * @param A - square matrix containing String20 [DO NOT MODIFY CONTENTS]
 * @param B - square matrix containing the reversed strings [DO NOT MODIFY CONTENTS]
 * @param s - param s - refers to the number of initialized rows and columns in A
 * @param C - 1D array to store the palindromes
 * @return the number of elements stored in C (this is also the number of palindromes)
 *
 * Requirements/Restrictions:
 * - use of string functions aside from the four (4) discussed in class is not allowed
 * - No printf() in this function.
 * - Contents of A and B should still be same after the function
**/
int
genPalindromes(String20 A[][SIZE], String20 B[][SIZE], int s, String20 C[])
{

}

/*
 * TO DO #5
 * Write the implementation for this function. (15 points)
 * This function should access the original square matrix, identify words with more vowels than consonants, and store & count them.
 * NOTE: ASCII values (small letters only) - YOU MAY OR MAY NOT USE THIS VALUES
 * a = 97, e = 101, i = 105, o = 111, u = 117
 * 
 * @param A - square matrix containing strings of size 20 [DO NOT MODIFY CONTENTS]
 * @param s - param s - refers to the number of initialized rows and columns in A
 * @param B - 1D array to store the words with more vowels than consonants (do not include if vowels == consonants)
 * @param numVoweled - address where the number of elements in B should be stored 
 *                    (this is also referring to the number of strings with more vowels)
 *					
 * Requirements/Restrictions:
 * - use of string functions aside from the four (4) discussed in class is not allowed
 * - assume characters are only small letters
 * - do not add other functions
 * - No printf() in this function.
 * - Contents of A should still be same after the function
**/
void
genVowelsOverConsonants(String20 A[][SIZE], int s, String20 B[], int *numVoweled)
{

}


/*

    DO NOT define a main() function in this file!!!
	    
    The main() function for testing your solution is already in another file named
	main.c file.

*/
