/* 
   Header file for the STRING MATRIX problem.
   
   DO NOT CHANGE THE CONTENTS OF THIS FILE. 
*/
typedef char String20[21];

/* size of the arrays */
#define SIZE 10


/* Function prototypes for the functions to be implemented. */

// Function to get inputs
void getMatrix(String20 A[][SIZE], int s);

// Function to TRANSPOSE the string matrix
void generateTranspose(String20 A[][SIZE], String20 B[][SIZE], int s);

// Function to REVERSE each string content
void generateReverse(String20 A[][SIZE], String20 B[][SIZE], int s);

// Function to copy to the 1D array all words that are palindromes
int genPalindromes(String20 A[][SIZE], String20 B[][SIZE], int s, String20 C[]);

// Function to copy to the 1D array all words with more vowels than consonants
void genVowelsOverConsonants(String20 A[][SIZE], int s, String20 B[], int *numVoweled);
