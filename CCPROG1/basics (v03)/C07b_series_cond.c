#include <stdio.h>

int main(){
    int nMonth;
    printf("Enter month: ");
    scanf("%d",&nMonth);
    if(nMonth == 1){
        printf("Jan\n");
    }else if(nMonth == 2){
        printf("Feb\n");
    }else if(nMonth == 3){
        printf("Mar\n");
    }else if(nMonth == 4){
        printf("Apr\n");
    }else if(nMonth == 5){
        printf("May\n");
    }else if(nMonth == 6){
        printf("Jun\n");
    }else if(nMonth == 7){
        printf("Jul\n");
    }else if(nMonth == 8){
        printf("Aug\n");
    }else if(nMonth == 9){
        printf("Sep\n");
    }else if(nMonth == 10){
        printf("Oct\n");
    }else if(nMonth == 11){
        printf("Nov\n");
    }else if(nMonth == 12){
        printf("Dec\n");
    }else{
        printf("Not a month\n");
    }//end else
    return 0;
}

/*
  (T_T)
  Sometimes, there will be cases where one variable is compared to many
  different values. In cases like these, there is a special conditional
  construct that can help.
*/
