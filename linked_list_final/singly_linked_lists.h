#ifndef __SINGLY_LINKED_LISTS_H__
#define __SINGLY_LINKED_LISTS_H__

#include "utils.h"

typedef struct NodeOfSinglyLinkedList {
    struct Data data;
    struct NodeOfSinglyLinkedList* next;
} SLLNODE;

typedef struct SinglyLinkedList {
    struct NodeOfSinglyLinkedList* head;
} SLLIST;

//*************************************************************
// function prototype
//*************************************************************
void demonstrate_singly_linked_lists(); // demo function
SLLNODE* createNodeFromWholeData(DATA __data);
SLLNODE* createNodeFromDataDetails(int __key, int __number, char* __text);

SLLNODE* getNode(SLLIST* __list, int __position);
SLLNODE* getHead(SLLIST* __list);
SLLNODE* getTail(SLLIST* __list);
int getLength(SLLIST* __list);
void printSinglyLinkedList(SLLIST* __list);
int searchByNode(SLLIST* __list, SLLNODE* __node);
int searchByData(SLLIST* __list, int __key);

SLLNODE* insertAtHead(SLLIST* __list, SLLNODE* __node);
SLLNODE* insertAtTail(SLLIST* __list, SLLNODE* __node);
SLLNODE* insertAfter(SLLIST* __list, SLLNODE* __node, SLLNODE* __prev);
SLLNODE* insertAtPosition(SLLIST* __list, SLLNODE* __node, int __position);

void releaseWholeList(SLLIST* __list);
void deleteHead(SLLIST* __list);
void deleteTail(SLLIST* __list);
void deleteAtPosition(SLLIST* __list, int __position);

void sortInAscending(SLLIST* __list);

#endif