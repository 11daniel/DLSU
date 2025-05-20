/* 
    This file contains the main() function for the GRADES problem.
	
	It is this file that you should compile and run.		
*/

/* DO NOT CHANGE THE #include below.  You are NOT allowed to include other files. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
   TO DO:  change the #include below to the file with your own lastname.  For example if your lastname
   is SHAZAM, then it should be changed to #include "GRADES-SHAZAM.c".
   
*/
#include "GRADES-CLEMENTE.c"

/*
    Understand the following function definition but do NOT change its contents.	 
*/
int
Initialize_Student_List(struct studentTag STUDENTS[])
{
    int ctr = 0;
	struct studentTag s;
	
	while (scanf("%s %s  %d %d", s.name.last, s.name.first, &s.practice_score, &s.midterm_score) == 4) {
			STUDENTS[ctr] = s;
			ctr++; 
	}		
	return ctr;
}

/*
   You are given this main() to help you test your five function definitions.
   
   Understand the sample function calls.  They serve as your guide to properly 
   implementing your solution.

   Take note that the teacher-in-charge of checking your solution will not necessarily
   use this main.c.  
   
   A different main.c with a different main() and another set of student data values
   will be used for black box testing.
*/
int
main()
{
	struct studentTag STUDENTS[MAXNUM_STUDENTS];  // this is the array of structures
    int nStudents; // number of student structures 
		
	struct studentTag NewList[MAXNUM_STUDENTS];   // this will hold the answer to the query in Task #5
	int nElements; // actual number of elements (structures) stored in the newList array
		
		
	/* Initialize the contents of STUDENTS[] array. */
	nStudents = Initialize_Student_List(STUDENTS);   
	
    
	/* Test solution for TASK #1 */
	printf("**TEST-01:Print_Student_List()**\n");
    Print_Student_List(STUDENTS, nStudents);
    printf("nStudents = %d\n", nStudents);    
    printf("\n");


    /* Test solution for TASK #2 */	
	printf("**TEST-02:Append_Student_List()**\n");    
	nStudents = Append_Student_List(STUDENTS, nStudents, "MAKINO", "ICHIRO", 30, 50);
	nStudents = Append_Student_List(STUDENTS, nStudents, "HIMURA", "KAORU", 6, 40);
	nStudents = Append_Student_List(STUDENTS, nStudents, "SUZUKI", "AKIKO", 1, 21);	
	
	Print_Student_List(STUDENTS, nStudents);
	printf("nStudents %d\n", nStudents);    
    printf("\n");

    
	/* Test solution for TASK #3 */	
	printf("**TEST-03:Selection_Sort()**\n");    
	Selection_Sort(STUDENTS, nStudents);
	
	Print_Student_List(STUDENTS, nStudents);
	printf("\n");


	/* Test solution for TASK #4 */
	printf("**TEST-04:Binary_Search()**\n"); 
	printf("%d\n", Binary_Search("MAKINO", "ICHIRO", STUDENTS, nStudents));  // found test case
	printf("%d\n", Binary_Search("HIMURA", "KAORU", STUDENTS, nStudents));   // found test case	
	printf("%d\n", Binary_Search("SUZUKI", "JOSELITO", STUDENTS, nStudents)); // not found test case
	printf("\n");
	

	/* Test solution for TASK #5 */
	// Who are the students who got lower than 30 in the Midterm Exam and did NOT solve the Pactice Quiz?
	printf("**TEST-05:Build_List()**\n");    
	nElements = Build_List(30, STUDENTS, nStudents, NewList);  
	
	Print_Student_List(NewList, nElements);
    printf("nElements = %d\n", nElements);       
	
   	return 0;
}

