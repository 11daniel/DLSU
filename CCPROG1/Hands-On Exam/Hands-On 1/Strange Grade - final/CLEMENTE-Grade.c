/******************************************
TO DO: Update with your name and section below

Problem: The Strange Grade
Author: Daniel Gavrie Clemente
Section: Block 09 S19B
******************************************/

/* TO DO: Complete the function to perform as intended.  (10 pts)

   This function takes in three pointers and updates these with 
   with values as indicated below.
   
   @param pQuiz1 is the address where the first value given by
                 the user as input will be placed
   @param pQuiz2 is the address where the second value given by
                 the user as input will be placed
   @param pQuiz3 is the address where the average of the quizzes
                 will be stored     
*/
void
encodeQuizzes( float *pQuiz1,float *pQuiz2,float *pQuiz3 )
{
    float fQuiz1, fQuiz2;
    scanf("%f\n", &fQuiz1);
    scanf("%f\n", &fQuiz2);
    *pQuiz1 = fQuiz1; // This line can be modified or removed
    *pQuiz2 = fQuiz2; // This line can be modified or removed
    *pQuiz3 = (*pQuiz1 + *pQuiz2)/2; // This line can be modified or removed
}

/* TO DO: Complete the function to perform as intended.  (10 pts)

   This function takes in two pointers (pHO1 and pHO2) and extracts 
   the values based on 1 integer input from the user. Refer to the problem
   specifications (the pdf file) on how the value extraction is done.
   
   @param pHO1 is the address that will refer to the 2 left digits
          of the original number.
   @param pHO2 is the address that will refer to the 2 right digits
          of the original number.
   
*/
void
encodeHandsOn( int * pHO1, int * pHO2 )
{
    int nHO;
    scanf("%d", &nHO);
    *pHO1 = nHO / 100; // This line can be modified or removed
    *pHO2 = nHO % 100; // This line can be modified or removed
}

/* TO DO: Complete the function to perform as intended. (10 pts)
		
   This function takes in several kinds of grades and will compute
   the total grade. See the instructions on how the diminishing
   grade is computed from the problem specs.
   
   @param fActivities contains a portion of the grade
   @param fMidterms contains a portion of the grade
   @param fHandsOn contains a portion of the grade
   @param fFinals contains a portion of the grade
   @param fProject contains a portion of the grade
   
   @return the total diminished grade
*/
float computeDiminishingTotal(float fActivities, float fMidterms,
                        float fHandsOn, float fFinals, float fProject) {
    return (fActivities/100)*(fMidterms/100)*(fHandsOn/100)*(fFinals/100)*(fProject/100)*100;  // This line can be modified or removed
}

/* TO DO: Complete the function to perform as intended. (10 pts) 
       
   Restrictions and Requirements:
     * The use of conditional constructs is not permitted 
       and a grade of zero will be given for this function should 
	   conditional constructs be used.
 

   This function checks if the grade fed is a failing grade or not.
   
   @param fGrade contains the grade to be checked
   @return 1 if fGrade is below 60 and returns 0 otherwise
*/
int isFail(float fGrade) {
    return fGrade < 60;  // This line can be modified or removed
}

/*  TO DO: Complete the function to perform as intended.  (10 pts)
      
	Restrictions and Requirements:
     * The use of conditional constructs is not permitted 
       and a grade of zero will be given for this function should 
	   conditional constructs be used.
 

   This function takes in the grades for the activities, midterms, 
   hands-on exams, final exam and final project and will determine 
   if the project grade is the lowest grade among the given grades. 

   @param fActivities contains a portion of the grade
   @param fMidterms contains a portion of the grade
   @param fHandsOn contains a portion of the grade
   @param fFinals contains a portion of the grade
   @param fProject contains a portion of the grade

   @return 1 if fProject is the lowest grade among all the parameters
           and return 0 otherwise
*/
int
isMPLowest(float fActivities, float fMidterms, float fHandsOn,
           float fFinals, float fProject)
{
    return fProject < fActivities && fProject < fMidterms && fProject < fHandsOn 
    && fProject < fFinals;  // This line can be modified or removed
}

