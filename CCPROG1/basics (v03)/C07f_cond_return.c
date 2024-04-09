/*
🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫
 *   * ***** ***** *   * ***** *   * *****
 *   * *   * *   * **  *   *   **  * *   
 * * * ***** ***** * * *   *   * * * * ***
 ** ** *   * *  *  *  **   *   *  ** *   *
 *   * *   * *   * *   * ***** *   * *****
🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫🚫

There is a code function here that should not
be done.
*/
#include <stdio.h>

// This syntax is correct and will work but one should
// get use to how the code executes in order.
int getReverseBad(int nNum){
    int nOnes, nTens, nHnds;
    if(nNum<100 || nNum>999)
        return -1;
    
    nOnes = nNum%10;
    nTens = nNum/10%10;
    nHnds = nNum/100;
    return nOnes*100+nTens*10+nHnds;
}

// Structure the code in this way instead
int getReverseGood(int nNum){
    int nOnes, nTens, nHnds, nRet;
    if(nNum<100 || nNum>999){
        nRet = -1;
    }else{
        nOnes = nNum%10;
        nTens = nNum/10%10;
        nHnds = nNum/100;
        nRet = nOnes*100+nTens*10+nHnds;
    }
    return nRet;
}

void displayRev(int nNum){
    if(nNum<0)
        printf("Number input invalid\n");
    else
        printf("Reverse: %d\n", nNum);
}

int main(){
    int nNum, nRev1, nRev2;
    printf("Enter 3 digit number: ");
    scanf("%d",&nNum);
    
    nRev1 = getReverseBad(nNum);
    nRev2 = getReverseGood(nNum);

    displayRev(nRev1);
    displayRev(nRev2);
    return 0;
}

/*
  ʕ•́ᴥ•̀ʔっ
  It is not enough that it works, it should also work well.
  This at the start, follow these practises so one can get
  use to tracing execution.
*/
