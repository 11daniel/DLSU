#include <stdio.h>

// This is an example of a nested conditional statement
// A conditional construct inside a conditional construct

int main(){
    int nYear;
    printf("Enter year: ");
    scanf("%d",&nYear);
    
    if(nYear%4!=0){
        printf("Not a leap year\n");
    }else{
        if(nYear%100!=0){
            printf("Is a leap year!\n");
        }else{
            if(nYear%400!=0)
                printf("Not a leap year\n");
            else
                printf("Is a leap year!\n");
        }//end else
    }//end else

    return 0;
}

/*
  ( ͡❛ ᴗ ͡❛)
  It may be confusing at times but take time and trace it out.
  
  Note: Be mindful of which else statement is paired with which
        if statement.
  
  External Ref:
  https://www.tutorialspoint.com/learn_c_by_examples/leap_year_program_in_c.htm
*/
