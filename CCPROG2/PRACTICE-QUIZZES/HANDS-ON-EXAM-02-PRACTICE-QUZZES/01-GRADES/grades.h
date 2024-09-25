/*
  grades.h   
  
  DO NOT CHANGE THE CONTENTS OF THIS HEADER FILE. 
  
  This file is included in the skeleton file GRADES-LASTNAME.c
*/

// maximum number of students
#define MAXNUM_STUDENTS   100

typedef char String[51];

/*
   This is the structure data type for a structure variable that will store
   data about a student.
*/
struct nameTag {
	String last;
	String first;
};

struct studentTag {  
	struct nameTag name;
	int practice_score; // Practice Quiz score
	int midterm_score;  // Midterm Exam score
};

/* 
	The following are the function prototypes for the functions that you will need to define. 
*/
void Print_Student_List(struct studentTag STUDENTS[], int nStudents);
int Append_Student_List(struct studentTag STUDENTS[], int nStudents, String lastname, String firstname, int practice, int midterms);
void Selection_Sort(struct studentTag STUDENTS[], int nStudents);
int Binary_Search(String param_lastname, String param_firstname, struct studentTag STUDENTS[], int nStudents);
int Build_List(int param_score,  struct studentTag STUDENTS[], int nStudents, struct studentTag newList[]);





