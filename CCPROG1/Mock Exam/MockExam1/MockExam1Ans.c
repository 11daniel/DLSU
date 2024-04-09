/******************************************
Author: <NAME OF STUDENT>

This file is to be submitted as the student's
submission for Problem 2 of HO1.
******************************************/

#include "MockExam1Ans.h"

/* This function takes in a character and will determine 
   if the fed character is a letter before the letter k, 
   inclusive of k. If the character is before the letter 
   k, the function returns a 1 result. The function 
   returns 0 otherwise.
   
   - cLetter is the letter to be checked
   
   This function is worth 0 points.
*/
int isBeforeK(char cLetter){
    return cLetter >= 'a' && cLetter <= 'k';
}

/* This function takes in a character and will determine if 
   the fed character is a vowel or not. If the character is 
   a vowel, the function returns a 1 result. The function 
   returns 0 otherwise.
   
   - cLetter is the letter to be checked
   
   This function is worth 0 points.
*/
int isVowel(char cLetter){
    return cLetter == 'a' || cLetter == 'e' || cLetter == 'i' || cLetter == 'o' || cLetter == 'u';
}

/* This function takes in a character pointer with a small 
   letter value and modifies the content of the pointer to 
   contain a capital letter equivalent. Assume that the value 
   fed is always a small letter. No need for checking.
   
   - cLetter is pointer of the letter to be modified
   
   This function is worth 0 points.
*/
void toUpperCase(char *cLetter){
    *cLetter -= ('a'-'A'); 
}

/* This function takes in four character parameters and 
   determines if the input is a palindrome or not. A 
   palindrome is a series of letters that when reversed will 
   yield the same set of letters. An example of this is 
   “tacocat” and “racecar”. The function will return 1 if the 
   set of characters has a palindrome and 0 if it is not.
   
   - c1st is the letter to be checked
   - c2nd is the letter to be checked
   - c3rd is the letter to be checked
   - c4th is the letter to be checked
   
   This function is worth 0 points.
*/
int isPalindrome(char c1st, char c2nd, char c3rd, char c4th){
    return c1st == c4th && c2nd == c3rd;
}

/* This function will compute how far the given letters are 
   from becoming a palindrome. The result should be a positive 
   integer that represents the total distance between the 
   1st & 4th and 2nd & 3rd letters. Assume all the parameter 
   values are capital letters.

   - c1st is the letter to be checked
   - c2nd is the letter to be checked
   - c3rd is the letter to be checked
   - c4th is the letter to be checked
   
   This function is worth 0 points.
*/
int computePallindromeDistance(char c1st, char c2nd, char c3rd, char c4th){
    return abs(c1st-c4th) + abs(c2nd-c3rd);
}

