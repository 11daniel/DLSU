#include <stdio.h>

// The switch statement is a special kind of
// conditional statement.

int main(){
    int nMonth;
    printf("Enter month: ");
    scanf("%d",&nMonth);
    switch(nMonth){
        case 1:
            printf("Jan\n");
            break;
        case 2: printf("Feb\n");break;
        case 3: printf("Mar\n");break;
        case 4: printf("Apr\n");break;
        case 5: printf("May\n");break;
        case 6: printf("Jun\n");break;
        case 7: printf("Jul\n");break;
        case 8: printf("Aug\n");break;
        case 9: printf("Sep\n");break;
        case 10: printf("Oct\n");break;
        case 11: printf("Nov\n");break;
        case 12: printf("Dec\n");break;
        default: printf("Not a month\n");break;
    }
    
    //Note: break is a statement that interupts the
    //      execution of the switch code. Though it
    //      can be used in other parts of the code
    //      it is discouraged for now.
    
    return 0;
}

/*
  (づ￣ ³￣)づ
  To make this case easier, a special kind of condition exists.
  This is called the switch statement.

  Try the following:
  1. run the program and place 13 as input.
  2. add another printf line after line 8.
  3. remove the break; part on like 9(or 10) then run the program. Type 1 as input.
*/
