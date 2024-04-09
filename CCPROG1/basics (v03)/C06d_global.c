#include <stdio.h>

// Global variables are variables that can be used
// by all functions. Typically, a function.
#define INCREMENT 5
const float PI = 3.14f;

void increase(int *nVar){
    *nVar = *nVar + INCREMENT;
}

// variables declared in a function can only be
// used in a function. Using nTemp
void trippleIncrease(int *nVar){
    int nTemp = *nVar + *nVar + *nVar;
    *nVar = nTemp;
}

int main(){
    int nNum = 0;
    
    increase(&nNum);
    increase(&nNum);
    trippleIncrease(&nNum);
    trippleIncrease(&nNum);
    

    // Though these work, it is not good coding practise.
    // It could lead to problematic tracing. It is best
    // to use local variables and simply pass them.
    printf("nNum is %d\n", nNum);
    
    // If there is any exemption to the rule, it would be
    // in the use of constants.
    printf("PI is %f\n", PI);
    return 0;
}

/*
  ( ͡* - ͡*)
  Global variables are just typically used for constants.
  
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_function_call_by_reference.htm
*/
