#include <stdio.h>

int main(){
    // When a decmial value gets placed in an int
    // container, the value is translated
    int nContainer1 =  72.5f;
    
    // The same is true for float containers, when
    // a character is given, it will convert it into
    // a number. Look for the ascii table to know
    // what value will be the result.
    float fContainer2 = 'A';
    
    // If the exact value of the ascii character is known
    // it can be fed directly into a character variable
    char cContainer3 = 81;
    
    printf("C1->d: %d\n", nContainer1);
    
    // The int container can also be viewed as a
    // character. This is because each character is assigned
    // a specific value through the ASII standard
    printf("C1->d: %c\n", nContainer1);
    
    printf("C2->f: %f\n", fContainer2);
    
    printf("C3->c: %c\n", cContainer3);
    printf("C3->d: %d\n", cContainer3);

    // Also know that int and float have capacities. If
    // the value to be contained is much larger, look
    // at the long and double data-types.
    
    return 0;
}

/*
  ☉ ‿ ⚆
  These are corner cases but may be useful in certain
  applications.
  
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_variables.htm
*/

