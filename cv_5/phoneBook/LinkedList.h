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

// (1) Insert at end 
LinkedList *insertNodeEnd(LinkedList *linkedList, Node *node){ 

    if (!linkedList -> head){ 
        linkedList -> head = node;
    }else{
        linkedList -> tail -> next = node;
    }

    linkedList -> tail = node; 
    return linkedList;
}

// (*) Insert in descending manner 
LinkedList *insertNodeDescending(LinkedList *linkedList, Node *node){
    if (!linkedList -> head){
        linkedList -> head = linkedList -> tail = node;
        return linkedList;
    }

    Node *cNode = linkedList -> head;
    while (cNode -> val)
}

// (2) Remove the first occurences of node with val
LinkedList *removeNode(LinkedList *linkedList, int val){
    if (!linkedList -> head) return linkedList; // Empty

    if (linkedList -> head -> val == val){ // Remove head
        Node *temp = linkedList -> head;
        linkedList -> head = linkedList -> head -> next;

        if (temp == linkedList -> tail) 
            linkedList -> tail = NULL; // Length of 1

        free(temp);
        return linkedList;
    } 

    // Default case
    Node *currNode = linkedList -> head;
    while (currNode -> next){ 

        if (currNode -> next -> val != val){
            currNode = currNode -> next;
            continue;
        }

        Node *temp = currNode -> next;
        currNode -> next = currNode -> next -> next;
        
        // Tail was removed
        if (temp == linkedList -> tail)
            linkedList -> tail = currNode;

        free(temp);

        break;
    }

    return linkedList;
}

void printLinkedList(LinkedList *linkedList){
    Node *curr = (linkedList -> head);
    while (curr){
        printf("%d\n", curr -> val);
        curr = curr -> next;
    }
}