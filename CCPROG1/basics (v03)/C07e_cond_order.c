#include <stdio.h>

int main(){
    int nGrade;
    printf("Enter grade: ");
    scanf("%d",&nGrade);
    
    if(nGrade>=60) // 1st
        if(nGrade>100) // 2nd
           printf("Invalid"); 
    else
        printf("Failed");
        
    if(nGrade>=70) 
        printf("Hello");
        printf("how are you?");

    return 0;
}

/*
  (ㆆ_ㆆ)
  Be aware on how the conditions are connected to each other.
  Use brackets to make it easier to understand.
*/
