#include <stdio.h>

int main(){
    // There are other data types but with different capacities
    // Variables have a limit to how much can be contained
    
    // Whole number variants
    int nNum1   =  1;
    int Num2    =  2;
    int n_num3  =  3;
    int _nNum4  =  4;
    int nNUm1   =  5;
    int nAns;
    
    /*
    Conventions not allowed:
    1. Cannot start with a number.
    2. Must not have any other symbols except _.
    3. Cannot use existing keywords.
    
    Note: Names are case sensitive.
    */
    
    nAns = nNum1 + Num2 + n_num3 + _nNum4 + nNUm1;
    printf("This works %d\n", nAns);
    
    return 0;
}

/*
  ( ͡❛ ‿●‿ ͡❛)
  Be aware of the case sensitivity.
  
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_variables.htm
*/
