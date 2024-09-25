/* 
   Header file for the WORDSEARCH problem.
   
   DO NOT CHANGE THE CONTENTS OF THIS FILE. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char String[80];


/* DO NOT CHANGE the #define below. NUM_WORDS is the number of words in ENABLE2K.txt */
#define  NUM_WORDS  173528


/* Function prototypes for the functions to be implemented. */


/*
   Q1: Is the word <param_str> in the list? 
       (Note: this is a searching problem. Your function should return 1 to mean “Yes, 
	   the word is in the list; otherwise, it should return 0 which means, 
	   “No, the word is not in the list”).
*/
int Q1(char * WordList[], int nSize, char * param_str); 
// note: the 2nd parameter can be rewritten as char search_key[] 


/*
   Q2: How many <param_length>-letter words that start with the 
       letter <param_char> are there in the list? (for example: gatekeeper)
*/
int Q2(char * WordList[], int nSize, int param_length, char param_char);  


/*
   Q3: How many words begins with the letter <param_begin_char>  and ends 
       with the letter <param_end_char> ? (for example: fry)
*/
int Q3(char * WordList[], int nSize, char param_begin_char, char param_end_char);


/*
    Q4: How many words are there that do not contain any vowel? 
	(for example: fry)
*/
int Q4(char * WordList[], int nSize);


/*
    Q5: How many words are there that start with the string 
	    <param_str>? (for example: unlimited)
*/
int Q5(char * WordList[], int nSize, char * param_str);


/*
    Q6 (Bonus Question): What is the longest word? 
	
	The function should return the memory address where the longest word is stored in 
	the WordList.  Thus, the function return type is char *.
*/
char * Q6(char * WordList[], int nSize);


