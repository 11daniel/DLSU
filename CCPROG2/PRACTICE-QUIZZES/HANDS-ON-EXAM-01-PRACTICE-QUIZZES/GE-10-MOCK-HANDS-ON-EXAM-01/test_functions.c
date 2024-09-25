/*  
  	DO NOT CHANGE THE CONTENTS OF THIS FILE!!!
  	
  	Do NOT compile JUST this file independently.
  	
	Note that if you compile JUST this file only, you will get an error that says "undefined
	reference to WinMain" (for DEVCPP users).  
	
	This file is already included in the main.c via #include.
	
	It is the main.c that you should compile to produce the main.exe file. 
*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <stdio.h>
#include <string.h>

#include "transform.h"  // make sure that you read/understand the contents of this header file


/*
	Input the contents of the MasterList[] array.
	We'll use input redirection to avoid manual keyboard input.
*/
int
ReadList(String MasterList[])
{
	int i;
	int n;
	
	scanf("%d", &n);  // assume user inputs an n <= MAXLIST
	
	for (i = 0; i < n; i++) // input the strings repesenting the creatures
		scanf("%s", MasterList[i]);
		
	return n;	// n is the actual number of elements (creatures) in the MasterList[] array.
}


/*
	Print the contents of the MasterList[] containing n elements (creatures).
*/
void
PrintList(String MasterList[], int n)
{
	int i;

	printf("%d\n", n);
	for (i = 0; i < n; i++) 
		printf("%s\n", MasterList[i]);
}


/*
	Print the current contents of the Matrix with ROWSIZE x COLSIZE number of elements.
*/
void
PrintMatrix(String Matrix[][COLSIZE])
{
	int i, j;
	
	for (i = 0; i < ROWSIZE; i++) {
		for (j = 0; j < COLSIZE; j++)
			printf("%-8s", Matrix[i][j]);
			
		printf("\n");
	}
}


/*
	This is the function that will test if the Search() function works correctly or not.
*/
void
Test_Search(String MasterList[], int n) 
{
	int i;
	int result;
	String creature;
	
	for (i = 0; i < n; i++) {  
		// these are the tests that will result into a found result
		strcpy(creature, MasterList[n-i-1]);		
		result = Search(creature, MasterList, n);   // test the Search() function here		
		printf("Test=%d: search_key=%s  result=%d\n", i+1, creature, result);
	}
	
	// this is the only test for a not found result
	strcpy(creature, "<ABC>");   // there is no <ABC> creature in the MasterList[].
	result = Search(creature, MasterList, n);  // test the Search() function here
	printf("Test= %d: search_key=%s  result=%d\n", i+1, creature, result);
	
	printf("\n\n");
}


/*
	This is the function that will test if the Spawn() function works correctly or not.
*/
void
Test_Spawn(String Matrix[][COLSIZE]) 
{
	int i, n;
	int result;
	int row, col;
	String creature;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %s", &row, &col, creature);     // note: the input data will be read via input redirection
		result = Spawn(creature, row, col, Matrix);  // test the Spawn() function here
		printf("Test=%d: result=%d\n", i+1, result);
	}
	
	printf("\n");	
	printf("Current-Matrix-Contents\n");
    PrintMatrix(Matrix);
	printf("\n\n");
}



/*
	This is the function that will test if the GetMatrixScore() function works correctly or not.
*/
void
Test_GetMatrixScore(String Matrix[][COLSIZE], String MasterList[], int n)
{
	int matrix_score;
	
	matrix_score = GetMatrixScore(Matrix, MasterList, n);
	printf("matrix_score=%d\n", matrix_score);
	printf("\n\n");	
}
	
	

/*
	This is the function that will test if the FrequencyCount() function works correctly or not.
*/
void 
Test_FrequencyCount(String Matrix[][COLSIZE], String MasterList[], int n) 
{
	int FC[MAXLIST] = {};  // sets FC elements to 0
	int i;
	
	FrequencyCount(FC, Matrix, MasterList, n);  // test the FrequencyCount() function here
	
	// print the contents of the FC[] array
	for (i = 0; i < n; i++) {
		printf("%-8s %2d\n", MasterList[i], FC[i]);
	}

	printf("\n\n");
}


/*
	This is the function that will test if the Merge() works correctly or not.
*/
void
Test_Merge(String Matrix[][COLSIZE], String MasterList[], int n) 
{
	int cells[6][4] = { 
	                    {0, 0, 1, 2},   // 1st value is row1, 2nd value is col1, 3rd value is row2, 4th value is col2
	                    {4, 3, 2, 3},
						{2, 3, 4, 4},  
						{3, 3, 1, 3},    		
						{0, 2, 3, 2},  
						{3, 2, 0, 1},   
					  };
	int i;
	int result;

    // note: there are 6 test cases	
	for (i = 0; i < 6; i++) {
		result = Merge(cells[i][0], cells[i][1], cells[i][2], cells[i][3], Matrix, MasterList, n);  // test the Merge() function here
		printf("Test=%d: result=%d\n", i+1, result);		
	}
	
	printf("\n");
	printf("Current-Matrix-Contents\n");
    PrintMatrix(Matrix);
	printf("\n\n");
}


