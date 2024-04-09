#include <stdio.h>

int main(){
    int nWholeNumber;
    float fDecimal;
    int nAlive;
    char cFirstLetter;
    
    // & is used because an address is used
    // The topic of addresses willl be tackled later
    // for now just use it...
    scanf("%d", &nWholeNumber);
    printf("%d\n", nWholeNumber);
    printf("*********\n");

    scanf("%f %d", &fDecimal,&nAlive);
    printf("%d & %f\n", nAlive,fDecimal);
    printf("*********\n");

    // Make sure there is a white space before the %c
    // the system will consider the enter pressed as an input
    // and will disregard the prompt
    scanf(" %c", &cFirstLetter);
    printf("%c\n", cFirstLetter);
    
    return 0;
}

/*
   (ノ ゜Д゜)ノ ︵ ┻━┻
  (the program breaks)

  Make sure the values you input are correct or it will break the program.
  Try the to input the following:
  1.  2 , 3.1 , 0 , Q
  2.  2.6 , 12, 1
  
  External Ref:
  https://www.tutorialspoint.com/cprogramming/c_input_output.htm
*/
