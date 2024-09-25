/*
    Header file for TRANSFORM problem.
    
    Do NOT change this file.
*/

/* CONCENTRATE only on Lines 12 to 38; you need not be concerned with the other lines. */
#ifndef TRANSFORM

    #define TRANSFORM (1)

	// DO NOT change the three #defines below
	#define MAXLIST 20
	#define ROWSIZE 5
	#define COLSIZE 5

	// DO NOT change the following typedef
	typedef char String[9];
	
	
	// function prototypes for the functions that the student need to define in the source file LASTNAME_TRANSFORM.c
	int Search(String creature, String MasterList[], int n);
	int Spawn(String creature, int row, int col, String Matrix[][COLSIZE]);
	int GetMatrixScore(String Matrix[][COLSIZE], String MasterList[], int n);
	void FrequencyCount(int FC[], String Matrix[][COLSIZE], String MasterList[], int n);
	int Merge(int row1, int col1, int row2, int col2, String Matrix[][COLSIZE], String MasterList[], int n);


	// the definitions for the following functions are already provided in test_functions.c file
	// they will be used for testing the student's solution
	int ReadList(String MasterList[]);	
	void PrintList(String MasterList[], int n);
	void PrintMatrix(String Matrix[][COLSIZE]);

	void Test_Search(String MasterList[], int n);
	void Test_Spawn(String Matrix[][COLSIZE]);
	void Test_FrequencyCount(String Matrix[][COLSIZE], String MasterList[], int n);
	void Test_Merge(String Matrix[][COLSIZE], String MasterList[], int n);	

#endif

