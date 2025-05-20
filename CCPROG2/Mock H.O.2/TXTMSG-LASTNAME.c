/* 
    This is the skeleton file that you need to use as base code for the TXTMSG problem.
	
	Encode your Name and Section below.
	    
    LASTNAME, FIRSTNAME: _____________________
    SECTION: _________
	
	DO NOT define a main() function in this file.  The main() function definition 
	is provided in the accompanying file TXTMSG-main-LASTNAME.c.

    MAKE SURE THAT the solution/program you are submitting does not have:
       * a compilation error
	   * a compilation warning
	   * a logical error
	
	If there is a compilation error, the score will be 0 point.	   
*/


/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "inbox.h"  // READ and UNDERSTAND the contents of this header file.  DO NOT change this line.
#include "loader-txtmsg.c"   // you need not really be concerned with the contents of this file. 


/*
    TO DO #1: 
    
    Implement the 5 functions that will compute and return a number that correspond as answer
	for each question from Q1 to Q5. 

    Except for Q1, the function prototype (i.e., return type, function name, and parameter list)
    for answering questions Q2 to Q5 are not given.  You have to figure it out on your own
    as part of your solution.
	
	RESTRICTIONS:
	1. Do NOT call printf() and scanf() in any of the required function definition.
	2. Do NOT use any unnecessary parameter.  The function parameters should only be those 
	   that are necessary to implement the function.
	   
    See for example the function for answering Q1 below...
*/





/*
	You may define other functions that can be called by the functions you need
	to answer questions Q1 to Q5.
*/






/* 
   	Q1: Is inbox <inbox_number> full? Return 1 to mean yes it is full, otherwise return 0.
     
   	Assume that the array of structures Inbox[] already have contents.
   
   	RESTRICTION: Do not use scanf() or printf().
*/
int 
Q1(struct inboxTag Inbox[], int inbox_number) 
{	
   int nRet;
   int i;
   if(Inbox[inbox_number].n_msgs >= MAX_INBOX_SIZE)
	   nRet = 1;
   else
	   nRet = 0;
	   
    return nRet;;  /* replace -1 with the appropriate return value */
}


/*
   	Q2: Who sent the most recent message in inbox <inbox_number>?  (answer is the cel number of the sender)

   	Assume that the array of structures Inbox[] already have contents.
  
   	RESTRICTION: Do not use scanf() or printf().
*/
void swap(struct msgTag *a, struct msgTag *b)
{
	struct msgTag temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sortDate(struct msgTag M[], int nMessage)
{
	int i, j, min;
	for(i = 0; i < nMessage - 1; i++)
	{
		//printf("%d %d %d %d\n ", M[i].sender, M[i].date.month, M[i].date.year, M[i].date.day);
		min = i;
		for(j = i + 1; j < nMessage; j++)
		{
			if(M[min].date.year > M[j].date.year)
				min = j;
			else if(M[min].date.year == M[j].date.year && M[min].date.month > M[j].date.month)
				min = j;
			else if(M[min].date.year == M[j].date.year && M[min].date.month == M[j].date.month && M[min].date.day > M[j].date.day)
				min = j;
			else if(M[min].date.year == M[j].date.year && M[min].date.month == M[j].date.month && M[min].date.day == M[j].date.day && M[min].sender > M[j].sender)
				min = j;
		}
		if(i != min)
			swap(&M[i], &M[min]);
	}
	
	
}
int Q2(struct msgTag M[], int nMessage)
{
	//Sort the messages by the date, year, then month, then day, return the cell number of the holder
	sortDate(M, nMessage);
	
	return M[nMessage-1].sender;
}




/*
   	Q3: How many unread messages are there in inbox <inbox_number>?

   	Assume that the array of structures Inbox[] already have contents.
  
   	RESTRICTION: Do not use scanf() or printf().   
*/

int Q3(struct msgTag M[], int nMessage)
{
	int unread = 0;
	int i;
	for(i = 0; i < nMessage; i++)
		if(M[i].read_flag == 0)
			unread++;
		
	return unread;
}



/*
	Q4: What is the string length of the most recent message in inbox <inbox_number>?

	Assume that the array of structures Inbox[] already have contents.
  
   	RESTRICTION: Do not use scanf() or printf().
*/
int Q4(struct msgTag M[], int nMessage)
{
	return strlen(M[nMessage-1].msg);
}



/*
   	Q5: How many messages were received from <sender> on <date> in inbox <inbox number>?
   
    Assume that the array of structures Inbox[] already have contents.
  
   	RESTRICTION: Do not use scanf() or printf().
*/

int Q5(struct msgTag M[], int nMessage, int sender, int month, int day, int year)
{
	int i;
	int msg = 0;
	for(i = 0; i < nMessage; i++)
		if(M[i].sender == sender && M[i].date.month == month && M[i].date.day == day && M[i].date.year == year)
			msg++;
	//Sum algorithm where it only adds when on the same sender and date
	return msg;
}




/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.  

    The main() is in the accompanying TXTMSG-main-LASTNAME.c source file.
    
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
********************************************************************************/




