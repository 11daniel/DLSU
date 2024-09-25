/*
    Skeleton file for WORDSEARCH problem - for main() function.
    
    lASTNAME, FIRSTNAME: 
	SECTION: 
    DATE: 
	
    Violation of any of the RESTRICTIONS will result to point deductions. 
*/


/*
   TO DO:  change the #include below to the file with your own lastname.  For example if your lastname
   is SHAZAM, then it should be changed to #include "WORDSEARCH-SHAZAM.c".  
*/
#include "WORDSEARCH-LASTNAME.c"


/*
   You DO NOT need to understand the details of the contents of the Input_Words() function.
   What is important for you to know is that after calling this function, WordList array 
   contains all the words that were read from the ENABLE2K.txt
      
   DO not modify this function.   
*/
void
Input_Words(char *WordList[])
{
	int i;
    String word;
	char *ptr;	
	FILE *fp;
	
	fp = fopen("ENABLE2k.txt", "r");
	if (fp != NULL) {
		i = 0; 
		while ( fscanf(fp, "%s", word) == 1 )  {    // read from ENABLE2K.txt while there are data available
			ptr = malloc(strlen(word) + 1);         // malloc() is not included in CCPROG2 topics	   		
			if (ptr != NULL) {
	   	  		strcpy(ptr, word);
	   	  		WordList[i] = ptr; 
	   	  		i++;
		  	}
	   		else {
	   			fprintf(stderr, "FATAL ERROR: no more memory space. Terminating...\n");	
				fclose(fp);		
	   			exit(1);
		   	}  	  	   		   		
	   }
	   fclose(fp);
	}
	else {
		fprintf(stderr, "FATAL ERROR: ENABLE2K.txt file not found.  Inform your teacher about this.\n");
		exit(1);
	}
}


/*
   This function is for debugging only.  DO not modify this function.   
   It also serves as a HINT on how to access the words in the WordList array.
*/   
void
Print_Words(char *WordList[])
{
	int i;	

	for (i = 0; i < NUM_WORDS; i++)
		printf("%s %d\n", WordList[i], (int) strlen(WordList[i]));  // prints the word and its length
}

/* 
   Use the main() function below to test your Q1() to Q6() function definitions.
   This file is for your use only.  Modify the contents any way you want.
   
   I will NOT use it nor check it.
   
   Note that I will be using a totally different main.c file for black box testing 
   your solution.
*/

int 
main()
{
    char *WordList[NUM_WORDS];   // 1D array of string (or a 1D array of character pointers)
	
	Input_Words(WordList);     // read the contents of ENABLE2K.txt into the WordList data structure
    // Print_Words(WordList);  // this is just for debugging purpose 
  
    // Test the functions that you defined.
    printf("A1: %d\n", Q1(WordList, NUM_WORDS, "program"));  // Q1 answer
	printf("A2: %d\n", Q2(WordList, NUM_WORDS, 10, 'g'));    // Q2 answer
    printf("A3: %d\n", Q3(WordList, NUM_WORDS, 'f', 'y'));   // Q3 answer
    printf("A4: %d\n", Q4(WordList, NUM_WORDS));             // Q4 answer
    printf("A5: %d\n", Q5(WordList, NUM_WORDS, "unli"));     // Q5 answer
    printf("A6: %s\n", Q6(WordList, NUM_WORDS));             // Q6 answer	
	
	return 0;
}


