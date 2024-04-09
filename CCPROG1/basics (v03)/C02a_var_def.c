// This is where we look for the needed libraries
#include <stdio.h>

// Variables:
//     Variables are entities that can store a value that can
//     be changed during the execution of a program

int main(){
    // Variables are typically declared at the top in C
    // The way it is declared is:
    // <data-type> <variable-name> = <value>;
    
    // int - integer - whole number
    int nWholeNumber =  6;
    
    // float - decimal - number with decimals
    // Note: The "f" in the value can be removed and it will
    //       still be valid.
    float fDecimal = 3.5f;
    
    // char - character - 
    char cFirstLetter = 'A';
    
    // To display variable content, we use %d, %f or %c
    // The format for display is:
    // printf( "%d" , <variable-name> );
    printf("%d\n", nWholeNumber);
    printf("%f\n", fDecimal);
    printf("%c\n", cFirstLetter);
    
    // Double quotes are used to create strings. These are
    // sequences of characters grouped together. For now,
    // these will be used in specific functions.
    
    return 0;
}

/*
  There are other ways to declare variables and display
  data but try these out.

   ʕっ•ᴥ•ʔっ
  Note: The right value should be given to the variable
        with the correct data-type.
        
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_variables.htm
*/
