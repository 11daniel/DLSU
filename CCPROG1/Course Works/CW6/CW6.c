/*
    Compile: gcc -Wall Displays.c CW6.c -o run.exe
    Run:     ./run.exe or run.exes
*/
#include <stdio.h>
#include "Displays.h"

void printMessage(int crystals) {
	for (int i = 0; i <= crystals; i++) {
		printMessageLetter(i);
	}
	printMessageLetter(99);
}

int getCrystals(int nInput) {
	int crystals = 0;
	crystals = nInput / 9;
	return crystals;
}

int getYears(int nCrystals) {
	int years;
	years = nCrystals * 6;
	return years;
}

int main(){
    int nYears = 0;
    int years = 0;
    int crystals;
	int nTotalYears = 0;
	int nTotalCrystals = 0;
	int nTotalCycles = 0;

	nYears = askInitialYears();
	crystals = getCrystals(nYears);
	nTotalYears = nYears;
	nTotalCrystals = crystals;

	if (crystals > 0) {
		nTotalCycles++;
		printMessage(crystals);
	}

	while (crystals > 0) {
		years = getYears(crystals);
		crystals = getCrystals(years);
		nTotalYears += years;
		nTotalCrystals += crystals;
		nTotalCycles++;

		printMessage(crystals);
	}

	printAnswers(nTotalYears, nTotalCycles, nTotalCrystals);
	return 0;
}