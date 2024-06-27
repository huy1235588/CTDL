#include "queues.h"

void demonstrate_queues()
{
    QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
    if (queue != NULL)
    {
        queue->head = NULL;
        ELEMENT *element1 = createElementFromDataDetails(1, 10, "A");
        ELEMENT *element2 = createElementFromDataDetails(2, 20, "B");
        ELEMENT *element3 = createElementFromDataDetails(3, 30, "C");
        ELEMENT *element4 = createElementFromDataDetails(4, 40, "D");
        ELEMENT *element5 = createElementFromDataDetails(5, 50, "E");
        ELEMENT *element6 = createElementFromDataDetails(6, 60, "F");
        ELEMENT *element7 = createElementFromDataDetails(7, 70, "G");
        ELEMENT *element8 = createElementFromDataDetails(8, 80, "H");

        enqueue(queue, element1); // 1
        enqueue(queue, element2); // 2 1
        enqueue(queue, element3); // 3 2 1
        enqueue(queue, element4); // 4 3 2 1
        enqueue(queue, element5); // 5 4 3 2 1
        enqueue(queue, element6); // 6 5 4 3 2 1
        enqueue(queue, element7); // 7 6 5 4 3 2 1
        enqueue(queue, element8); // 8 7 6 5 4 3 2 1
        printQueue(queue);

        printf("\nLength = %d", getLengtQueue(queue));
        printf("\nItem 8th = %p", front(queue));

        sortQueueInAscending(queue);
        printQueue(queue);

        dequeue(queue); // 1 2 3 4 5 6 7
        dequeue(queue); // 1 2 3 4 5 6
        dequeue(queue); // 1 2 3 4 5

        puts("");
        printQueue(queue);
        dequeue(queue); // 1 2 3 4
        puts("");
        printQueue(queue);

        releaseWholeQueue(queue);
    }
    else
    {
        puts("Cannot allocate.");
    }
}

ELEMENT *createElementFromWholeData(DATA __data)
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

ELEMENT *createElementFromDataDetails(int __key, int __number, char *__text)
{
    ELEMENT *__element = (ELEMENT *)malloc(sizeof(ELEMENT));
    if (__element != NULL)
    {
        // data
        __element->data.key = __key;
        __element->data.number = __number;
        strcpy(__element->data.text, __text);
        // next
        __element->next = NULL;
        return __element;
    }
    return NULL;
}

int getLengtQueue(QUEUE *__queue)
{
    int length = 0;
    if (__queue != NULL)
    {
        ELEMENT *current = __queue->head;
        while (current != NULL)
        {
            length++;
            current = current->next;
        }
    }
    return length;
}

BOOLEAN isEmptyQueue(QUEUE *__queue)
{
    return (__queue->head == NULL) ? (BOOLEAN)TRUE : (BOOLEAN)FALSE;
}

//*************************************************************
// Insert
//*************************************************************
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

//*************************************************************
// Get a node
//*************************************************************
ELEMENT *dequeue(QUEUE *__queue)
{
    if (__queue != NULL && __queue->head != NULL)
    {
        ELEMENT *__element = __queue->head;
        if (__queue->head == __queue->tail)
        {
            __queue->head = __queue->tail = NULL;
            free(__queue->head);
            return __element;
        }
        else
        {
            ELEMENT *__current = __queue->head;
            while (__current->next != __queue->tail)
            {
                __current = __current->next;
            }
            __element = __queue->tail;
            free(__queue->tail);
            __queue->tail = __current;
            __queue->tail->next = NULL;
            return __element;
        }
    }
    return NULL;
}

//*************************************************************
// Get a node at the position (0 --> size-1) in list
//*************************************************************
ELEMENT *front(QUEUE *__queue)
{
    if (__queue != NULL && __queue->head != NULL)
    {
        return __queue->head;
    }
    return NULL;
}

ELEMENT *rear(QUEUE *__queue)
{
    if (__queue != NULL && __queue->head != NULL)
    {
        ELEMENT *current = __queue->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        return current;
    }
    return NULL;
}

//*************************************************************
// Print all data of the whole list
//*************************************************************
static void __printElement(ELEMENT *__element)
{
    if (__element != NULL)
    {
        printf("( %p :: %d :: %d )", // ( item's address :: key :: value )
               __element,
               __element->data.key,
               __element->data.number,
               __element->data.text);
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


//*************************************************************
// SORT
//*************************************************************
static void __selectionSort(QUEUE *__queue)
{
    if (__queue != NULL && __queue->head != NULL && __queue->head->next != NULL)
    {
        ELEMENT *minimum;
        ELEMENT *external;
        ELEMENT *internal;
        external = __queue->head;
        while (external->next != NULL)
        {
            minimum = external;
            internal = external->next;
            while (internal != NULL)
            {
                if (compareDataByKey(minimum->data, internal->data) > 0)
                { // nghịch thế
                    minimum = internal;
                }
                internal = internal->next;
            }
            if (minimum != external)
            {
                swapData(&(minimum->data), &(external->data));
            }
            external = external->next;
        }
    }
}

static ELEMENT *__partition(ELEMENT *__first, ELEMENT *__last)
{
    ELEMENT *pivot = __first;
    ELEMENT *front = __first;
    while (front != NULL && front != __last)
    {
        if (compareDataByKey(__last->data, front->data) > 0)
        { // nghịch thế
            pivot = __first;
            swapData(&(__first->data), &(front->data));
            __first = __first->next;
        }
        front = front->next;
    }
    swapData(&(__first->data), &(__last->data));
    return pivot;
}

static void __quick_sort(ELEMENT *__first, ELEMENT *__last)
{
    if (__first != __last)
    {
        ELEMENT *__pivot = __partition(__first, __last);
        if (__pivot != NULL && __pivot->next != NULL)
        {
            __quick_sort(__pivot->next, __last);
        }
        if (__pivot != NULL && __first != __pivot)
        {
            __quick_sort(__first, __pivot);
        }
    }
}

static void __quickSort(QUEUE *__queue)
{
    if (__queue != NULL && __queue->head != NULL && __queue->head->next != NULL)
    {
        __quick_sort(__queue->head, rear(__queue));
    }
}

void sortQueueInAscending(QUEUE *__queue)
{
    // __selectionSort(__queue);
    __quickSort(__queue);
}

//*************************************************************
// Release
//************************************************************
void releaseWholeQueue(QUEUE *__queue)
{
    if (__queue != NULL)
    {
        ELEMENT *temp;
        while (__queue->head != NULL)
        {
            temp = __queue->head;
            __queue->head = __queue->head->next;
            free(temp);
        }
    }
}