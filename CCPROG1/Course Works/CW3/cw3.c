/*
	To compile this file:
	gcc cw3Ans.c cw3.c -o run.exe
	
	To run this file using the input files:
	run.exe < cw3-in1.txt
	run.exe < cw3-in2.txt
*/

#include "cw3Ans.h"

int main(){
    float fInput, fInput2;
    
    printf("Input stick : ");
    scanf("%f", &fInput);
    printf("Output stone: %.2f\n\n", convertStickToOunce(fInput));
    
    printf("Input USD   : ");
    scanf("%f", &fInput);
    convertUSDToSGD(&fInput);
    printf("Output SGD  : %.2f\n\n", fInput);
    
    printf("Input gold  : ");
    scanf("%f", &fInput);
    printf("Input cash  : ");
    scanf("%f", &fInput2);
    printf("Converted   : %.2f\n", convertGoldToPHP(fInput,&fInput2));
    printf("Output cash : %.2f\n\n", fInput2);
    
    printf("Input orange: ");
    scanf("%f", &fInput);
    printf("Input mango : ");
    scanf("%f", &fInput2);
    printf("Output cups : %d\n\n", convertFruitToJuice(fInput,fInput2));
    
    printf("Input metal : ");
    scanf("%f", &fInput);
    printf("Output toys : %d\n", convertMetalToToys(fInput));
    return 0;
}

