#include <stdio.h>

int main(){
    // Another way to define variables is by not giving it values
    // in the form:
    // <data-type> <variable-name>;
    int nWholeNumber;
    float fDecimal;
    char cFirstLetter;
    
    // This variable will contain garbage values. Some compilers
    // will assign a default value but this depends on the
    // compiler. Assume the contents are garbage.
    printf("|%d| $%f$*%c*\n", nWholeNumber, fDecimal, cFirstLetter);
    
    //Note: To display multiple things, use multiple %xs and have
    //      variables separated by commas.
    
    return 0;
}

/*
  ( ͡❛ ‿●‿ ͡❛)
  This is another way to declare variables.

  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_variables.htm
*/
