#include "Displays.h"

int askInitialYears(){
	int nYears;
	printf("Input years    : ");
	scanf("%d", &nYears);
	return nYears;
}

void printAnswers(int nTotalYears, int nTotalCycles, int nTotalCrystals){
	printf("Total Years    : %3d\n", nTotalYears);
	printf("Total cycles   : %3d\n", nTotalCycles);
	printf("Total crystals : %3d\n", nTotalCrystals); 
}

void printMessageLetter(int nLetter){
    switch(nLetter){
        case 0:  printf("I"); break;
        case 1:  printf("L"); break;
        case 2:  printf("O"); break;
        case 3:  printf("V"); break;
        case 4:  printf("E"); break;
        case 5:  printf("U"); break;
        case 6:  printf("A"); break;
        case 7:  printf("L"); break;
        case 8:  printf("W"); break;
        case 9:  printf("A"); break;
        case 10: printf("Y"); break;
        case 11: printf("S"); break;
        case 12: printf("♥"); break;
        case 13: printf("!"); break;
        case 99: printf("\n"); break;
    }
}
