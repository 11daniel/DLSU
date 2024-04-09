/******************************************
TO DO: Update by indicating your name and section below.

Problem: Cost Splitting

Author: Daniel Gavrie Clemente
Section: Block 09 S19B

******************************************/

#include <stdio.h>
#include "CLEMENTE-Cost.c"  /* replace this line with the actual filename
                               you used.  For example, the file containing
							   your solution for all functions is in 
							   SANTOS-Cost.c, then indicate
							   #include "SANTOS-Cost.c"
                            */
int main()
{
	// TO DO: Declare the necessary variables (6 pts)
	int nPeople, nTotal, nBackOut;
	float fOriginal, fAdded, fNew;

	printf("Enter no. of people in the group: ");
	// TO DO: Provide the code for getting the number for friends (3 pts)
	scanf("%d", &nPeople);
	printf("Enter total cost of the present: ");
	// TO DO: Provide the code for getting the amount of the gift (3 pts)
	scanf("%d", &nTotal);
	printf("Number of people backing out: ");
	// TO DO: Provide the code for number of people that backed out (3 pts)
	scanf("%d", &nBackOut);
	/* TO DO: Provide the assignment statement to compute for 
	          the original contribution per person (4 pts)
    */
	fOriginal = nTotal / nPeople;
	
	/* TO DO: Provide the assignment statement to compute for 
	          the added contribution per person. 
			  You are required to call the computeAddedContribution() 
			  function. (5 pts)
	*/
	fAdded = computeAddedContribution(nPeople, nTotal, nBackOut);
	
	/* TO DO: Provide the assignment statement to compute for 
	          the new cost per person. 
			  You are required to call the computeNewContribution() 
			  function (4 pts)
    */
   fNew = computeNewContribution(fOriginal, fAdded);
	
	// TO DO: Call the displayBreakdown() function (4 pts)
	displayBreakdown(fOriginal, fAdded, fNew);
	return 0;
}
