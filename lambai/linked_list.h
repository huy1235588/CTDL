#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "utils.h"

typedef struct Node
{
    struct Data *data;
    struct Node *next;

} NODE;

typedef struct SinglyLinkedList
{
    struct Node *head;
} LIST;

//*************************************************************
// function prototype
//*************************************************************
NODE *createNode(DATA *__data);
DATA *generateData(int __key, int __value);
BOOLEAN isInitialized(LIST *__list);
BOOLEAN isEmptyList(LIST *__list);
int getSize(LIST *__list);
NODE *getNode(LIST *__list, int __position);
NODE *getHead(LIST *__list);
NODE *getTail(LIST *__list);
NODE *getMid(NODE *__head);
int getPositionByNode(LIST *__list, NODE *__node);
int getPositionByKey(LIST *__list, int __key);
void printList(LIST *__list);
NODE *addAtHead(LIST *__list, NODE *__node);
NODE *addAtTail(LIST *__list, NODE *__node);
NODE *addAtPosition(LIST *__list, int __position, NODE *__node);
NODE *addAfter(LIST *__list, NODE *__prev, NODE *__node);
void removeAtHead(LIST *__list);
void removeAtTail(LIST *__list);
void removeAfter(LIST *__list, NODE *__prev);
void removeAtPosition(LIST *__list, int __position);
void releaseWholeList(LIST *__list);
void sort(LIST *__list, ORDER __order);
void sortByQS(LIST *__list, ORDER __order);
void sortByMerge(LIST *__list, ORDER __order);
void sortByInsertion(LIST *__list, ORDER __order);
void sortByShell(LIST *__list, ORDER __order);
double measureSortTime(void (*sortFunction)(LIST *, ORDER), LIST *__list, ORDER __order);

#endif