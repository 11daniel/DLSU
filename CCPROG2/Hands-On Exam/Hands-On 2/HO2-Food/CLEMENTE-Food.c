/*
    HANDS-ON #2
    PROBLEM: FOOD
	
    NAME: <TO-DO: Write Lastname, Firstname>
    SECTION:
*/


/* Make sure that you read and understand the contents of the food.h header file. */
#include "food.h"

/*
    TO DO: 
    
    Implement the  functions defined in the food.h header file. 
	
	You may define other functions if you want, which can be called by one or more of the 
	required functions.
	
	RESTRICTIONS:
	1. Make sure to follow the function prototypes specified in food.h
	2. Use only the library function that we discussed in class, within
	   the coverage of the exam and in the course material.  Non-compliance with 
	   this restriction will make your answer incorrect, and therefore will result
	   into a score of 0.
	3. None of the codes that you will implement should include
	   scanf() and printf() statements.
	4. Only code constructs within the coverage and in the course material 
	   can be used.  For example, for strings, only strlen(), strcmp(),
	   strcat(), and strcpy() can be used.
	5. Do NOT define a main() function in this file.  The main() function definition 
	   is already in the file main.c.
	6. Do NOT add any other header files.
	
*/


/*
 * TO DO #1
 * Write the implementation for this function. (10 points)
 * This function answers the question 
 *    "How many calories (per gram) are there in param_food?"
 *  Ex: How many calories are there in per gram of carrots?
 * 
 * @param param_food - foodName to search for in foodList
 * @param foodList - 1D array of foodType
 * @param nElem - number of initialized elements in foodList
 * @return number of calories (per gram) of the param_food; returns
           0.0 when param_food is not found in foodList
 * 
 * Requirement/Restriction:
 * 1. No printf() or scanf() in this function. 
 * 2. foodList should not be modified within this function
*/
float 
Q1(char * param_food, foodType foodList[], int nElem)
{
	int i = 0; 
	float foodCalories;
	
	for (i = 0; i < nElem; i++) {
		
		if (strcmp(foodList[i].foodName, param_food) == 0) {
			foodCalories = foodList[i].calories;
		}
	}
	
	return foodCalories; //replace the returned value
}

/*
 * TO DO #2
 * Write the implementation for this function. (10 points)
 * This function answers the question 
 *    "How many of the list of foodName in the viand are param_category?"
 *   Ex. How many of the list of foodName in the adobo menuItem are vegetable? 
 *
 * @param param_category - category to search for in foodList
 * @param foodList - 1D array of foodType
 * @param nElem - number of initialized elements in foodList
 * @param viand - structure of itemType
 * @return number of foodName that have category param_category
 * 
 * Requirement/Restriction:
 * 1. No printf() or scanf() in this function. 
 * 2. all given parameters should not be modified within this function
 */
int 
Q2(char * param_category, foodType foodList[], int nElem,
   itemType viand)
{
	int i, j;
	int totalCat = 0;
	
	for (i = 0; i < nElem; i++) 
	{
		for(j = 0; j < viand.numIng; j++) {
			if (strcmp(viand.aList[j].foodName, foodList[i].foodName) == 0) {
				if (strcmp(foodList[i].category, param_category) == 0) {
					totalCat++;
				}
			}
		}
	}
	return totalCat; //replace the returned value
}

/*
 * TO DO #3
 * Write the implementation for this function. (15 points)
 * This function updates the totalCal through the parameter viand.
 * Note that the totalCal considers the quantity. For example,
 * if egg is 0.97 calories per gram and quantity (in grams) of egg in
 * the viand is 120 (grams), then calories for egg is 116.4.  This is
 * added to the calories of the other ingredients of the viand. 
 * 
 *   Ex. How many totalCal are referred to in the adobo menuItem? 
 *
 * @param viand - address to structure of itemType
 * @param foodList - 1D array of foodType
 * @param nElem - number of initialized elements in foodList
 * 
 * Requirement/Restriction:
 * 1. No printf() or scanf() in this function. 
 * 2. foodList should not be modified within this function
 */
void 
Q3(itemType * viand, foodType foodList[], int nElem)  
{
	int i, j;
	
	for (i = 0; i < viand->numIng; i++) {
		
		for(j = 0; j < nElem; j++) {
			if(strcmp(viand->aList[i].foodName, foodList[j].foodName) == 0){
				viand->totalCal += Q1(viand->aList[i].foodName, foodList, nElem) * (viand->aList[i].quantity * 1.0f);
			}
		}
	}
}

/*
 * TO DO #4
 * Write the implementation for this function. (15 points)
 * This function should generate the array of itemType that
 *    do not have param_restrict and at least 70% of the 
 *    ingredients in the viand is characterized by 
 *    param_category. The 70% is just based on the count of
 *    the ingredients (NOT based on quantity (in grams)).
 * 
 *    Ex. Which itemType do not have egg and at least 70% of
 *         the ingredients in the viand is vegetable?
 *
 * @param recommended - resulting 1D array to contain the itemType that
              does not contain param_restrict and at least 70%
              of the ingredients are param_category			  
 * @param pReco - address where the number of initialized elements in 
                  recommended will be stored
 * @param param_restrict - foodName that the user does not want to have as
                  part of viand (compare against foodName, not category)
 * @param param_category - category to search for in foodList (check only
                  against category, not foodName)
 * @param menu - 1D array of itemType
 * @param nMenu - number of initialized elements in menu
 * @param foodList - 1D array of foodType
 * @param nElem - number of initialized elements in foodList
 * 
 * Requirements/Restrictions:
 * 1. No printf() or scanf() in this function. 
 * 2. only recommended and *pReco should be modified within this function
 *
 * Hint: Consider using result of Q2() as part of your solution.
*/
void 
Q4(itemType recommended[], int *pReco, char * param_restrict,
   char * param_category, itemType menu[], int nMenu,
   foodType foodList[], int nElem)
{
	int i =0;
	int j = 0;
	
	while(j < nMenu) {
		if (Q2(param_restrict, foodList, nElem, menu[j]) == 0) {
			if (Q2(param_category, foodList, nElem, menu[j]) >= 0.7 * menu[j].numIng) {
				recommended[i] = menu[j];
				i++;
			}
		}
		j++;
	}
	(*pReco) = i;
}



/* 

    DO NOT define a main() function in this file!!!
	    
    The main() function for testing your solution is already in another file named
	main.c file.

*/