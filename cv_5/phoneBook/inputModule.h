#include <stdio.h>

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


// Main function for reading number input
// - reads negative numbers as well
// - reads until end of input -> change endOfInput to 0
//         - use while (!endOfInput){}
int getNextNumber(int *endOfInput) {

    int digLowASCIIMargin = 48;
    int cCharASCII = getNextCharASCII();
    int signMinus = 0;
    int number = 0;

    // remove trash
    while (!isDigit(cCharASCII)) {
        if (cCharASCII == -1)  *endOfInput = 1;
        return 0;
        if (isMinus(cCharASCII)) signMinus = 1;
        cCharASCII = getNextCharASCII();
    };

    // get number
    while (isDigit(cCharASCII)) {
        int cDig = cCharASCII -  digLowASCIIMargin;
        number = number * 10 + cDig;
        cCharASCII = getNextCharASCII();
    }

    if (signMinus) number *= -1;

    return number;
}