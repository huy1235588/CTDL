#include "stacks.h"

void demonstrate_stacks()
{
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    if (stack != NULL)
    {
        stack->head = NULL;
        ITEM *item1 = createItemFromDataDetails(1, 10, "A");
        ITEM *item2 = createItemFromDataDetails(2, 20, "B");
        ITEM *item3 = createItemFromDataDetails(3, 30, "C");
        ITEM *item4 = createItemFromDataDetails(4, 40, "D");
        ITEM *item5 = createItemFromDataDetails(5, 50, "E");
        ITEM *item6 = createItemFromDataDetails(6, 60, "F");
        ITEM *item7 = createItemFromDataDetails(7, 70, "G");
        ITEM *item8 = createItemFromDataDetails(8, 80, "H");

        push(stack, item1); // 1
        push(stack, item2); // 2 1
        push(stack, item3); // 3 2 1
        push(stack, item4); // 4 3 2 1
        push(stack, item5); // 5 4 3 2 1
        push(stack, item6); // 6 5 4 3 2 1
        push(stack, item7); // 7 6 5 4 3 2 1
        push(stack, item8); // 8 7 6 5 4 3 2 1
        printStack(stack);

        printf("\nLength = %d", getLengthStack(stack));
        printf("\nItem 8th = %p", top(stack));

        sortStackInAscending(stack);
        printStack(stack);

        pop(stack); // 2 3 4 5 6 7 8
        pop(stack); // 3 4 5 6 7 8
        pop(stack); // 4 5 6 7 8

        puts("");
        printStack(stack);
        pop(stack); // 5 6 7 8
        puts("");
        printStack(stack);

        releaseWholeStack(stack);
    }
    else
    {
        puts("Cannot allocate.");
    }
}

ITEM *createItemFromWholeData(DATA __data)
{
    ITEM *__item;
    __item = (ITEM *)malloc(sizeof(ITEM));
    if (__item != NULL)
    {
        __item->data = __data;
        __item->next = NULL;
    }
    return __item;
}

ITEM *createItemFromDataDetails(int __key, int __number, char *__text)
{
    ITEM *__item = (ITEM *)malloc(sizeof(ITEM));
    if (__item != NULL)
    {
        // data
        __item->data.key = __key;
        __item->data.number = __number;
        strcpy(__item->data.text, __text);
        // next
        __item->next = NULL;
        return __item;
    }
    return NULL;
}

//*************************************************************
// Get the size (number of elements) of the list
//*************************************************************
int getLengthStack(STACK *__stack)
{
    int length = 0;
    if (__stack != NULL)
    {
        ITEM *current = __stack->head;
        while (current != NULL)
        {
            length++;
            current = current->next;
        }
    }
    return length;
}

BOOLEAN isEmptyStack(STACK *__stack)
{
    return (__stack->head == NULL) ? (BOOLEAN)TRUE : (BOOLEAN)FALSE;
}

//*************************************************************
// Insert
//*************************************************************
ITEM *push(STACK *__stack, ITEM *__item)
{
    if (__stack != NULL && __item != NULL)
    {
        if (__stack->head == NULL)
        {
            __stack->head = __item;
        }
        else
        {
            __item->next = __stack->head;
            __stack->head = __item;
        }
        return __item;
    }
    return NULL;
}

//*************************************************************
// Remove
//*************************************************************
ITEM *pop(STACK *__stack)
{
    if (__stack != NULL && __stack->head != NULL)
    {
        ITEM *__temp = __stack->head;
        __stack->head = __stack->head->next;
        ITEM *__item = __temp;
        free(__temp);
        return __item;
    }
    return NULL;
}

//*************************************************************
// Get a node
//*************************************************************
ITEM *top(STACK *__stack)
{
    if (__stack != NULL && __stack->head != NULL)
    {
        return __stack->head;
    }
    return NULL;
}

ITEM *bottom(STACK *__stack)
{
    if (__stack != NULL && __stack->head != NULL)
    {
        ITEM *current = __stack->head;
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
static void __printItem(ITEM *__item)
{
    if (__item != NULL)
    {
        printf("( %p :: %d :: %d :: \'%s\' )", // ( item's address :: key :: value )
               __item,
               __item->data.key,
               __item->data.number,
               __item->data.text);
    }
}

void printStack(STACK *__stack)
{
    if (__stack != NULL)
    {
        ITEM *__current = __stack->head;
        while (__current != NULL)
        {
            printf("\n");
            __printItem(__current);
            __current = __current->next;
        }
    }
}

//*************************************************************
// SORT
//*************************************************************
static void __selectionSort(STACK *__stack)
{
    if (__stack != NULL && __stack->head != NULL && __stack->head->next != NULL)
    {
        ITEM *minimum;
        ITEM *external;
        ITEM *internal;
        external = __stack->head;
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

static ITEM *__partition(ITEM *__first, ITEM *__last)
{
    ITEM *pivot = __first;
    ITEM *front = __first;
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

static void __quick_sort(ITEM *__first, ITEM *__last)
{
    if (__first != __last)
    {
        ITEM *__pivot = __partition(__first, __last);
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

static void __quickSort(STACK *__stack)
{
    if (__stack != NULL && __stack->head != NULL && __stack->head->next != NULL)
    {
        __quick_sort(__stack->head, bottom(__stack));
    }
}

void sortStackInAscending(STACK *__stack)
{
    // __selectionSort(__stack);
    __quickSort(__stack);
}

//*************************************************************
// Release
//************************************************************
void releaseWholeStack(STACK *__stack)
{
    if (__stack != NULL)
    {
        ITEM *temp;
        while (__stack->head != NULL)
        {
            temp = __stack->head;
            __stack->head = __stack->head->next;
            free(temp);
        }
    }
}