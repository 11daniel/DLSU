/******************************************
TO DO: Update by indicating your name and section below.

Problem: Cost Splitting

Author: Daniel Gavrie Clemente
Section: Block 09 S19B
******************************************/

/* Requirements and Restrictions: 
      * You are NOT allowed to write any additional function 
        other than the ones specified in the specs.
	  * main() should not be placed in this file.
*/


/*
	This function is pre-defined.
	This function computes for the new additional contribution per person.
	Example:
	   If  friendCount = 7, amount = 5300.00, backOut = 2
	   the function returns 302.857143
	DO NOT MAKE ANY CHANGES TO THIS FUNCTION!
*/
float computeAddedContribution(int friendCount, float amount, int backOut)
{
	return amount / (friendCount - backOut) - amount / friendCount;
}

/* TO DO: Implement computeNewContribution() to compute and return the new 
        contribution cost per person. (8 pts)
	
	Example:
	   If  origCont = 757.142857, added = 302.857143
	   the function returns 1060.000000
		
	@param origCont - original contribution per person
	@param added - the additional contribution per person
	@return the new contribution per person
	
	Requirement and Restrictions:
	   * No display statements should be in this function (e.g. printf)
	   * Function name and other details provided should be followed
	     (including case and spelling).
	   * The parameter list should follow the sequence indicated above.
	       That is origCont is the first parameter and added is the second.
*/
float computeNewContribution(float fOrig, float fAdd) {
	return fOrig + fAdd;
}



/* TO DO: Implement displayBreakdown() to display the following: (10 pts)
			- Original Contribution per person: (be sure to add 1 tab after the colon(:))
			- Added Contribution per person due to backout: (be sure to add 1 tab after the colon(:))
			- New Contribution cost per person: (be sure to add 1 tab after the colon(:))
	
	NOTE: The field width of all amounts is 7 and you should limit it to 2 decimal places.
	
	@param origCont - the original contribution per person amount
	@param additionalCont - the additional contribution per person due to backout
	@param newCont - the new contribution cost per person

	Requirement and Restrictions:
	   * Function name and other details provided should be followed
	     (including case and spelling).
	   * You are required to follow the sequence of the parameter
	     list indicated above (that is, origCont is the first parameter and newCont is the last).

*/

void displayBreakdown(float fOrig, float fAdd, float fNew) {
	printf("Original contribution per person: %.2f\n", fOrig);
	printf("Additional contribution per person: %.2f\n", fAdd);
	printf("New contribution per person: %.2f", fNew);
}