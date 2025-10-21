#include <stdio.h>
#include <string.h>
#include "module.h"

int hasSmallerNumber(int arr[], int num){
    return 0; // --> return the index of smaller number
}

int quickSortFromIndex(int arr[], int index){ // sort including the index
    return 0; 
}


int main(){
    int n = getNextNumber();
    int nextPermutation[n];
    int hasSmallerFurthestIndex = -1;
    int smallerIndex;

    for (int i = 0; i < n; i++){
        int cNum = getNextNumber();

        smallerIndex = hasSmallerNumber(nextPermutation, cNum);
        if (smallerIndex != -1){
            hasSmallerFurthestIndex = i;
        };

        nextPermutation[i] = cNum;
    }

    quickSortFrom(nextPermutation, smallerIndex + 1); 
}