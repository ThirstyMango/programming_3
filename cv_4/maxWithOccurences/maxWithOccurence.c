#include <stdio.h>
#include <string.h>
#include "module.h"

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

int main(){
    int n = getNextNumber();

    int maximum = 0;
    int occurences[n + 1];
    int cNumOccurences = 0;

    for (int i = 1; i <= n; i++){
        int cNum = getNextNumber();

        if (cNum == maximum){
            occurences[cNumOccurences] = i;
            cNumOccurences++;
        }else if (cNum > maximum){
            maximum = cNum;
            memset(occurences, -1, sizeof occurences); // set the array to array of 0
            occurences[0] = i;
            cNumOccurences = 1;
        }
    }

    printf("%d\n", maximum);
    printArray(occurences);
    return 0;
}