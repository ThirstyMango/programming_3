#include <stdio.h>
#include "inputModule.h"
#include "LinkedList.h"

int main(){
    
    LinkedList *linkedList = createLinkedList(NULL, NULL); // Create an empty instance of linkedList

    int endOfInput = 0;
    int cVal = getNextNumber(&endOfInput);
    while (!endOfInput){
        printf("%d\n", cVal);
        insertNodeEnd(linkedList, createNode(cVal, NULL));
        cVal = getNextNumber(&endOfInput);
    }

    printLinkedList(linkedList);
    return 0;
}