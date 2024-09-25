/*
    Skeleton file for POPULATION problem.
	
    lASTNAME, FIRSTNAME: 
	SECTION: 
    DATE: 
*/


/* Make sure that you read and understand the contents of the population.h header file. */
#include "population.h"


/*
    TO DO: 
    
    Implement the 5 functions that will compute and return a number that correspond as answer
	for each question from Q1 to Q5. 
	
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
	Q1: How many males were there in year <param_year>?

	The sample INCOMPLETE function definition below shows the appropriate return data type (double), 
	a function name and the four necessary parameters to compute the answer to the question.  
	
	An example function call would be: Q1(YEAR, POPULATION, nYears, 2000);
	
	You must fill in the body of the function. DO NOT forget a return statement!
*/
double
Q1(int YEAR[], int POPULATION[], int nYears, int param_year)
{
	/* declare your own local variables and define the body of this function. */

	int i, count = 0;
	double male_percentage;
	double total_population;

	for (i = 0; i < nYears && count == 0; i++) {
		total_population = POPULATION[i];
		count = 1;
	}

	male_percentage = POPULATION[i] * 0.49;


    return male_percentage;  /* replace -1.0 with the appropriate return value */	
}


/*
   Q2: How many senior citizens were there in year ___?
*/
double
Q2(int YEAR[], int POPULATION[], int nYears, int param_year)
{
	/* declare your own local variables and define the body of this function. */

	int i, count = 0;
	double male_percentage;
	double total_population;

	for (i = 0; i < nYears && count == 0; i++) {
		total_population = POPULATION[i];
		count = 1;
	}

	male_percentage = POPULATION[i] * 0.49;


    return male_percentage;  /* replace -1.0 with the appropriate return value */	
}



/*
   Q3: What is the annual population growth rate (in percent) in year <param_year>?
*/





/*
    Q4: What is the lowest annual population growth rate?
*/





/*
    Q5: What is the average annual population growth rate?
*/





/*

    DO NOT define a main() function in this file!!!
	    
    The main() function for testing your solution is already in another file named
	main.c file.

*/

