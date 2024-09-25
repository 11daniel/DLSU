/* 
   	This file contains the main() function.  
	   
	It is this file that you should compile and run to test your solution.
   	
    MAKE SURE THAT the solution/program you are submitting does not have:
       * a compilation error
	   * a compilation warning
	   * a logical error
	
	If there is a compilation error, the score will be 0 point.	   
*/


/*
   TO DO #1:  change the #include below to the file with your own lastname.  For example if your lastname
   is SHAZAM, then it should be changed to #include "BUYSELL-SHAZAM.c".
   
*/
#include "BUYSELL-LASTNAME.c"

/* 
   You may change the main() function call.  But you have to make sure that you 
   follow the function parametrization given in the sample function calls.
   
   Note that your BUYSELL-LASTNAME.c and MYHEADER-LASTNAME.h solution will be black box tested
   using another main() function which is different the one this file.
*/
int
main()
{
    struct sellerTag SELLERS[MAX_SELLERS];      // MAX_SELLERS is defined in buysell.h
    struct productTag PRODUCTS[MAX_PRODUCTS];   // MAX_PRODUCTS is defined buysell.h
    
    int n_sellers;   // actual number of sellers
    int n_products;  // actual number of products
	 
	scanf("%d", &n_sellers);    // assume input is valid    
	scanf("%d", &n_products);   // assume input is value
		
	// sample InputSellers() function call
	InputSellers(SELLERS, n_sellers);
	
	// sample InputProducts() function
	InputProducts(PRODUCTS, n_products);
		
    // sample Recommend() function calls
	Recommend(SELLERS, PRODUCTS, n_sellers, n_products, "CUTTER");	      
	Recommend(SELLERS, PRODUCTS, n_sellers, n_products, "CLIP");	      
	Recommend(SELLERS, PRODUCTS, n_sellers, n_products, "PAPER");	      	
	
	// the next call should result into "BOARD NONE"  if using INPUT.txt test file 
	// because the seller has a Rating < 3.0
	Recommend(SELLERS, PRODUCTS, n_sellers, n_products, "BOARD");	      
			
	Recommend(SELLERS, PRODUCTS, n_sellers, n_products, "BAG");	      	

    // the next call should result into "GLUE NONE"  if using INPUT.txt test file 
    // because there is no seller selling GLUE
	Recommend(SELLERS, PRODUCTS, n_sellers, n_products, "GLUE");	  
	
	return 0;
}


