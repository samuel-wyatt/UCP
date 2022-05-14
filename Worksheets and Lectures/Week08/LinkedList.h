#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct ListNode {
    void *value;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
    int counter;
} LinkedList;

LinkedList* createLinkedList();
void insertStart(LinkedList *list, void *value);
void insertLast(LinkedList *list, void *value);
void* removeStart(LinkedList *list);
void* removeLast(LinkedList *list);
int isEmpty(LinkedList *list);
void incrementCounter(LinkedList *list);
void decrementCounter(LinkedList *list);
int size(LinkedList *list);

typedef void (*listFunc)(void* data);

void printLinkedList(LinkedList *list, listFunc funcPtr);
void freeLinkedList(LinkedList *list, listFunc funcPtr);

#endif
