/* 
   Header file for the POPULATION problem.
   
   DO NOT CHANGE THE CONTENTS OF THIS FILE. 
*/


/* size of the YEAR[] and POPULATION arrays */
#define MAX_SIZE 30


/* You may or may not use the following constants in your solution */
#define PERCENT_ADULT   (60.0/100.0)
#define PERCENT_FEMALE  (51.0/100.0)
#define PERCENT_SENIOR  (11.0/100.0)


/* Function prototypes for the functions to be implemented. */

// Q1: How many males were there in year <param_year>?
double Q1(int YEAR[], int POPULATION[], int nYears, int param_year);

// Q2: How many senior citizens were there in year <param_year>? 
double Q2(int YEAR[], int POPULATION[], int nYears, int param_year);

// Q3: What is the annual population growth rate (in percent) in year <param_year>?
double Q3(int YEAR[], int POPULATION[], int nYears, int param_year);

// Q4: What is the lowest annual population growth rate?
double Q4(int YEAR[], int POPULATION[], int nYears);

// Q5: What is the average annual population growth rate?
double Q5(int YEAR[], int POPULATION[], int nYears);


