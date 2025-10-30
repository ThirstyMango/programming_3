#include <malloc.h>
typedef struct Node{
    int val;
    struct Node *next;
} Node;

typedef struct LinkedList{
    Node *head; 
    Node *tail;
} LinkedList;

LinkedList *createLinkedList(Node *head, Node *tail){
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList -> head = head;
    linkedList -> tail = tail;
    return linkedList; 
}

Node *createNode(int val, Node *next){
    Node *newNode = malloc(sizeof(Node));
    newNode -> val = val;
    newNode -> next = next;
    return newNode;
}

LinkedList *insertNodeEnd(LinkedList *linkedList, Node *node){ // inserts at the end and returns linkedList

    if (!linkedList -> head){ 
        linkedList -> head = node;
    }else{
        linkedList -> tail -> next = node;
    }

    linkedList -> tail = node; 
    return linkedList;
}

void printLinkedList(LinkedList *linkedList){
    Node *curr = (linkedList -> head);
    while (curr){
        printf("%d\n", curr -> val);
        curr = curr -> next;
    }
}