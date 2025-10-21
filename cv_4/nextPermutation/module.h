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


int printArray(int array[]){ // prints all the array elements like a string separated by spaces
    int cIndex = 0;
    int currElem = array[cIndex];
    while (currElem != -1){
        printf("%d ", currElem);
        currElem = array[++cIndex];
    }
   printf("%s\n", "");
   return 0;
}