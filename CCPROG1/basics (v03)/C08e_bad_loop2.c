/*
🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫
 *   * ***** ***** *   * ***** *   * *****
 *   * *   * *   * **  *   *   **  * *   
 * * * ***** ***** * * *   *   * * * * ***
 ** ** *   * *  *  *  **   *   *  ** *   *
 *   * *   * *   * *   * ***** *   * *****
🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫

 The task is add all the numbers between two numbers
 but are even.
*/

#include <stdio.h>

// Do not use continue to skip the iteration of a loop
int sumEven1(int nStart, int nEnd){
    int i, nSum=0;
    for(i=nStart; i<=nEnd; i++){
        if(i%2==1)
            continue;
        nSum += i;
    }//end for
    return nSum;
}

// This is a better way to do it.
int sumEven2(int nStart, int nEnd){
    int i, nSum=0;
    for(i=nStart; i<=nEnd; i++){
        if(i%2==0)
            nSum += i;
    }//end for
    return nSum;
}

int main(){
    int nStart = 5, nEnd = 10;
    
    printf("Sum 1: %d\n", sumEven1(nStart,nEnd));
    printf("Sum 2: %d\n", sumEven2(nStart,nEnd));
    return 0;
}

/*
  ლ( ͡X ﹏ ͡X)ლ
  Again, do not do these things.
*/
