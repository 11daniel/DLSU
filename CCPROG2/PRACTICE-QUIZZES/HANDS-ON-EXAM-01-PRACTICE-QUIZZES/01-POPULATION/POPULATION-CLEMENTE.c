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
	int i;
	int value = 0;
	double total_population;
	double male_percentage;

	for (i = 0; i < nYears && value == 0; i++) {
		total_population = POPULATION[i];
		value = 1;
	}

	male_percentage = total_population * 0.49;


    return male_percentage;  /* replace -1.0 with the appropriate return value */	
}


/*
   Q2: How many senior citizens were there in year ___?
*/
double
Q2(int YEAR[], int POPULATION[], int nYears, int param_year)
{
	/* declare your own local variables and define the body of this function. */
	int i;
	int value = 0;
	double total_population;
	double adult_percentage;
	double senior_percentage;

	for (i = 0; i < nYears && value == 0; i++) {
		total_population = POPULATION[i];
		value = 1;
	}

	adult_percentage = total_population * 0.60;
	senior_percentage = adult_percentage * 0.11;


    return senior_percentage;  /* replace -1.0 with the appropriate return value */	
}



/*
   Q3: What is the annual population growth rate (in percent) in year <param_year>?
*/

double
Q3(int YEAR[], int POPULATION[], int nYears, int param_year)
{
	// declare your own local variables and define the body of this function. 
	int i;
	int value = 0;
	double current_total;
	double previous_total;
	double annual_growth;

	for (i = 0; i < nYears && value == 0; i++) {
		if (YEAR[i] == param_year) {
			current_total = POPULATION[i];
			previous_total = POPULATION[i - 1];
			value = 1;
		}
	}

	annual_growth = (current_total - previous_total) / previous_total * 100;



    return annual_growth;  // replace -1.0 with the appropriate return value	
}





/*
    Q4: What is the lowest annual population growth rate?
*/
double
Q4(int YEAR[], int POPULATION[], int nYears)
{
	/* declare your own local variables and define the body of this function. */
	int i;
	double lower_annual;
	double lower_percentile = Q3(YEAR, POPULATION, nYears, YEAR[1]);

	for (i = 2; i < nYears; i++) {
		lower_annual = Q3(YEAR, POPULATION, nYears, YEAR[i]);

		if (lower_annual < lower_percentile) {
			lower_percentile = lower_annual;
		}
	}


    return lower_annual;  /* replace -1.0 with the appropriate return value */	
}




/*
    Q5: What is the average annual population growth rate?
*/
double
Q5(int YEAR[], int POPULATION[], int nYears)
{
	/* declare your own local variables and define the body of this function. */
	int i;
	double average_annual = 0.0;

	for (i = 1; i < nYears; i++) {
		average_annual += Q3(YEAR, POPULATION, nYears, YEAR[i]);
	}


    return average_annual/(nYears - 1);  /* replace -1.0 with the appropriate return value */	
}




/*

    DO NOT define a main() function in this file!!!
	    
    The main() function for testing your solution is already in another file named
	main.c file.

*/

