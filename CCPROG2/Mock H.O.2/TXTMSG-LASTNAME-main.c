/* 
    This is the skeleton file that you need to use as base code for the TXTMSG problem.
	
	Encode your Name and Section below.
	    
    LASTNAME, FIRSTNAME: _____________________
    SECTION: _________
	
	TO DO: Complete the missing parts in the main() function.
	
    MAKE SURE THAT the solution/program you are submitting does not have:
       * a compilation error
	   * a compilation warning
	   * a logical error
	
	If there is a compilation error, the score will be 0 point.	   
*/


/*
   TO DO #1:  change the #include below to the file with your own lastname.  For example if your lastname
   is SHAZAM, then it should be changed to #include "TXTMSG-SHAZAM.c".
   
*/
#include "TXTMSG-LASTNAME.c"


/*
	This function is called prior to a scanf() function.
	It is used to display a prompt corresponding to the text parameter.
*/
void Prompt(char * text)
{
// Do NOT mind the #if BLACK_BOX #endif in this function.
#if BLACK_BOX	

	printf("%s", text);

#endif	
}


/* 
   TO DO #2: Complete the missing parts of the main() function.
   
   You are allowed to change only those lines with printf() that require you to call 
   the functions that you defined above.
*/
int
main()
{
	// Assume a dual SIM cellphone.  Both slots have SIMS inserted in them.
	struct inboxTag Inbox[2];   // Inbox[0] is for the 1st SIM. It has an inbox number of 0.  
	                            // Inbox[1] is the for 2nd SIM. It has an inbox number of 1.
	
	int inbox_number;  // value is 0 or 1
	int sender;
	struct dateTag date;
	
	Load_Data(Inbox);  // This function was define in the accompanying file "loder-txtmsg.c".
	                   // It loads/initializes the contents of the Inbox[] array of structure.
	
	/* You are NOT allowed to: (1) to add other variables, (2) change existing variable declarations. */
	
	
	/*
	    TO DO #2:  Replace the -1 in the printf() below with an appropriate call to the 
		           function you defined as answer to Q1 to Q5.
		
		DO NOT: 
		  a.  replace the 1.0 if you were not able to come up with a solution.
		  b. change the %d format -- thus, the expected return value data type is int. 
		
		ASSUME that all inputs via scanf() are valid values.
	*/		
			
	Prompt("Input inbox number (type 0 or 1 only): ");
	scanf("%d", &inbox_number);  

	/*
		HARD REQUIREMENT: You have to USE inbox_number value as actual parameter in answering Q1 to Q5
	*/	
	
	// Q1: Is inbox <inbox_number> full?   
    printf("A1: %d\n", Q1(Inbox, inbox_number));  // Q1 answer example call

	// Q2: Who sent the most recent message in inbox <inbox_number>?  (answer is the number of the sender)
    printf("A2: %d\n", Q2(Inbox[inbox_number].Msg, Inbox[inbox_number].n_msgs));   // REPLACE -1 with your function call to answer Q2.
	
	// Q3: How many unread messages are there in inbox <inbox_number>
    printf("A3: %d\n", Q3(Inbox[inbox_number].Msg, Inbox[inbox_number].n_msgs));   // REPLACE -1 with your function call to answer Q3.
	
	
    // Q4: What is the string length of the most recent message in inbox <inbox_number>? 
	printf("A4: %d\n", Q4(Inbox[inbox_number].Msg, Inbox[inbox_number].n_msgs));   // REPLACE -1 with your function call to answer Q4.


 	/*
		HARD REQUIREMENT: You have to use the sender and date structure values as parameters in answering Q5.
	*/
	
	Prompt("Input sender cellphone number: ");
    scanf("%d", &sender);
	
    Prompt("Input numeric month day year separated by spaces: ");
	scanf("%d %d %d", &date.month, &date.day, &date.year);
	
	// Q5: How many messages were received from <sender> on <date> in inbox <inbox number>?
	printf("A5: %d\n",  Q5(Inbox[inbox_number].Msg, Inbox[inbox_number].n_msgs, sender, date.month, date.day, date.year));   // REPLACE -1 with your function call to answer Q5.
						    
	return 0;

}


