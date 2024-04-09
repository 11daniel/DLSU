#include <stdio.h>

int main(){
    // Booleans signify true and false values
    // 1 or up - true and 0 - false
    // What the symbols mean
    // && - AND
    // || - OR
    printf("%d\n",(1&&0));
    printf("%d\n",(1&&3));
    printf("%d\n",(1||0));
    printf("%d\n",(0||0));
    printf("%d\n",(0||1&&0));
    printf("%d\n",((0||1)&&0));
    printf("%d\n",(0<3&&3<6));
    return 0;
}

/*
  ( ◡́.◡̀)\(^◡^ )
  Although there is no direct data-type in C for boolean
  it is still very much used.

  Note: OR and AND are not exactly the same as in the
      English way of using it. Specially OR.
      
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_operators.htm
*/
