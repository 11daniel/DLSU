#include <stdio.h>

int main(){
    int nNum = 5;
    const unsigned int LENGTH = 6;
    int nLengthComp = (0<nNum&&nNum<LENGTH);
    int nOddComp = (nNum%2 == 1);
    printf("%d\n",(nLengthComp && nOddComp)+5);
    return 0;
}

/*
  (⊙︿⊙✿)
  The result of a boolean operation can be translated into a
  1 or 0 which can then be used as a nNumber.

  Try the following:
  1. remove the "== 1" in line 7
  2. remove the parenthesis on line 7 then put a ! before the var nNum
  3. remove "0<" from line 5
*/
