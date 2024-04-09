#include <stdio.h>

int getZeroPad(int nPad){
	int nRet = 1;
	while(nPad>1){
    	nRet*=10;
    	nPad--;
	}//end while
	return nRet;
}

int main(){
	int nId, nPad, nMonth;
	printf("Type your id Number: ");
	scanf("%d",&nId);
    
	for(nPad=1,nMonth=0;nId>getZeroPad(nPad);nPad++){
    	nMonth += nId/getZeroPad(nPad)%10*nPad;
	}//end for
    
	switch(12-nMonth){
    	default: printf("January\n");   break;
    	case 2:  printf("February\n");  break;
    	case 3:  printf("March\n"); 	break;
    	case 4:  printf("April\n"); 	break;
    	case 5:  printf("May\n");   	break;
    	case 6:  printf("June\n");  	break;
    	case 7:  printf("July\n");  	break;
    	case 8:  printf("August\n");   break;
    	case 9:  printf("September\n"); break;
    	case 10: printf("October\n");   break;
    	case 11: printf("November\n");  break;
    	case 12: printf("December\n");  break;
	}//end switch
    
	return 0;
}//end main
