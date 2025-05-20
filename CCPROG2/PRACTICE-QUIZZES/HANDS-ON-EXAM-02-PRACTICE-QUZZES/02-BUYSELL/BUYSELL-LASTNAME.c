/* 
    This is the skeleton file that you need to use as base code for the BUY-AND-SELL problem.
	
	Encode your Name and Section below.
	    
    LASTNAME, FIRSTNAME: _____________________
    SECTION: _________

    MAKE SURE THAT the solution/program you are submitting does not have:
       * a compilation error
	   * a compilation warning
	   * a logical error
	
	If there is a compilation error, the score will be 0 point.	   
*/

/* DO NOT CHANGE THE #include below */
#include <stdio.h>
#include <string.h>


/*
   TO DO #1:  change the #include below to the header file with your own lastname.  For example if your lastname
   is SHAZAM, then it should be changed to #include "MYHEADER-SHAZAM.h".   
*/
#include "MYHEADER-LASTNAME.h" 


/* 
   	TO DO #2 [5 points]:
	   
	Implement InputSellers(SELLERS, n_sellers) function to input using scanf() the contents of the SELLERS[] array.   

   	RESTRICTION: DO NOT USE printf() inside this function!   
*/
void InputSellers(struct sellerTag SELLERS[], int n_sellers) {
	int i;

	for (i = 0; i < n_sellers; i++) 
	{
		scanf("%d %s %s %f", &SELLERS[i].ID, SELLERS[i].first, SELLERS[i].last, &SELLERS[i].rating);
	}
}





/* 
   	TO DO #3 [5 points]:

   	Implement InputProducts(PRODUCTS, n_products) function to input using scanf() the contents of the PRODUCTS[] array.

   	RESTRICTION: DO NOT USE printf() inside this function!   
*/
void InputProducts(struct productTag PRODUCTS[], int n_products) {
	int i;

	for (i = 0; i < n_products; i++) 
	{
		scanf("%d %s %f", &PRODUCTS[i].ID, PRODUCTS[i].product_type, &PRODUCTS[i].price);
	}
}




/* 
   	TO DO #4 [5 points]: 
   
   	Implement Linear_Search(struct sellerTag SELLERS[], int n_sellers, int key) function.  
    It should return the index where a seller ID matching the key parameter value 
	was found.  If the key is not found, the function should return -1.
             
   	RESTRICTION: DO NOT USE printf() and scanf() inside this function!   
*/
int Linear_Search(struct sellerTag SELLERS[], int n_sellers, int key) 
{
	int i;
	
	for (i = 0; i < n_sellers; i++)
	{
		if (key == SELLERS[i].ID)
		{
			return i;
		}
	}
	return -1;
}



/*  		  
	TO DO #5 [25 points]: Deductions ranging from minus 25 to minus 5 will be applied depending 
	on the severity of the logical errors. 
	
	Implement Recommend(SELLERS, PRODUCTS, n_sellers, n_products, product) function. The function should 
	search and print information about the seller who is selling the product (i.e., the search string) at the 
	lowest Price.  The following rules must be obeyed:

    Rule 1. Only sellers with a rating of at least 3.0 are qualified to be considered for recommendation.
              
	Rule 2. Tie-Breakers:
			  	
			Q1: What if there are two or more sellers selling the same product for the same price?  
			A1: It is the seller with the highest Rating who is recommended.  We value more Trustworthy people! 

			Q2: What if the situation above happens, and the sellers have the same rating? 
			A2: It is the seller with the smallest ID number (the lower the number, the more senior is the seller 
	    		in the community) who is recommended. We respect people who are more senior than us!

    You are allowed to define other functions that you can call inside Recommend().
			  
  	HARD REQUIREMENTS: 
	1. you must call Linear_Search() inside Recommend().
	 
	2. You must strictly follow the same output format described below.
	   a. If the product is found, the output is in the following sequence:
	   
	      product	price	ID	firstname	lastname	rating 
	   
	   b. If the item is not found, the output should be:
	   	     
	       product NONE
	   
	   
	   c. Use printf() to output the required values separated by a tab character, i.e. '\t'.  
	   	  Print floating point values with two digits after the decimal point.
		   
	3. DO NOT print any other unnecessary string or value.  It will interfere with the black box test!!!
	   
	View the contents of the file EXPECTED.txt for the sample expected output when the given main() function is executed.	   
*/

void swap(struct sellerTag *a, struct sellerTag *b)
{
	struct sellerTag temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swapP(struct productTag *a, struct productTag *b)
{
	struct productTag temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sortPrice(struct productTag P[], int n_products)
{
	int i, j, min = 0;
	for(i = 0; i < n_products - 1; i++)
	{
		min = i;
		for(j = i + 1; j < n_products; j++)
			if(P[min].price > P[j].price)
				min = j;
			else if(P[min].price == P[j].price && P[min].ID < P[j].ID)
				min = j;
			
		if(min != i)
			swapP(&P[i], &P[min]);
	}
}

void sortID(struct sellerTag S[], int n_sellers)
{
	int i, j, min = 0;
	for(i = 0; i < n_sellers - 1; i++)
	{
		min = i;
		for(j = i + 1; j < n_sellers; j++)
			if(S[min].ID > S[j].ID)
				min = j;
			
		if(min != i)
			swap(&S[i], &S[min]);
	}
}

void Recommend(struct sellerTag SELLERS[], struct productTag PRODUCTS[], int n_sellers, int n_products, String30 product)
{
	//Search and print information about seller who is selling the product at the lowest price
	//Note that the seller and product ID is the same
	//Store all the potential products with the same string in one array
	//Update only when that seller's ID's rating is 3.0 above
	//Sort in increasing order and get index 0 as the lowest price
	//Get that struct's productID and call linearsearch to find the user with the same ID
	//print the info of the candidate with the same ID
	int i, prodNo = 0, sellNo = 0, index = 0, found = 0;
	struct productTag prodcand[MAX_PRODUCTS];
	struct sellerTag sellcand;
	
	for(i = 0; i < n_products; i++)
	{
		if(strcmp(PRODUCTS[i].product_type, product) == 0)
		{
			prodcand[prodNo] = PRODUCTS[i];
			if(SELLERS[Linear_Search(SELLERS, n_sellers, prodcand[prodNo].ID)].rating >= 3.0)
			prodNo++;
		}
	}
	
	sortPrice(prodcand, prodNo);
	sortID(SELLERS, n_sellers);
	
	if(prodNo > 0)
	{
		while(!found)
		{
			index = Linear_Search(&SELLERS[index], n_sellers - index, prodcand[0].ID);
			if(SELLERS[index].rating >= 3.0)
			{
				sellcand = SELLERS[index];
				found = 1;
			}
		}
		printf("%s\t%.2f\t%d\t%s\t%s\t%.2f\n", product, prodcand[0].price, sellcand.ID, sellcand.first, sellcand.last, sellcand.rating);
	}
	else {
		printf("%s\tNONE\n", product);
	}	
}







/*******************************************************************************
    WARNING!!!   WARNING!!!   WARNING!!!    
	
	YOU ARE NOT ALLOWED TO DEFINE the main() function in this file.  

    The main() is in the accompanying BUYSELL-LASTNAME-main.c source file.
    
	VIOLATION OF THIS RESTRICTION WILL RESULT TO A DEDUCTION OF 10 points!		 
********************************************************************************/



