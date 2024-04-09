/*
    To compile the program: gcc -Wall HO1_P2.c -o p2.exe
	To run the program in Windows: p2
	To run the program in Mac: ./p2.exe
*/

/* You are not allowed to modify the contents of this 
   except on line 11 */
   
#include <stdio.h>
#include "CLEMENTE-Grade.c" /* replace this line with the actual filename
                               you used.  For example, the file containing
							   your solution for all functions is in 
							   SANTOS-Grade.c, then indicate
							   #include "SANTOS-Grade.c"
							*/

int main()
{
    float fQuiz1, fQuiz2, fQuiz3;
    int   nHO1, nHO2;
    float fActivies;
    float fMidterms = 96.0;
    float fHandsOn;
    float fFinals   = 88.5;
    float fProject  = 75;
    float fTotalGrade;
    
    encodeQuizzes(&fQuiz1, &fQuiz2, &fQuiz3);
    encodeHandsOn( &nHO1, &nHO2 );
    printf( "Results\n" );
    printf( " Quiz  : %.2f %.2f %.2f\n",fQuiz1,fQuiz2,fQuiz3 );
    printf( " HO1&2 : %d %d\n", nHO1, nHO2 );
    fActivies = ( fQuiz1 + fQuiz2 + fQuiz3 ) / 3;
    fHandsOn  = ( nHO1 + nHO2 ) / 2.0;
    fTotalGrade = computeDiminishingTotal( fActivies,fMidterms,
                                           fHandsOn,fFinals,fProject );
    printf( " Total : %.2f\n",fTotalGrade );
    printf( " Fail  : %d\n",isFail(fTotalGrade) );
    printf( " MP low: %d\n",isMPLowest(fActivies,fMidterms,
                                       fHandsOn,fFinals,fProject) );

    return 0;
}
