#ifndef __STACKS_H__
#define __STACKS_H__

#include "utils.h"

typedef struct Item
{
    struct Data data;
    struct Item *next;

} ITEM;

typedef struct Stack
{
    struct Item *head;
} STACK;

//*************************************************************
// function prototype
//*************************************************************
void demonstrate_stacks(); // demo function

ITEM *createItemFromWholeData(DATA __data);
ITEM *createItemFromDataDetails(int __key, int __number, char *__text);

int getLengthStack(STACK *__stack);
BOOLEAN isEmptyStack(STACK *__stack);

ITEM *push(STACK *__stack, ITEM *__item);
ITEM *pop(STACK *__stack);
ITEM *top(STACK *__stack);
ITEM *bottom(STACK *__stack);

void printStack(STACK *__stack);

void sortStackInAscending(STACK *__list);

void releaseWholeStack(STACK *__stack);

#endif