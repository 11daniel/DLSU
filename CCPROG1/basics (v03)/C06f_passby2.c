/*
  In some cases, one might have to call a pass by
  reference function inside another pass by reference
  function.
*/

#include <stdio.h>

// This is a passing a pointer in a function
void addFive(int *nNum){
    *nNum += 5;
}

// When one needs to pass a pointer in a function
// but will also feed a pointer, it may be confusing.
// Here are several ways to go about it.
void addTwenty(int *nNum){
    int nTmp = 0;
    
    // Method 1: New Variable Approach
    // One way to go about it is to create a new variable
    // and feed it. Then when the results are returned, 
    // feed the value into the pointer variable.
    addFive(&nTmp);
    *nNum += nTmp;

    // Method 2: Address of the pointed variable
    // Another method is to tell the function to go to the
    // pointer and then once at the address, take the 
    // address of where the pointed variable is.
    addFive(&*nNum);
    
    // Method 3: Direct Access
    // Since the pointer value contains an address and the
    // value is only obtained by going to where the address
    // is pointing to, one can simply use the address stored
    // in the variable.
    addFive(nNum);
    
    // Method 4: Bad method
    // One may be tempted to just copy the code from
    // the other function. This is a bad practise and
    // so use the other methods.
    *nNum += 5;
}

int main(){
    int nNum = 50;
    printf("Start Value: %d\n", nNum);
    addTwenty(&nNum);
    printf("End Value  : %d\n", nNum);
    return 0;
}

/*
  	(ˆ⺫ˆ๑)<3
  Passing a value and passing a pointer may take some time
  to get use to. But it will help clarify how functions
  interact with the main.
  
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_function_call_by_reference.htm
*/