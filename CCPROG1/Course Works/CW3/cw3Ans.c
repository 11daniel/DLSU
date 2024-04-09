#include "cw3Ans.h"

float convertStickToOunce(float fStick){
    return fStick * 4.056506;
}

void convertUSDToSGD(float *nDollar){
    *nDollar = *nDollar / 0.693830742;
}

float convertGoldToPHP(float fOunces, float *fCash){
    float fOunce;
    fOunce = fOunces * 96312;
    *fCash = fOunce + *fCash - 500;
    return fOunce;
}

int convertFruitToJuice(float fOrange, float fMango){
    int nOrange = fOrange;
    int nMango = fMango;
    return nOrange / 5 + nMango / 3;
}

int convertMetalToToys(float fMetal){
    float fToy = fMetal / 2;
    float fAddToy = fToy / 6;
    return fToy + fAddToy;
}

