#include <stdio.h>

/*
  Here we declare our own functions or user-defined functions.
  These function declarations has different parts:
    return type - the type of value returned by the function
    function name - the label of the function
    parameters - inputs needed by the program to run
    body - code that would be executed
*/
void printHW(){
    printf("hello world\n");
}

// This function shows how parameters are used
void printSum(int nNumA, int nNumB){
    printf("%d + %d = %d\n",nNumA,nNumB,nNumA+nNumB);
}

// This function shows how return values are used
int giveFive(){
    //the data type returned must be the same data-type
    return 5;
}

// This function shows both paramaters and returned are used
// If the number of parameters are too many, it is possible to
// put the other parameters on another line.
int sumNumbers(int nNumA, 
        int nNumB){
    return nNumA + nNumB;
}

// Typically, the program reads a from top to bottom which
// is why user-defined functions are declared above the
// main function. But if the name of the function is
// declared, the body can be declared bellow the main.
// This is refered to as a function prototype.
int giveSeven();

int main(){
    int nNumber = 2;
    printHW();
    printSum(nNumber,6);

    nNumber = giveFive()+giveSeven();
    printf("%d\n",nNumber);

    printf("%d\n",sumNumbers(2,nNumber));
    return 0;
}

// The content of the function (the series of instructions)
// and its header is called the function declaration.
int giveSeven(){
    return 7;
}

/*
  (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧
  Group code statements commonly used so it does not need
  to be pasted often.
  
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_functions.htm
*/
