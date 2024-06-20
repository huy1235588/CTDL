#include "queue.h"

ELEMENT* createElement(DATA* __data) {
    ELEMENT* __element;
    __element = (ELEMENT*) malloc (sizeof(ELEMENT));
    if (__element != NULL) {
        __element->data = __data;
        __element->next = NULL;
    }    
    return __element;  
}

BOOLEAN isEmptyQueue(QUEUE* __queue) {
    return (__queue->head == NULL) ? (BOOLEAN) TRUE : (BOOLEAN) FALSE;
}

ELEMENT* enqueue(QUEUE* __queue, ELEMENT* __element) {
    if (__queue != NULL && __element != NULL) {
        if (__queue->head == NULL) {
            __queue->head = __element;
        } else {
            __element->next = __queue->head;
            __queue->head = __element;
        }
        return __element;
    }
    return NULL;
}

DATA* dequeue(QUEUE* __queue) {

}

DATA* front(QUEUE* __queue) {

}

static void __printElement(ELEMENT* __element) {
    if (__element != NULL) {
        printf("( %p :: %d :: %d )",    // ( item's address :: key :: value ) 
            __element,
            __element->data->key,
            __element->data->value
        );
    }
}

void printQueue(QUEUE* __queue) {
    if (__queue != NULL) {
        ELEMENT* __current = __queue->head;
        while (__current != NULL) {
            printf("\n");
            __printItem(__current);
            __current = __current->next;
        } 
    }   
}