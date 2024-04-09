/*
    Compile:
    gcc MockExam1Ans.c MockExam1Main.c -o run.exe
    
*/
#include <stdio.h>
#include "MockExam1Ans.h"

int main(){
    char cIn1, cIn2, cIn3, cIn4; 
    
    printf("Input small letters for all\n");
    printf("Input letter 1: ");
    scanf("%c", &cIn1);
    printf("Input letter 2: ");
    scanf(" %c", &cIn2);
    printf("Input letter 3: ");
    scanf(" %c", &cIn3);
    printf("Input letter 4: ");
    scanf(" %c", &cIn4);
    
    printf("\nFor inputs: %c%c%c%c\n", cIn1, cIn2, cIn3, cIn4);
    printf( " Is letter 1 before k: %d\n", isBeforeK(cIn1) );
    printf( " Is letter 2 a vowel : %d\n", isVowel(cIn2) );
    printf( " Is letter 3 before k: %d\n", isBeforeK(cIn3) );
    printf( " Is letter 4 a vowel : %d\n", isVowel(cIn4) );
    
    toUpperCase(&cIn1);
    toUpperCase(&cIn2);
    toUpperCase(&cIn3);
    toUpperCase(&cIn4);
    
    printf( " If in all capitals  : %c%c%c%c\n", cIn1, cIn2, cIn3, cIn4);
    printf( " Is pallindrome      : %d\n",
            isPalindrome(cIn1, cIn2, cIn3, cIn4));
    printf( " Pallindrome distance: %d\n\n",
            computePallindromeDistance(cIn1, cIn2, cIn3, cIn4));
    return 0;
}
