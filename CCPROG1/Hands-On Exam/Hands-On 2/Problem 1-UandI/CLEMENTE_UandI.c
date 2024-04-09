/* Hands-on 2
   Problem: Union and Intersection

   Name:    Clemente, Daniel Gavrie
   Section:
*/

#include <stdio.h>  //Do not remove or replace this line
/* General requirements and restrictions: 
   1. No other header files can be included in this file 
   2. You are not allowed to have main() in this file. 
   3. You are not allowed to create additional functions. 
   4. You are not allowed to modify the function prototypes and
      function headers provided.
   5. You are not allowed to use topics outside of the coverage
      (e.g., not allowed to use arrays).
   6. Only the already given printf() in menu() are allowed.  No
      additional printf() in menu() or in other functions allowed.
*/

//Function prototypes
void menu();
int isIn(int digit, int num);
int numUnion(int num1, int num2);
int numIntersect(int num1, int num2);

/* TO DO: Debug this function. (10 pts)

   This function serves as the menu. The function gets 2 integer
   inputs, checks if both are positive before calling (and displaying
   the results of) both union and intersection functions. If at least
   one of the numbers is not positive, the function displays a message
   and terminates the loop and the function ends.
   
   Requirements/Restrictions:
    - You are not allowed to use break, continue or return statement
       in this function.
*/
void
menu()
{
   int num1, num2;

   do
   {
      printf("Enter two numbers: ");
      scanf("%d%d", &num1, &num2);
      
	  /* if both numbers are positive, call the functions to produce
	     and display results of the union and intersection */
      if (num1 , num2 > 0){
          printf("U: %d\n", numUnion(num1, num2));
          printf("I: %d\n\n", numIntersect(num1, num2));
      }
      else printf("Program terminates\n");
   } while (num1 || num2);  /* Program terminates once at least one of the given numbers
                               is not positive */
}
   
/* TO DO: Write the implementation for this function. (10 pts) 

   This function should return 1 when digit is in num. 
   Otherwise, function returns 0.
   
   Pre-condition/Assumption: digit > 0, num > 0
   @param digit - a 1-digit number that is being searched for
   @param num - the value to search from
   @return 1 if digit is in num and return 0, otherwise

   Requirements/Restrictions:
    - No printf() allowed in this function.
   
   Example 1: digit = 9, num = 123, function returns 0
   Example 2: digit = 4, num = 3241, function returns 1
*/
int
isIn(int digit, int num)
{
   int rem;
   while (num != 0) 
   {
      rem = num % 10;
      if (rem == digit) {
         return 1;
      }
      num /= 10;
   }
   return 0;
}

/* TO DO: Write the implementation for this function. (15 pts)
   
   This function attaches a new digit at the RIGHT of num1 each 
   time a digit in num2 is not yet in num1.  The function returns
   this new number.
   
   Pre-condition: num1 > 0, num2 > 0, each number has unique digits
   @param num1 - the first number
   @param num2 - the second number
   @return the new number representing the union of num1 and num2

   Requirements/Restrictions:
   1.) No printf() allowed in this function.
   2.) Required to call the function isIn() and meaningfully use
       its result, as part of the solution of this function.
   3.) Required to attach the new digits to the right as shown in
       samples below.  Other results will not be considered.

   Example 1: num1 = 56, num2 = 895264, function returns 564298
   Example 2: num1 = 1234, num2 = 4321, function returns 1234
   Example 3: num1 = 54892, num2 = 391, function returns 5489213
*/
int
numUnion(int num1, int num2)
{
   int nResult;
   if(isIn(num1, num2)) {
      return num1;
   }
   else {
      nResult = num1 * (num2 % 10) + num2;
   }
   return nResult;
}


/* TO DO: Write the implementation for this function. (15 pts)

   This function returns the intersection of the digits found
   in num1 and num2. The new digit will be attached at the RIGHT.

   Pre-condition: num1 > 0, num2 > 0, each number has unique digits
   @param num1 - the first number
   @param num2 - the second number
   @return the new number representing the intersection of num1 and 
           num2; returns 0 when there is no intersection

   Requirements/Restrictions:
   1.) No printf() allowed in this function.
   2.) Required to call the function isIn() and meaningfully use
       its result, as part of the solution of this function.
   3.) Required to attach the new digits to the right as shown in
       samples below.  Other results will not be considered.

   Example 1: num1 = 56, num2 = 895264, function returns 65
   Example 2: num1 = 56, num2 = 896254, function returns 65
   Example 3: num1 = 9546, num2 = 24, function returns 4
   Example 4: num1 = 123, num2 = 9476, function returns 0
*/
int 
numIntersect(int num1, int num2)
{
   int nDigit;
   if(isIn(num1, num2)) {
      return num1;
   }
   else {
      return 0;
   }
}
