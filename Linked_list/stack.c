#include "stack.h"

ITEM* createItem(DATA* __data) {
    ITEM* __item;
    __item = (ITEM*) malloc (sizeof(ITEM));
    if (__item != NULL) {
        __item->data = __data;
        __item->next = NULL;
    }    
    return __item;   
}

BOOLEAN isEmptyStack(STACK* __stack) {
    return (__stack->head == NULL) ? (BOOLEAN) TRUE : (BOOLEAN) FALSE;
}

ITEM* push(STACK* __stack, ITEM* __item) {
    if (__stack != NULL && __item != NULL) {
        if (__stack->head == NULL) {
            __stack->head = __item;
        } else {
            __item->next = __stack->head;
            __stack->head = __item;
        }
        return __item;
    }
    return NULL;
}

DATA* pop(STACK* __stack) {
    DATA* __data = NULL;
    if (__stack != NULL || __stack->head != NULL) {
        ITEM* __item = __stack->head;
        __stack->head = __stack->head->next;
        __data = __item->data;
        free(__item);
    }
    return __data;  
}

DATA* top(STACK* __stack) {
    DATA* __data = NULL;
    if (__stack != NULL || __stack->head != NULL) {
        __data = __stack->head->data;
    }
    return __data;  
}

//*************************************************************
// Print all data of the whole list
//*************************************************************
static void __printItem(ITEM* __item) {
    if (__item != NULL) {
        printf("( %p :: %d :: %d )",    // ( item's address :: key :: value ) 
            __item,
            __item->data->key,
            __item->data->value
        );
    }
}

void printStack(STACK* __stack) {
    if (__stack != NULL) {
        ITEM* __current = __stack->head;
        while (__current != NULL) {
            printf("\n");
            __printItem(__current);
            __current = __current->next;
        } 
    }     
}
