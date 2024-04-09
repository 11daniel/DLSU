#include <stdio.h>

// Assignment:
//     An assignment statement stores a value or a computational
//     result in a variable.

int main(){
    // Variables could be declared with no values assigned
    int   nWholeNumber;
    float fDecimal;
    char  cFirstLetter;
    
    // The = sign is used to assign a value to a variable
    // their data types must correspond to the correct types
    nWholeNumber = 123;
    fDecimal     = 62.111f;
    cFirstLetter = 'A';
    
    // Different variables with different data-types can be
    // displayed on a single print
    printf("%d\n%f\n%c\n", nWholeNumber, fDecimal, cFirstLetter);
    
    return 0;
}

/*
    ༼ つ ╹ ╹ ༽つ
  Now try to use const on one the variables and see
  what happens to the program.
*/

