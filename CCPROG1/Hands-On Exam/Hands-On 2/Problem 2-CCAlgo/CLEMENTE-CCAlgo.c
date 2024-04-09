/***********************************************************************
AUTHOR: DANIEL GAVRIE CLEMENTE - BLOCK - 09
***********************************************************************/

#include <stdio.h>

/*******************************************************************************************************
	No need to do this function. Already provided.
	Function Name : computeDigitSum
	Prototype	  : int computeDigitSum(int)
	Description   : Returns the sum of the digits of a two-digit number. The maximum value
					that we can get when we multiply a single digit number with 2 is 18.
					Let's not overthink too much. 
	Precondition  : nProductDigit is a positive number > 9
	@param nProductDigit - a two digit number 
	@return 1 digit number representing the sum of the digits of a 2-digit number
	
	Example:	computeDigitSum(17) returns 8. (i.e., 1 + 7 = 8)
				computeDigitSum(5) will return a negative number. However, precondition states that the parameter should be > 9.
*/

int computeDigitSum(int nProductDigit)
{
	return nProductDigit - 10 + 1;
}


/*******************************************************************************************************	
GENERAL GUIDELINES:
1. You are only allowed to use stdio.h for this problem. Use of other libraries will be prohibited.
2. Strictly NO BRUTE FORCE programming. It is expected that you use the programming constructs used in class.
   Particularly, functions, conditional statements, and most importantly... loops.
3. You are not allowed to write any additional function other than the ones specified in the specs.
4. You are not allowed to use code outside of the scope of the coverage of topics (i.e., not allowed
   to use arrays.
*/

/*******************************************************************************************************	
	TO DO #1    
	Function Name : isNumberSameDigitLength (10 points)
	Prototype	  : int isNumberSameDigitLength(int, int)
	Description   : This function checks if the number of digits of nCardNumber is the same as value nTotalDigits. 
	Precondition  : nCardNumber, nTotalDigits are positive numbers
	@param nCardNumber - number / value to be checked
	@param nTotalDigits - number of digits to be matched
	@return 1 if the number of digits of n is equal to the second parameter i and 0 otherwise.
	
	Example:		isNumberSameDigitLength(12345678, 5) will return 0 (i.e., We are checking if the first parameter has 5 digits)
					isNumberSameDigitLength(1234, 4) will return 1 (i.e., Since 1234 has 4 digits)
*/

int isNumberSameDigitLength(int nCardNumber, int nTotalDigits)
{
	int nDigit = 0;
	int nResult;

	while (nCardNumber > 0) {
		nCardNumber = nCardNumber / 10;
		nDigit++;
	}

	if (nDigit == nTotalDigits) {
		nResult = 1;
	}
	else {
		nResult = 0;
	}

	return nResult;  		//You must change this line when you update the function definition.
}


/*******************************************************************************************************
	TO DO #2
	Function Name : extractDigit (15 points)
	Prototype	  : int extractDigit(int, int)
	Description   : This extracts the ith digit of n. 
	Precondition  : n, i are positive numbers and there is an ith digit in n
	@param nCardNumber - number / value to be checked
	@param nPosition - digit to be extracted (i.e., nth position starting from the ones digit)
	@return ith digit from n
	
	Example:		extractDigit(12345678, 5) will return 4 (i.e., it will extract the 5th digit starting from the right)
					extractDigit(12345678, 8) will return 1 (i.e., it will extract the 8th digit starting from the right)
*/

int extractDigit(int nCardNumber, int nPosition)
{
	int i;
	int nDigitPosition;
	while (nCardNumber != 0) {
		int digit = nCardNumber % 10;
		nCardNumber = nCardNumber / 10;
	}
	for (i = nCardNumber; nPosition < i ; i--) {
		nDigitPosition = nCardNumber/nPosition;
	}
	return nDigitPosition;	//You must change this line when you update the function definition.
}

/*******************************************************************************************************
	TO DO #3
	Function Name : isValidCardNumber (25 points)
	Prototype	  : int isValidCardNumber(int, int)
	Description   : The function validates if the card number provided by the user is valid or not.
					You are required to call functions extractDigit and computeDigitSum (provided already above)
					and meaningfully use their results as part of solution for this function.
					Please refer to the mechanics on the Luhn's Algorithm in page 2 of the specifications.
	Precondition  : both nCardNumberP1, nCardNumberP2 are 8-digit numbers
	@param nCardNumberP1 - 1st half of the 16-digit card number
	@param nCardNumberP2 - 2nd half of the 16-digit card number
	@return 1 if the card number passes the Luhn's Algorithm. Otherwise, returns 0.
	
	Example:	isValidCardNumber(51001089, 33421116) returns 1. (i.e., the number is a valid card number)
				isValidCardNumber(55001293, 61823442) returns 0. (i.e., the number is NOT a valid card number)
*/

int isValidCardNumber(int nCardNumberP1, int nCardNumberP2)
{
	int nResult;
	int nResult1;
	int extractedDigit = extractDigit(nCardNumberP1, 8);
	nResult1 = computeDigitSum(extractedDigit);
	if (extractedDigit == nResult1) {
		nResult = 1;
	}
	else {
		nResult = 0;
	}
	return nResult;  		//You must change this line when you update the function definition.
}


