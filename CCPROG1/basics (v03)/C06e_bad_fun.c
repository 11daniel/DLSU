/*
🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫
 *   * ***** ***** *   * ***** *   * *****
 *   * *   * *   * **  *   *   **  * *   
 * * * ***** ***** * * *   *   * * * * ***
 ** ** *   * *  *  *  **   *   *  ** *   *
 *   * *   * *   * *   * ***** *   * *****
🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫

Everything in this file are things that should
not be done.
*/

#include <stdio.h>

// This is a global variable which is a variable
// placed in the body. This should not be done
// as there are complications in coding later on.
int nCounter = 0;

void increaseCounter(int nInc){
    nCounter += nInc;
}

int main(){
    increaseCounter(5);
    increaseCounter(7);

    printf("%d", nCounter);
    return 0;
}

/*
  ლ( ͡X ﹏ ͡X)ლ
  Again, do not do these things.
*/
