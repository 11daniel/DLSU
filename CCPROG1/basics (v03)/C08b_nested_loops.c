#include <stdio.h>

int main(){
    int nNumI;
    int nNumJ;
    for(nNumI=0; nNumI<5; nNumI++){
        for(nNumJ=0; nNumJ<5; nNumJ++){
            printf("%d\n",nNumI*5+nNumJ+1);
        }//end for
        printf("*\n");
    }//end for
    return 0;
}

/*
  (;° ロ°)
  The code shows what a nested loop looks like. This means a loop
  inside another loop.

  Try the following:
  1. in line 7, change the starting value of nNumJ from 0 to nNumI
  2. in line 7, change the ending condition to nNumJ<nNumI
  3. in line 7, change the ending condition to nNumJ<=5
*/
