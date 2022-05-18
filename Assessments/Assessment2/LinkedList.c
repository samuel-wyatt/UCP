#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/* Constructor*/
LinkedList* createLinkedList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

/* Insert new element at the start*/
void insertStart(LinkedList *list, void *value) {
    ListNode *newNd = (ListNode*)malloc(sizeof(ListNode));
    newNd->value = value;
    newNd->next = NULL;
    newNd->prev = NULL;

    if (isEmpty(list) == 1) {
        list->head = newNd;
        list->tail = newNd;
    } else {
        newNd->prev = NULL;
        newNd->next = list->head;
        list->head->prev = newNd;
        list->head = newNd;
    }
    incrementCount(list);
}

/* Insert new element at the end*/
void insertLast(LinkedList *list, void *value) {
    ListNode *newNd = (ListNode*)malloc(sizeof(ListNode));
    newNd->value = value;
    newNd->next = NULL;
    newNd->prev = NULL;

    if (isEmpty(list) == 1) {
        list->head = newNd;
        list->tail = newNd;
    } else {
        newNd->prev = list->tail;
        newNd->next = NULL;
        list->tail->next = newNd;
        list->tail = newNd;
    }
    incrementCount(list);
}

/* Remove the element from the start*/
void* removeStart(LinkedList *list) {
    void *returnNode = NULL;
    if (list->head == NULL) {
        returnNode = NULL;
    } else {
        ListNode *frontNode = list->head;
        returnNode = frontNode->value;
        frontNode->next->prev = NULL;
        list->head = frontNode->next;
        frontNode->next = NULL;
        free(frontNode);
        decrementCount(list);
    } 
    return returnNode;
}

/* Remove the element from the end*/
 void* removeLast(LinkedList *list) {
    void *returnNode;
    if (list->head == NULL) {
        returnNode = NULL;
    } else {
        ListNode *endNode = list->tail;
        returnNode = endNode->value;
        endNode->prev->next = NULL;
        list->tail = endNode->prev;
        endNode->prev = NULL;
        free(endNode);
        decrementCount(list);
    } 
    return returnNode;
}

/* Check if the linked list is empty*/
int isEmpty(LinkedList *list) {
    int empty;
    if (list->count == 0) {
        empty = 1;
    } else {
        empty = 0;
    }
    return empty;
}

/* Increment the count*/
void incrementCount(LinkedList *list) {
    list->count += 1;
}

/* Decrement the count*/
void decrementCount(LinkedList *list) {
    list->count -= 1;
}

/* Return the size of the linked list*/
int size(LinkedList *list) {
    return list->count;
}

/* Print the linked list*/
void printLinkedList(LinkedList *list, listFunc funcPtr) {
    ListNode *currNd = list->head;
    while (currNd != NULL) {
        funcPtr(currNd->value);
        printf("\n");
        currNd = currNd->next;
    }
}

/* Free the memory of the linked list*/
void freeLinkedList(LinkedList *list, listFunc funcPtr) {
    ListNode *currNd = list->head;
    ListNode *nextNd;

    while (currNd != NULL)
    {
        nextNd = currNd->next;
        funcPtr(currNd->value);
        free(currNd);
        currNd = nextNd;
    }
    list->head = NULL;
    list->tail = NULL;
    free(list);
}
