/*    
	Do NOT forget to include your name and section below.
	
	lASTNAME, FIRSTNAME: ____________________        SECTION: _____
	
	DO NOT define a main() function in this file.  The main() function definition is already 
	given in the accompanying main.c file.
	
	Note that if you compile JUST this file only, you will get an error that says "undefined
	reference to WinMain" (for DEVCPP users).  
	
	You'll have to include this file first in main.c via #include, and then it is the main.c 
	that you you should compile to produce the main.exe file.
	
    Violation of any of the RESTRICTIONS or non-compliance with the specifications will result to point deductions. 
*/


/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "transform.h"   // make sure that you read & understand the contents of this header file

/*
	RESTRICTION: Do not use any string library function not discussed in our class or Course Notes.  
	You are limited to using only four string functions, specifically: 
	
			strlen(), strcpy(), strcat() and strcmp()  
	
	A solution that does not comply with this restriction will be considered an incorrect solution, 
	and therefore, the score for the required function will be zero.
*/

/*
	You may define any number of helper functions that you deem necessary below this comment.
	You are free to decide on the function return type, name, and parametrization of your helper functions.
*/


/*
	TO DO #1: implement Search() as described in the problem specs.
	
	creature is the search key
    MasterList[] is a 1D array of strings that contains the names of ALL the creatures in the game.
    n is the number of creatures in the MasterList[].	
*/
int 
Search(String creature, String MasterList[], int n)
{
	/* 
		Declare your own local variables. 	   
	   	Do NOT call printf() or scanf() in this function. 
	*/


	return 888;  // Do NOT forget to return a value. You'll need to change 888.
}


/*
	TO DO #2: implement Spawn() as described in the problem specs.
	
	creature is the string to be stored in the Matrix with the specified row and column indices.
*/
int
Spawn(String creature,  int row, int col, String Matrix[][COLSIZE])
{
	/* 
		Declare your own local variables. 	   
	   	Do NOT call printf() or scanf() in this function. 
	*/

	return 888;  // Do NOT forget to return a value. You'll need to change 888.
}


/*
	TO DO #3: implement GetMatrixScore() as described in the problem specs.
	
	Matrix is the 2D array containing the creatures
	MasterList[] is a 1D array of strings that contains the names of ALL the creatures in the game.
    n is the number of creatures in the MasterList[].	
*/
int 
GetMatrixScore(String Matrix[][COLSIZE], String MasterList[], int n)
{
	/* 
		Declare your own local variables. 	   
	   	Do NOT call printf() or scanf() in this function. 
	   
	   You have to use the macros COLSIZE and ROWSIZE in your solution.
	   
	   HINTS: 
	   a. To compute 2^level, call the pre-defined math function pow() as pow(2, level).
	      For example, if level = 10, then pow(2, level) computes 2^10 which is equal to 1024. 
	
	   b. Call Search() function to determine the index or level of a creature.
	*/

	  
	return 888;  // Do NOT forget to return a value. You'll need to change 888.
}


/*
	TO DO #4: implement FrequencyCount() as described in the problem specs.

	FC is the 1D array of counters.  Assume that the elements of FC are initialized to 0 prior to calling this function.
	Matrix is the 2D array containing the creatures
	MasterList[] is a 1D array of strings that contains the names of ALL the creatures in the game.
    n is the number of creatures in the MasterList[].
*/
void 
FrequencyCount(int FC[], String Matrix[][COLSIZE], String MasterList[], int n)
{	
	/* 
		Declare your own local variables. 	   
	   	Do NOT call printf() or scanf() in this function. 
	   
	   You have to use the macros COLSIZE and ROWSIZE in your solution.
	*/

	
}


/*
	TO DO #5: implement Merge() as described in the problem specs.
	
	row1 and col1 are the indices of the 1st creature
	row2 and col2 are the indices of the 2nd creature
	Matrix is the 2D array containing the creatures
	MasterList[] is a 1D array of strings that contains the names of ALL the creatures in the game.
    n is the number of creatures in the MasterList[].
*/
int 
Merge(int row1, int col1, int row2, int col2, String Matrix[][COLSIZE], String MasterList[], int n)
{
	/* 
		Declare your own local variables. 	   
	   	Do NOT call printf() or scanf() in this function. 

		HINT:
	    a. Call Search() function to determine the index or level of a creature.
	*/


	return 888;  // Do NOT forget to return a value. You'll need to change 888.
}


/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.  

    The main() is in the accompanying main.c source file.
    
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
********************************************************************************/

