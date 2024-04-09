/** Hands on 1
  * Problem : Secret
  *
  * Name: <replace this with Lastname, Firstname>
  * Section: <replace this with your section>
  */

#include "secret.h"    //Do NOT remove this line

//Do NOT modify this function
void 
getInput(sentence s)
{
   char ch;
   int i = 0;
   
   do
   {
      scanf("%c", &ch);
	  if (ch != '\n')
	  {  s[i] = ch;
	     i++;
	     s[i] = '\0';
	  }
   }while (i < LEN2 && ch != '\n');   
}

//Do NOT modify this function
void 
display(arrWords aWords, int nElem)
{	int i;
	for (i = 0; i < nElem; i++)
		printf("-%s-", aWords[i]);
	printf("\n");
}

/*
   To Do : Implement this function.  [10 points] 
   
   Requirement: 1.) No printf() statements allowed in this function.
                2.) contents of s and key should not be modified

   @param d is the destination container for the encrypted result
   @param s is the source word that has to be encrypted
   @param key is the secret key
*/ 
void
Encrypt(string d, string s, string key)
{   //your code
	
}

/*
   To Do : Implement this function.  [10 points] 
   
   Requirement: 1.) No printf() statements allowed in this function.
                2.) contents of s and key should not be modified

   @param d is the destination container for the decrypted result
   @param s is the source word that has to be decrypted
   @param key is the secret key
*/ 
void
Decrypt(string d, string s, string key)
{   //your code
	
}



/* To Do: Implement this function.  [15 points]

   Store each word in s to aWords. Do not assume that 
   there is only 1 space that separates the words. Assume
   that there are only letters and spaces in s. Note that
   spaces should not be part of any content in aWords.
	
   Requirement: s should not be modified
   
   @param aWords is the destination container (array)
   @param s is assumed to contain at least one word.
   @return the total number of entries in aWords at the end of the function
*/
int
Tokenize(arrWords aWords, sentence s)
{	//your code


}

/* To Do: Implement this function.   [10 pts]
   
   This function puts together into 1 long string all contents 
   of the array of words. There is exactly 1 space between the
   words.  There should be no space before the first word and no
   space after the last word. Any previous value of s should not
   be part of the merged result.
  
   Requirement: 1.) No printf() statements allowed in this function.
                2.) contents of arrWord should not be modified
				
   @param s is the destination container (array)
   @param aWords is the source array of words 
   @param nWords is the number of initialized elements in aWords
*/
void 
Merge(sentence s, arrWords aWords, int nWords)
{
   // your code


}
