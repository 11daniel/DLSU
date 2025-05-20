/*
    Skeleton file for Word Search problem.
	
    lASTNAME, FIRSTNAME: 
	SECTION: 
	DATE: 
	
    Violation of any of the RESTRICTIONS will result to point deduction. 
*/

/*
    TO DO #1: 
    
    Implement the SIX functions that will compute and return a number that correspond as answer
	for each question from Q1 to Q6. 
	
	You may define other functions if you want, which can be called by one or more of the 
	required functions.

	RESTRICTIONS:
	1. Make sure that you follow the function prototypes specified in population.h
	2. Do NOT call printf() or scanf() in any of the required function definition.
	3. Use only the library function that we discussed in class.  Non-compliance with 
	   this restriction will make your answer incorrect, and therefore will result
	   into a score of 0.
	4. Do NOT define a main() function in this file.  The main() function definition 
	   is already in the file main.c.
	

	
    See for example the function for answering Q1 below...
*/

/* Make sure that you read and understand the contents of the wordsearch.h header file. */
#include "wordsearch.h"

/*
    TO DO: 
    
    Implement the 6 functions that will compute and return a number that correspond as answer
	for each question from Q1 to Q6. 
	
	You may define other functions if you want, which can be called by one or more of the 
	required functions.
	
	RESTRICTIONS:
	1. Make sure that you follow the function prototypes specified in population.h
	2. Do NOT call printf() or scanf() in any of the required function definition.
	3. Use only the library function that we discussed in class.  Non-compliance with 
	   this restriction will make your answer incorrect, and therefore will result
	   into a score of 0.
	4. Do NOT define a main() function in this file.  The main() function definition 
	   is already in the file main.c.
	
    See for example the function for answering Q1 below...
*/


/*
	Q1: Is the word <param_str> in the list? 

	This is a searching problem.  The function should return 1 to mean "Yes, the word being searched
	is in the list", otherwise, it should return 0 to mean "No, it is not in the list".
	
	The example INCOMPLETE function definition below shows the appropriate return data type (int), 
	a function name and the necessary parameters to compute the answer to the question.  
	
	The param_str represents a function parameter (in this case the search key, i.e., the 
	word to search).  It is given as the third parameter in the function definition.
	
	An example function call would be: result = Search(WordList, NUM_SIZE, "program"); 
	where result is an int variable
	
	You must fill in the body of the function. DO NOT forget a return statement!
*/
int
Q1(char * WordList[], int nSize, char * param_str)
// note: the 2nd parameter can be rewritten as char search_key[] 
{
	int value = 0;
	/* declare your own local variables and define the body of this function. */
	for (int i = 0; i < nSize && value == 0; i++) {
		if (strcmp(WordList[i], param_str) == 0) {
			value = 1;
		}
	}


    return value;  /* replace this with an appropriate return statement */
}


/*
    Q2:How many <param_length>-letter words that start with the 
       letter <param_char> are there in the list? 

	An example actual question is:
 	   
	How many 10-letter words that start with the letter 'g' are there in the list? 
	
	(example word is "gatekeeper")  
*/
int 
Q2(char * WordList[], int nSize, int param_length, char param_char) {
	int count = 0;
	for (int i = 0; i < nSize; i++) {
		if ((strlen(WordList[i]) == param_length) && (WordList[i][0] == param_char)) {
			count++;
		}
	}
	return count;
}




/*
    Q3: How many words begins with the letter <param_begin_char>  and ends 
       with the letter <param_end_char> ? (for example: fry)
	
	An example actual question is:
    
    How many words begin with the letter 'q' and ends with the letter 't'?  
	
	(example word is "quit")

*/
int 
Q3(char * WordList[], int nSize, char param_begin_char, char param_end_char) {
	int count = 0;
	int i;
	for (i = 0; i < nSize; i++) {
		if (WordList[i][0] == param_begin_char && WordList[i][strlen(WordList[i]) - 1] == param_end_char) {
			count++;
		}
	}

	return count;
}




/*
	Q4: How many words are there that do not contain any vowel?  
	
	(example word: "cry")		
*/
int 
Q4(char * WordList[], int nSize) {
	int i, j;
	int vowel_count = 0;
	int count = 0;
	for (i = 0; i < nSize; i++) {
		for (j = 0, vowel_count = 0; j < strlen(WordList[i]) && vowel_count == 0; j++){
			if (WordList[i][j] == 'a' || WordList[i][j] == 'e' || WordList[i][j] == 'i' || WordList[i][j] == 'o' || WordList[i][j] == 'u'){
				count++;
				vowel_count = 1;
			}
		}
	}
	return nSize - count;
}




/*
	
    Q5: How many words are there that start with the string 
	    <param_str>? 
		
    An actual example question is:
	
		How many words are there that start with the string "unli"?   
		
		(example word is "unlimited")
	
*/
int
Q5(char * WordList[], int nSize, char * param_str) {
	int i, j;
	int count = 0;
	int nStrlength = strlen(param_str);
	int nValid = 0;
	int nMatch = 0;
	for (i = 0; i < nSize; i++) {
		nMatch = 0;
		for(j = 0; j < nStrlength; j++) {
			if (WordList[i][j] == param_str[j]){
				nMatch++;
			}
			if (nMatch == nStrlength) {
				nValid++;
			}
		}
	}
	return nValid;
}


/*
	Q6 (BONUS QUESTION): What is the longest word?   
	
	The function should return the memory address where the longest word is stored in the WordList.
	This means that the function return type is char *.
	
	Note: you should NOT manually search for this word. You have to implement the function
	that will search this word.		
*/
char * Q6(char * WordList[], int nSize) {
	int i;
	int nLength = 0;
	char* longest = NULL;

	for (i = 0; i < nSize; i++) {
		if (strlen(WordList[nLength]) < strlen(WordList[i])) {
			nLength = i;
			longest = WordList[i];
		}
	}
	return longest;
}


/*

    DO NOT define a main() function in this file!!!
	    
    The main() function for testing your solution is already in another file named
	main.c file.

*/

