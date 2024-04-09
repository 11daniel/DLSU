/*
    Skeleton file for STRING MATRIX problem - for main() function.
	
    NAME: <TO-DO: Write Lastname, Firstname>
    SECTION:
	
    Violation of any of the RESTRICTIONS will result to point deduction. 
*/


/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <stdio.h>
#include <string.h>


/*
   TO DO:  change the #include below to the file with your own lastname.  For example if your lastname
   is SHAZAM, then it should be changed to #include "SHAZAM-MATRIX.c".  
*/
#include "LASTNAME-MATRIX.c"


/*
   This display functions are for debugging only. 
   * Do NOT not modify the following (2) functions.   
*/

/*
 Function to display a matrix containing strings
 */
void
display2D(String20 S[][SIZE], int s)
{
	int r, c;
	for(r = 0; r < s; r++)
	{
		printf("\n");
		for(c = 0; c < s; c++)
		{
			printf("%-20s", S[r][c]);
		}
	}	
}

void
display1D(String20 S[SIZE], int s)
{
	int r;
	printf("\n");
	for(r = 0; r < s; r++)
	{
		printf("%d %s\n", r+1, S[r]);
	}	
}

/* 
   Use the main() function below to test your function definitions.
   This file is for your use only.  I will NOT use it nor check it.
   
   Note that I will be using a totally different main.c file for black box testing 
   your solution.
*/
int 
main()
{
	int inputSize;  // store the square matrix size
    int pal; // store the number of palindromes
    int vow; // store the number of strings with more vowels than consonants
    
    String20 StringMatrix[SIZE][SIZE];        // 2D array to store the string input
    String20 ReverseMatrix[SIZE][SIZE];       // 2D array to store the reverse of string input
    String20 TransposeMatrix[SIZE][SIZE];     // 2D array to store the transposed string matrix
    
    String20 palindrome[SIZE*SIZE];           // 1D array to store the palindromes
    String20 vowelWords[SIZE*SIZE];           // 1D array to store words with more vowels than consonants
    
    /* You are NOT allowed to edit or add other variables for your submission. */
	  
	// HINT: use input redirection so that you do not have to type the values for scanf()
	printf("Row and column size: ");
	scanf("%d", &inputSize); // this is for the size of the square matrix; ex. 3 -> 3x3 matrix
	getMatrix(StringMatrix, inputSize);
	printf("\nORIGINAL STRINGS");
	display2D(StringMatrix, inputSize);

	generateTranspose(StringMatrix, TransposeMatrix, inputSize);
	printf("\n\nTRANSPOSED MATRIX");
	display2D(TransposeMatrix, inputSize);

	generateReverse(StringMatrix, ReverseMatrix, inputSize);
	printf("\n\nREVERSED STRINGS");
	display2D(ReverseMatrix, inputSize);

	pal = genPalindromes(StringMatrix, ReverseMatrix, inputSize, palindrome);
	printf("\n\nPALINDROMES");
	display1D(palindrome, pal);
	printf("\nTOTAL COUNT: %d", pal);

	genVowelsOverConsonants(StringMatrix, inputSize, vowelWords, &vow);
	printf("\n\nVOWELED STRINGS");
	display1D(vowelWords, vow);

	printf("\n");
    
    return 0;
}
