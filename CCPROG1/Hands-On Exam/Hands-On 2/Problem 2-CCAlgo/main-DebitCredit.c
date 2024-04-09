/***********************************************************************
This file WILL NOT be submitted.

DO NOT CHANGE ANY CODES IN THIS FILE, except for Line 9 where
LASTNAME-CCAlgo.c should be changed to your own .c file.
***********************************************************************/

#include <stdio.h>
#include "CLEMENTE-CCAlgo.c"

int main()
{
	int cardNum1, cardNum2;		//this would represent the card number to be entered.
	
	do
	{	
		printf("\n\nCREDIT / DEBIT CARD NUMBER VERIFIER\n");
		printf("===================================\n\n");

		/*
			Take note of the instruction that the inputs are 2 8-digit values.
			Maximum value for integers is 2147483647 (10 digits long). Since you will be required to enter
			a 16-digit number, we will need to enter 2 integer values to suffice the 16-digit requirement.
			
			For this exam, you will accept 2 integer values. So, the space is needed in-between.
		*/

		printf("When entering the card number, add a space/gap between the 8th and 9th digit.\n");
		printf("Enter a card number : ");
		
		/*
			The first 8 digits of the card number will be stored in cardNum1. The next 8 numbers, stored in cardNum2.
		*/
		scanf("%d %d", &cardNum1, &cardNum2);
		
		if (isNumberSameDigitLength(cardNum1, 8) && isNumberSameDigitLength(cardNum2, 8))
		{	
			/*
				Verify if the Card Number is correct. If the function ValidateCardNumber returns 1, 
				it means that the card number passes the Luhn's algorithm.
			*/
			if (isValidCardNumber(cardNum1, cardNum2) == 1) 
			{
				printf("Card has a VALID number!\n");
			}
			else
			{
				/*
					This would mean that the ID Number did not pass Luhn's Algorithm.
				*/
				printf("Card has an INVALID number!\n");
			}
		}
		else
			/*
				Error message will display if the user did not enter 2 8-digit numbers.
				Take note that typing leading zeros as inputs will not be considered.
			*/
			printf("Please recheck your input.");
			
	/*
		The program will end when the user enters a correct input for the card number.
	*/
			
	}while(!isNumberSameDigitLength(cardNum1, 8) || !isNumberSameDigitLength(cardNum2, 8));
	
	return 0;
}
