#include <stdio.h>
#define DIG_LOW_ASCII_MARGIN 48
#define DIG_TOP_ASCII_MARGIN 57
#define spaceASCII 32
#define plusASCII 43
#define minusASCII 45
#define divideASCII 47
#define multiplyASCII 42



int getNextCharASCII() {
    int nextNumberASCII = getchar();
    return nextNumberASCII;
}

int isDigit(int charASCII) {
    int lowerMargin = 48;
    int topMargin = 57;
    return (charASCII >= lowerMargin && charASCII <= topMargin);
}

int getNextNumber(int firstDigit) {

    int cCharASCII = getNextCharASCII();
    int number = firstDigit;

    // get number
    while (isDigit(cCharASCII)) {
        int cDig = cCharASCII -  DIG_LOW_ASCII_MARGIN;
        number = number * 10 + cDig;
        cCharASCII = getNextCharASCII();
    }

    return number;

}

int evaluatePrefix(){
    int cCharASCII; // get First non space character
    while ((cCharASCII = getNextCharASCII()) == spaceASCII);

    if (isDigit(cCharASCII)){
        int firstDigit = cCharASCII - DIG_LOW_ASCII_MARGIN;
        int cNumber = getNextNumber(firstDigit);
        return cNumber;
    }

    int firstOperand = evaluatePrefix();
    int secondOperand = evaluatePrefix();

    switch (cCharASCII){
    case plusASCII:
        return firstOperand + secondOperand;
    case minusASCII:
        return firstOperand - secondOperand;
    case divideASCII:
        return (int)(firstOperand / secondOperand); // integer division
    case multiplyASCII:
        return firstOperand * secondOperand;
    }
}

int main(){
    int evaluatedPrefixNotation = evaluatePrefix();
    printf("%d\n", evaluatedPrefixNotation);
    return 0;
}