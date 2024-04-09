#include <stdio.h>

int main(){
    int nCycles = 5;
    int i,j;
    
    // Note the order of execution and which ones are part
    // of the execution scope
    for(i=0; i<nCycles; i++)
        printf("Flip-");
        printf("Flop\n"); // once
        
    //i = 0, 0<5, yes count 1
    //i = 1, 1<5, yes count 2
    //i = 2, 2<5, yes count 3
    //i = 3, 3<5, yes count 4  
    //i = 4, 4<5, yes count 5
    //i = 5, 5<5, no  count 5    
    
    // To have more than one statement in the initialization and 
    // of a for loop iteration. For this class, I will not be using
    // this commonly.
    for(i=0,j=nCycles; i<j; i++,j--){
        printf("Swish\n");
    }//end for
    
    //i=0,j=5 :0<5, yes count 1
    //i=1,j=4 :1<4, yes count 2
    //i=2,j=3 :2<3, yes count 3
    //i=3,j=2 :3<2, no  count 3
    
    return 0;
}

/*
  ≧◠‿●‿◠≦
  Loops now make it possible for the program to do things repetitively and so
  this releaves the programmer of needless re-typing.
*/
