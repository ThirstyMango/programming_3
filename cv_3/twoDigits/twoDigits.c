#include "module.h"
#include <math.h>
#include <stdio.h>
#define LOW_MARGIN_ASCII_DIG 48;

int getLastTwoInputRowDigits(){
    int penultimateASCII = 0, ultimateASCII = 0;

    int cChar = getNextCharASCII();
    while (isDigit(cChar)){
        penultimateASCII = ultimateASCII;
        ultimateASCII = cChar;
        cChar = getNextCharASCII();
    }

    int ultimate = ultimateASCII -  LOW_MARGIN_ASCII_DIG;

    if (!penultimateASCII){
        return ultimate;
    }

    int penultimate = penultimateASCII - LOW_MARGIN_ASCII_DIG;

    return penultimate * 10 + ultimate;
}

int getLastNDigits(int number, int n){
    int base = 10;
    int lastNDigits =  number % (int)pow(base, n);
    return lastNDigits;
}

int main(){
    int baseLastTwo = getLastTwoInputRowDigits();
    
    int cLastTwo = 1;
    int cPowerCharASCII = getNextCharASCII();
    while (isDigit(cPowerCharASCII)){
        int cDigit = cPowerCharASCII - LOW_MARGIN_ASCII_DIG;

        switch (cDigit){
            case 0:
                cLastTwo = getLastNDigits(cLastTwo * cLastTwo, 2);
                break;
            case 1:
                cLastTwo = getLastNDigits(cLastTwo * cLastTwo * baseLastTwo, 2);
                break;
        }

        cPowerCharASCII = getNextCharASCII();
    }

    if (cLastTwo < 10){
        printf("0%d\n", cLastTwo);
        return 0;
    }

    printf("%d\n", cLastTwo);
    return 0;
}