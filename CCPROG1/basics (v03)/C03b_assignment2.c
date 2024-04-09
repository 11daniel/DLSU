#include <stdio.h>

int main(){

    // Variable with a declared value
    int nIndex = 1;
    printf("%d\n",nIndex);
    
    // A variable can have its contents
    // changed and will change its value
    nIndex = 2;
    printf("%d\n",nIndex);
    
    // One can also use a variable to update
    // the value of a variable
    nIndex = nIndex + 1;
    printf("%d\n",nIndex);
    
    // This way of writing is just a quick way
    // of saying this variable is increased by 1
    nIndex++;
    printf("%d\n",nIndex);
    
    return 0;
}

/*
     ༼ つ ◕_◕ ༽つ
  Assignments are a key concept used in many
  programs. Take time to understand it...
*/

