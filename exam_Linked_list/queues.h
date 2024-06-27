#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "utils.h"

//
typedef struct Element
{
    struct Data data;
    struct Element *next;
} ELEMENT;

typedef struct Queue
{
    struct Element *head;
    struct Element *tail;
} QUEUE;

//*************************************************************
// function prototype
//*************************************************************
void demonstrate_queues();

ELEMENT *createElementFromWholeData(DATA __data);
ELEMENT *createElementFromDataDetails(int __key, int __number, char *__text);

int getLengtQueue(QUEUE *__queue);
BOOLEAN isEmptyQueue(QUEUE *__queue);

ELEMENT *enqueue(QUEUE *__queue, ELEMENT *__element);
ELEMENT *dequeue(QUEUE *__queue);
ELEMENT *front(QUEUE *__queue);
ELEMENT *rear(QUEUE *__queue);

void printQueue(QUEUE *__queue);

void sortQueueInAscending(QUEUE *__queue);

void releaseWholeQueue(QUEUE *__queue);

#endif