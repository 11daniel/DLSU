#include <stdio.h>

// Event-Controlled Loops:
//     This structure continues to loop until some condition is met.


int main(){
    int nWhileVar = 4;
    int nDowhileVar = 4;
    int nForVar;
    // while loop - checks the condition first
    while(nWhileVar < 5){
        printf("While-%d\n",nWhileVar);
        nWhileVar = nWhileVar + 1;
    }

    // do-while loop - checks the condition after processing
    do{
        printf("Do-while-%d\n",nDowhileVar);
        nDowhileVar = nDowhileVar + 1;
    }while(nDowhileVar < 5);

    // for loop - loop for a set number of times
    for(nForVar = 4; nForVar < 5; nForVar++){
        printf("For-%d\n",nForVar);
    }
    return 0;
}

/*
  ＼(^▽^＠)ノ
  Loops now make it possible for the program to do things repetitively and so
  this releaves the programmer of needless re-typing.

  Try the following:
  1. set the initial values of nWhileVar, nDowhileVar, and nDowhileVar to 5.
  2. change the conditions to 10'000 e.g line 6: while(nWhileVar < 10000){
  3. change the conditions to greater than of equal to zero
     e.g line 6: while(nWhileVar >= 0){
     
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_loops.htm
*/
