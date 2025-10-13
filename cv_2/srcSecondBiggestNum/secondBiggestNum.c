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

int getNextNumber() {

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
        cCharASCII = getNextCharASCII();
    }

    if (signMinus) number *= -1;

    return number;

}

int main() {
    
    int biggest = getNextNumber();
    int secondBiggest = getNextNumber();

    if (secondBiggest > biggest) {
        int temp = biggest;
        biggest = secondBiggest;
        secondBiggest = temp;
    }

    int cNum;
    while ((cNum = getNextNumber()) != -1){
        if (cNum > biggest){ 
            secondBiggest = biggest;
            biggest = cNum;
        } else if (cNum > secondBiggest){
            secondBiggest = cNum;
        }
    }
        

    printf("%d\n", secondBiggest);
    return 0;
    
}