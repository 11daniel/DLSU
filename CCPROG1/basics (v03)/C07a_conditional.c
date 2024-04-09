#include <stdio.h>

// Conditional statements:
//     are statements that check certain conditions (boolean
//     expressions) before executing certain statements.

int main(){
    int nGrade;
    printf("Enter grade: ");
    scanf("%d",&nGrade);
    
    // declaration is as follows
    // if (<boolean value>)
    if(nGrade<0)
        printf("Grade is invalid!\n");
    
    // The else statement is what is executed should
    // the condition be false.
    if(nGrade >= 70)
        printf("student pass\n");
    else
        printf("student fail\n");
    
    // It is also possible to clump multiple statements
    // by using parenthesis.
    if(nGrade >= 90){
        printf("High grades!\n");
        printf("Very Good!\n");
    }
    
    // Note: else statements are optional and may not be
    //       included per if statement.
    
    return 0;
}

/*
  (>^_^)><(^o^<)
  This is a very powerful programming construct. With this, your code
  can now make decisions on what to do with the data.
  
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_decision_making.htm
*/
