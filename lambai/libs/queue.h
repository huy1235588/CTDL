#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "utils.h"

//
typedef struct Element {
    struct Data* data;
    struct Element* next;
} ELEMENT;

typedef struct Queue {
    struct Element* head;
    struct Element* tail;
} QUEUE;

//*************************************************************
// function prototype
//*************************************************************
ELEMENT* createElement(DATA* __data);
BOOLEAN isEmptyQueue(QUEUE* __queue);
ELEMENT* enqueue(QUEUE* __queue, ELEMENT* __element);
DATA* dequeue(QUEUE* __queue);
DATA* front(QUEUE* __queue);
void printQueue(QUEUE* __queue);
void freeQueue(QUEUE *__queue);

#endif