#include "queue.h"

ELEMENT *createElement(DATA *__data)
{
    ELEMENT *__element;
    __element = (ELEMENT *)malloc(sizeof(ELEMENT));
    if (__element != NULL)
    {
        __element->data = __data;
        __element->next = NULL;
    }
    return __element;
}

BOOLEAN isEmptyQueue(QUEUE *__queue)
{
    return (__queue->head == NULL) ? (BOOLEAN)TRUE : (BOOLEAN)FALSE;
}

ELEMENT *enqueue(QUEUE *__queue, ELEMENT *__element)
{
    if (__queue != NULL && __element != NULL)
    {
        if (__queue->head == NULL)
        {
            __queue->head = __queue->tail = __element;
        }
        else
        {
            __element->next = __queue->head;
            __queue->head = __element;
        }
        return __element;
    }
    return NULL;
}

DATA *dequeue(QUEUE *__queue)
{
    DATA *__data = NULL;
    if (__queue != NULL && __queue->head != NULL)
    {
        if (__queue->head == __queue->tail)
        {
            __data = __queue->head->data;
            free(__queue->head);
            __queue->head = __queue->tail = NULL;
        }
        else
        {
            ELEMENT *__current = __queue->head;
            while (__current->next != __queue->tail)
            {
                __current = __current->next;
            }
            __data = __queue->tail->data;
            free(__queue->tail);
            __queue->tail = __current;
            __queue->tail->next = NULL;
        }
    }
    return __data;
}

DATA *front(QUEUE *__queue)
{
    DATA *__data = NULL;
    if (__queue != NULL || __queue->head != NULL)
    {
        __data = __queue->tail->data;
    }
    return __data;
}

void freeQueue(QUEUE *__queue)
{
    if (__queue != NULL)
    {
        ELEMENT *__temp;
        while (__queue->head != NULL)
        {
            __temp = __queue->head;
            __queue->head = __queue->head->next;
            free(__temp->data);
            free(__temp);
        }
    }
}

static void __printElement(ELEMENT *__element)
{
    if (__element != NULL)
    {
        printf("( %p :: %d :: %d )", // ( item's address :: key :: value )
               __element,
               __element->data->key,
               __element->data->value);
    }
}

void printQueue(QUEUE *__queue)
{
    if (__queue != NULL)
    {
        ELEMENT *__current = __queue->head;
        while (__current != NULL)
        {
            printf("\n");
            __printElement(__current);
            __current = __current->next;
        }
    }
}