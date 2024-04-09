/*
🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫
 *   * ***** ***** *   * ***** *   * *****
 *   * *   * *   * **  *   *   **  * *   
 * * * ***** ***** * * *   *   * * * * ***
 ** ** *   * *  *  *  **   *   *  ** *   *
 *   * *   * *   * *   * ***** *   * *****
🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫

 The task is to find the exponent with the base of 2
  task is implemented several ways.
*/
#include <stdio.h>

// Do not use break to exit a loop. This is a
// bad programming practise for beguinners.
int expCount1(int nNum){
    int nAns,nTracker=0;
    while(1){
        if(nNum==1){
            break;
        }//end if
        nNum/=2;
        nTracker++;
    }//end while
    return nTracker;
}

// Do not use return to exit a loop. This is a
// bad programming practise for beguinners.
int expCount2(int nNum){
    int nAns,nTracker=0;
    while(1){
        if(nNum==1){
            return nTracker;
        }//end if
        nNum/=2;
        nTracker++;
    }//end while
    return nTracker;
}

// Here is how the code would look like using
// good programming practises as a beguinner.
int expCount3(int nNum){
    int nAns,nTracker=0;
    while(nNum>1){
        nNum/=2;
        nTracker++;
    }//end while
    return nTracker;
}

int main(){
    int nNum = 2*2*2*2*2;
    
    printf("Way 1: %d\n", expCount1(nNum));
    printf("Way 2: %d\n", expCount2(nNum));
    printf("Way 3: %d\n", expCount3(nNum));
    return 0;
}

/*
  ლ( ͡X ﹏ ͡X)ლ
  Again, do not do these things.
*/
