#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/* Constructor*/
LinkedList* createLinkedList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->counter = 0;
    return list;
}

void insertStart(LinkedList *list, void *value) {
    ListNode *newNd = (ListNode*)malloc(sizeof(ListNode));
    newNd->value = value;

    if (isEmpty(list) == 1) {
        list->head = newNd;
        list->tail = newNd;
    } else {
        newNd->prev = NULL;
        newNd->next = list->head;
        list->head->prev = newNd;
        list->head = newNd;
    }
    incrementCounter(list);
}

void insertLast(LinkedList *list, void *value) {
    ListNode *newNd = (ListNode*)malloc(sizeof(ListNode));
    newNd->value = value;

    if (isEmpty(list) == 1) {
        list->head = newNd;
        list->tail = newNd;
    } else {
        newNd->prev = list->tail;
        newNd->next = NULL;
        list->tail->next = newNd;
        list->tail = newNd;
    }
    incrementCounter(list);
}

void* removeStart(LinkedList *list) {
    void *returnNode;
    if (isEmpty(list) == 1) {
        returnNode = NULL;
    } else {
        ListNode *headNode = (ListNode*)malloc(sizeof(ListNode));
        headNode = list->head->next;
        returnNode = list->head;
        list->head->next = NULL;
        list->head = headNode;
        list->head->prev = NULL;
        decrementCounter(list);
    } 
    return returnNode;
}

 void* removeLast(LinkedList *list) {
    void *returnNode;
    if (isEmpty(list) == 1) {
        returnNode = NULL;
    } else {
        ListNode *tailNode = (ListNode*)malloc(sizeof(ListNode));
        tailNode = list->tail->prev;
        returnNode = list->tail;
        list->tail->prev = NULL;
        list->tail = tailNode;
        list->tail->next = NULL;
        decrementCounter(list);
    } 
    return returnNode;
}


int isEmpty(LinkedList *list) {
    int empty;
    if (list->counter == 0) {
        empty = 1;
    } else {
        empty = 0;
    }
    return empty;
}

void incrementCounter(LinkedList *list) {
    list->counter += 1;
}

void decrementCounter(LinkedList *list) {
    list->counter -= 1;
}

int size(LinkedList *list) {
    return list->counter;
}

void printLinkedList(LinkedList *list, listFunc funcPtr) {
    ListNode *currNd = list->head;
    while (currNd != NULL) {
        char *val = currNd->value;
        printf("[%s] ", val);
    }
}

void freeLinkedList(LinkedList *list, listFunc funcPtr) {
    ListNode *tmp;

   while (list->head != NULL)
    {
       tmp = list->head;
       list->head = list->head->next;
       free(tmp);
       tmp->next = NULL;
       tmp->prev = NULL;
       tmp->value = NULL;
    }
}
