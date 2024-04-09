#include <stdio.h>

// This passes a value
void fnA(int nVar){
    nVar = 2;
}

// This passes a pointer
void fnB(int *nVar){
    *nVar = 2;
}


int main(){
    int nNumA = 1;
    int nNumB = 1;

    fnA(nNumA);
    fnB(&nNumB);
    
    printf("Num A %d\n",nNumA);
    printf("Num B %d\n",nNumB);
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
