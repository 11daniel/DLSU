#include <stdio.h>

int main(){
    int nMyst1 = 1+2*3;
    int nMyst2 = 1+2*3/4;
    float fMyst3 = 4/3   +-2;
    float fMyst4 = 4/3.0f+-2;
    float fMyst5 = 1+3/4*2.0f;
    float fMyst6 = 1+3/4.0f*2;
    printf("%d\n",nMyst1);
    printf("%d\n",nMyst2);
    printf("%f\n",fMyst3);
    
    // This is how to state how many decimal points
    // will be shown in the terminal.
    printf("%.3f\n",fMyst4);
    printf("%.2f\n",fMyst5);
    printf("%.1f\n",fMyst6);
    return 0;
}

/*
  (ノಠ益ಠ)ノ彡┻━┻
  Dont get frustrated but carefully break down each part.
  Note: Do not forget, when two integers are operated on, the
      result is also an int. But if one of the two is a float,
      the result becomes a float.
*/
