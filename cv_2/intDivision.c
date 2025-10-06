#include <stdio.h>

int getIntDivision(int numerator, int denominator) {
    int div = numerator / denominator;
    return div;
}

int getNextCharASCII() {
    int nextNumberASCII = getchar();
    return nextNumberASCII;
}

int isDigit(int charASCII) {
    int lowerMargin = 48;
    int topMargin = 57;
    return (charASCII >= lowerMargin && charASCII <= topMargin);
}

int isMinus(int charASCII) {
    int minusASCII = 45;
    return (charASCII == minusASCII);
}

int getNextNumber(){

    int digLowASCIIMargin = 48;
    int cCharASCII = getNextCharASCII();
    int signMinus = 0;
    int number = 0;

    // remove trash
    while (!isDigit(cCharASCII)) {
        if (isMinus(cCharASCII)) signMinus = 1;
        cCharASCII = getNextCharASCII();
    };

    // get number
    while (isDigit(cCharASCII)) {
        int cDig = cCharASCII -  digLowASCIIMargin;
        number = number * 10 + cDig;
    }

    if (signMinus) number *= -1;

    return number;

}

int main() {
    int numeratorASCII = getNextNumber();
    int denominatorASCII = getNextNumber();

    int zeroASCII = 48;
    if (denominatorASCII == zeroASCII) printf("%s\n", "NELZE");

    int div = getIntDivision(numeratorASCII, denominatorASCII);
    
    printf("%d\n", div);

    return 0;

}