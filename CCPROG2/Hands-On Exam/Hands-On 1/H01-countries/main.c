/*
    Skeleton file for COUNTRIES problem - for main() function.
	
    NAME: <TO-DO: Write Lastname, Firstname>
    SECTION:
	
    Violation of any of the RESTRICTIONS will result to point deduction. 
*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <stdio.h>
#include <string.h>

/*
   TO DO:  change the #include below to the file with your own lastname.  For example if your lastname
   is CORDOVA, then it should be changed to #include "CORDOVA-Countries.c".  
*/
#include "LASTNAME-Countries.c"

/*
   These display functions are for debugging only. 
   Do NOT not modify the following (2) functions.   
*/

void 
PrintOutput(Str20 a2D[ROWS][COLS], int nR, int nC)
{
	int i,j;
	printf("\nList of Favorite Countries:\n");
	 for(i=0; i<nR;i++)
	 {
	 	for(j=0; j<nC;j++)
	 	{
	 		printf("%s\t ", a2D[i][j]);
		}   
		printf("\n");	
	 }
}

void PrintOutput2(Str20 oneStr[ROWS*COLS],int freq[ROWS*COLS], int nElem)
{
    int i;
    for (i = 0; i < nElem; i++)
    {
          printf("%s : %d\n", oneStr[i], freq[i]);
    }

}

//This file will not be submitted.
int
main()
{
   Str20 a2D[ROWS][COLS]; // 2D array containing the strings (country names) entered by the user
 //  char search[SIZE+1]; // 1D array to store string (country name)to be searched in the 2D array
   Str20 array[ROWS*COLS]; // 1D array that contains 1D array of strings (country names)
   int freq[ROWS*COLS]; // 1D array to store the frequency of the string (country name)
   int nRows, nCols;
   int ind1, ind2;
   
    // HINT: use input redirection so that you do not have to type the values for scanf()

	scanf("%d %d ", &nRows, &nCols); //get input for the number of rows and columns to initialize
	
    printf("Enter name of countries you want to visit: \n");
    InputString(a2D, nRows, nCols);  
    printf("\n");
    PrintOutput(a2D, nRows, nCols); 


    printf("Search a Country you want to visit:\n");
	//Testing the Search1D()
	ind1 = Search1D(a2D[1], nCols, "Sweden");
	if (ind1 != -1)
		printf("%s found in index %d\n", "Sweden", ind1);
	else printf("%s not found in row %d\n", "Sweden", 1);
	
	ind2 = Search1D(a2D[2], nCols, "Sweden");
	if (ind2 != -1)
		printf("%s found in index %d\n\n", "Sweden", ind2);
	else printf("%s not found in row %d\n", "Sweden", 2);
	
	//Testing the SearchCountry
	SearchCountry(a2D, nRows, nCols, "Sweden", &ind1, &ind2); 
	if (ind1 != -1 && ind2 != -1)
		printf("%s found in row %d col %d\n", "Sweden", ind1, ind2);
	else printf("%s not found in your list of favorite countries\n", "Sweden");

	SearchCountry(a2D, nRows, nCols, "Thailand", &ind1, &ind2); 
	if (ind1 != -1 && ind2 != -1)
		printf("%s found in row %d col %d\n", "Thailand", ind1, ind2);
	else printf("%s not found in your list of favorite countries\n", "Thailand");
	
    printf("\n");

    
    printf("Frequency of each string (country name) from the 2D array:\n");
    WordFrequency(a2D, nRows, nCols, array, freq, &ind1); 
    printf("\n");
    PrintOutput2(array,freq, ind1); 

  
    printf("\n Sorted Array of String in Row-Wise technique \n");
    SortRowWiseString(a2D, nRows, nCols);  
    PrintOutput(a2D, nRows, nCols); 

	return 0;
}
