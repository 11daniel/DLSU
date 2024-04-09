// This is a comment, it does not affect the code.
// Think of it like notes one can leave in the code.

/*
  Another way to leave a comment is this way. This
  allows multiple lines of comments to be written
  as long as it starts with and ends with the right
  symbols.
*/

// This is where we look for the needed libraries
// #include - means use this library
// #stdio.h - pertains to the standard input output library
#include <stdio.h>


// This is the main function. It might not make sense
// but it will make more sense when functions are 
// discussed. For now, think of this as the process
// the computer will run first when the program starts.
int main(){
    // printf is a function used to display something
    // to the screen. It can display various characters.
    // \n means next line
    printf("hello world\n");

    // return 0 means the program exited properly
    return 0;
}

/*
  To run it, open a terminal where this file
  is and type:
  
  gcc C01_hello_world.c -o run.exe
  run.exe
  
  Congratulations on your first program!
      ⊂_ヽ
    　 ＼＼
    　　 ＼( ͡° ͜ʖ ͡°)
    　　　 >　⌒ヽ
    　　　/ 　 へ＼
    　　 /　　/　＼＼
    　　 ﾚ　ノ　　 ヽ_つ
    　　/　/
    　 /　/|
    　(　(ヽ
    　|　|、＼
    　| 丿 ＼ ⌒)
    　| |　　) /
    ノ )　　Lﾉ
    (_／
    
  External Ref:
  https://www.tutorialspoint.com/cprogramming/index.htm
*/
