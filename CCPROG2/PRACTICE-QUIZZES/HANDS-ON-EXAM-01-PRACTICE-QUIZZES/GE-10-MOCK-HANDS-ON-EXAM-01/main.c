/*
    This is main.c file.  It contains the main() function for the TRANSFORM problem.
	
	DO the following to test your LASTNAME-TRANSFORM.c solution: 
	
	1. Edit Line 40 below to include your own source file.
	2. Compile this main.c file to produce main.exe.  Make sure to use -Wall compiler directive!
	3. If there are no compilation errors and/or warnings, go to the Command Line Interface via CMD. 
	4. Run main.exe in the command line with I/O redirection as follows:
   
           	main < INPUT.txt > LASTNAME-ACTUAL.txt           	

	   where INPUT.txt is an accompanying sample text files that contain input data 
	   read via scanf() in the ReadWords() function.

       For example, if your lastname is SANTOS, you should run main.exe as:
	   
       		main < INPUT.txt > SANTOS-ACTUAL.txt
		      
    5. Using Notepad (or other text editors), open and compare your LASTNAME-ACTUAL.txt with the 
	   contents of the accompanying EXPECTED.TXT file. They should be exactly the same -- even the spacing!
	   If they are not the same, then there's a strong probability that there's a logical error in your 
	   solution, or you did not follow some specifications.  

	6. Debug and retry until you get the correct results.    
	   
	7. Devise your own tests. Do NOT simply depend on the sample INPUT and EXPECTED text files.
*/

/* Do NOT change  the #include below.  You are NOT allowed to include other files. */
#include <stdio.h>
#include <string.h>

#include "transform.h"  // make sure that you read/understand the contents of this header file

/*
    TO DO: change the #include below to your own file/solution. For example if your 
	lastname is SANTOS, then it should be changed to #include "SANTOS-TRANSFORM.c".
*/	
#include "LASTNAME-TRANSFORM.c"

#include "test_functions.c"  // read/understand the contents of this C file

/*
    This is the main() function for testing your solution.  
	
	You are not supposed to modify the contents and the logic of this function.
    
    If you need to experiment, i.e. you'd like to edit/introduce new codes, then it is suggested that you
	copy this file, and make changes on your copy.
	
	Note that the teacher-in-charge of checking your solution may use another set of input data 
	and a different main() function.  
	
	Your functions should work correctly even with a different set of input data and a different main() function.
*/	
int main()
{
    int nList;	// number of creatures in the MasterList
	String MasterList[MAXLIST];
	String Matrix[ROWSIZE][COLSIZE] = {};   

	
	nList = ReadList(MasterList);  // read data via input redirection
	printf("MasterList[] contents\n");
	PrintList(MasterList, nList);
	printf("\n\n");
	
	
	// Test the functions that the student defined.
	printf("**01-Test-Search()**\n");
	Test_Search(MasterList, nList);

	printf("**02-Test-Spawn()**\n");
	Test_Spawn(Matrix);
	
	printf("**03-Test-GetMatrixScore()**\n");   
	Test_GetMatrixScore(Matrix, MasterList, nList);
	
	printf("**04-Test-FrequencyCount()**\n");   	 
	Test_FrequencyCount(Matrix, MasterList, nList);
	
	printf("**05-Test-Merge()**\n");
	Test_Merge(Matrix, MasterList, nList);
	
	return 0;	
}
