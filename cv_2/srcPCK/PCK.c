#include "module.h"
#include <math.h>
#include <stdio.h>


int main() {
    int n = getNextNumber();
    double nSqrt = sqrt(n);
    int sumOfDivisors = 1; // 1 is always a divisor
    
    int isPerfect = 0;
    int isSquare = 0;
    int isCube = 0;

    int i;
    for (i = 2; i <= nSqrt; i++) {

        if (n % i != 0) continue;

        sumOfDivisors += i; // If i divisor => (n / i) is divisor
        if (i != nSqrt) sumOfDivisors += n/i; 

        int cSquare = i * i;
        if (cSquare == n) isSquare = 1; 

        int cCube = cSquare * i;
        if (cCube == n) isCube = 1;
    }

    if (sumOfDivisors == n) isPerfect = 1;


    if (isPerfect) printf("%s", "P");
    if (isSquare) printf("%s", "C");
    if (isCube) printf("%s", "K");
    printf("%s\n", "");

    return 0;
}