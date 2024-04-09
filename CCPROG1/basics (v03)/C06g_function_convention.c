#include <stdio.h>

// Some declare functions with the curly bracket beside the parameters
int fun1(int nNum1, int nNum2, int nNum3){
    return nNum1 + nNum2 + nNum3;
}

// Some put the open curly bracket at the next line
int fun2 (int nNum1, int nNum2, int nNum3)
{
    return nNum1 + nNum2 + nNum3;
}

// Some declare functions is by putting the return type on a separate
// line from the function name. They may also put the parameters at
// separate lines. 
int
fun3(   int nNum1, // Some even chose to comment on each variable
        int nNum2, // Though this can be done, it may not be
        int nNum3) // necessary if the function is obvious.
{
    return nNum1 + nNum2 + nNum3;
}

// PLEASE DO NOT make functions that do not follow typical coding
// convention. This is difficult to read by other developers.
int fun4                                                                    (
        int nNum1                                                           , 
        int nNum2                                                           , 
        int nNum3                                                           ){
    return nNum1 + nNum2 + nNum3                                            ;
                                                                            }

int main(){
    printf("F1: %d\n",fun1(1, 2, 3));
    printf("F2: %d\n",fun2(1, 2, 3));
    printf("F3: %d\n",fun3(1, 2, 3));
    printf("F4: %d\n",fun4(1, 2, 3));
    return 0;
}

/*
  ☉ ‿ ⚆
  Write code in a way that is easy to understand. Not just by you
  but by other developers. This is why the coding standards exist.
*/
