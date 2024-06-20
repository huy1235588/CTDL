#ifndef __STACK_H__
#define __STACK_H__

#include "utils.h"

//
typedef struct Item {
    struct Data* data;
    struct Item* next;

} ITEM;

typedef struct Stack {
    struct Item* head;
} STACK;

//*************************************************************
// function prototype
//*************************************************************
ITEM* createItem(DATA* __data);
BOOLEAN isEmptyStack(STACK* __stack);
ITEM* push(STACK* __stack, ITEM* __item);
DATA* pop(STACK* __stack);
DATA* top(STACK* __stack);
void printStack(STACK* __stack);

#endif