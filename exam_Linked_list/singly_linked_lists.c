#include "singly_linked_lists.h"

void demonstrate_singly_linked_lists(SLLIST *list)
{

    list->head = NULL;
    SLLNODE *node1 = createNodeFromDataDetails(1, 10, 9.8, "Le Thien Huy");
    SLLNODE *node2 = createNodeFromDataDetails(2, 8, 4, "ha");
    SLLNODE *node3 = createNodeFromDataDetails(3, 3.5, 5, "he");
    SLLNODE *node4 = createNodeFromDataDetails(4, 3.4, 5.4, "hu");
    SLLNODE *node5 = createNodeFromDataDetails(5, 2.1, 7.4, "hi");
    SLLNODE *node6 = createNodeFromDataDetails(6, 2.9, 7.4, "hehe");
    SLLNODE *node7 = createNodeFromDataDetails(7, 4.7, 8.4, "haha");
    SLLNODE *node8 = createNodeFromDataDetails(8, 9.1, 8.5, "hihi");

    insertAtHead(list, node1);        // 1
    insertAtHead(list, node2);        // 2 1
    insertAtHead(list, node3);        // 3 2 1
    insertAtTail(list, node4);        // 3 2 1 4
    insertAtTail(list, node5);        // 3 2 1 4 5
    insertAtTail(list, node6);        // 3 2 1 4 5 6
    insertAfter(list, node7, node4);  // 3 2 1 4 7 5 6
    insertAtPosition(list, node8, 2); // 3 2 8 1 4 7 5 6

    // printSinglyLinkedList(list);

    // printf("\nLength = %d", getLength(list));
    // printf("\nNode 7th = %p", getNode(list, 7));

    // sortInAscending(list);
    // printSinglyLinkedList(list);

    // deleteHead(list);          // 2 3 4 5 6 7 8
    // deleteTail(list);          // 2 3 4 5 6 7
    // deleteAtPosition(list, 2); // 2 3 5 6 7
    // puts("");
    // printSinglyLinkedList(list);
    // // deleteAfter(list, node5);  // 2 3 5 7
    // puts("");
    // printSinglyLinkedList(list);

    // releaseWholeList(list);
}

SLLNODE *createNodeFromWholeData(STUDENT __data)
{
    SLLNODE *node = (SLLNODE *)malloc(sizeof(SLLNODE));
    if (node != NULL)
    {
        // data
        node->student = __data;
        // next
        node->next = NULL;
        return node;
    }
    return NULL;
}

SLLNODE *createNodeFromDataDetails(int __id, float __mathScore, float __literatureScore, char *__name)
{
    SLLNODE *node = (SLLNODE *)malloc(sizeof(SLLNODE));
    if (node != NULL)
    {
        // data
        node->student.id = __id;
        node->student.mathScore = __mathScore;
        node->student.literatureScore = __literatureScore;
        node->student.averageScore = (__mathScore + __literatureScore) / 2;
        strcpy(node->student.name, __name);
        // next
        node->next = NULL;
        return node;
    }
    return NULL;
}

int getLength(SLLIST *__list)
{
    int length = 0;
    if (__list != NULL)
    {
        SLLNODE *current = __list->head;
        while (current != NULL)
        {
            length++;
            current = current->next;
        }
    }
    return length;
}

SLLNODE *getNode(SLLIST *__list, int __position)
{
    if (__list != NULL && __list->head != NULL && __position >= 0)
    {
        SLLNODE *current = __list->head;
        int index = 0;
        while (current != NULL)
        {
            if (index == __position)
            {
                return current;
            }
            index++;
            current = current->next;
        }
    }
    return NULL;
}

SLLNODE *getHead(SLLIST *__list)
{
    return (__list == NULL) ? (SLLNODE *)NULL : __list->head;
}

SLLNODE *getTail(SLLIST *__list)
{
    SLLNODE *current = NULL;
    if (__list != NULL && __list->head != NULL)
    {
        current = __list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
    }
    return current;
}

static SLLNODE *getPrevNodeByPosition(SLLIST *__list, int __position)
{
    if (__list != NULL && __list->head != NULL && __position > 0)
    {
        SLLNODE *prev = __list->head;
        SLLNODE *current = prev->next;
        int index = 1;
        while (current != NULL)
        {
            if (index == __position)
            {
                return prev;
            }
            index++;
            prev = prev->next;
            current = current->next;
        }
    }
    return NULL;
}

int searchByData(SLLIST *__list, int __id)
{
    if (__list != NULL && __list->head != NULL)
    {
        SLLNODE *current = __list->head;
        int index = 0;
        while (current != NULL)
        {
            if (current->student.id == __id)
            {
                return index;
            }
            index++;
            current = current->next;
        }
    }
    return -1; // Not Found
}

int searchByNode(SLLIST *__list, SLLNODE *__node)
{
    if (__list != NULL && __list->head != NULL && __node != NULL)
    {
        SLLNODE *current = __list->head;
        int index = 0;
        while (current != NULL)
        {
            if (current == __node)
            {
                return index;
            }
            index++;
            current = current->next;
        }
    }
    return -1; // Not Found
}

static void __printNode(SLLNODE *__node)
{
    if (__node != NULL)
    {
        printf("(%d :: %f :: %f :: %f :: \'%s\' )",
               __node->student.id,
               __node->student.mathScore,
               __node->student.literatureScore,
               __node->student.averageScore,
               __node->student.name);
    }
}
void printSinglyLinkedList(SLLIST *__list)
{
    if (__list != NULL)
    {
        SLLNODE *current = __list->head;
        while (current != NULL)
        {
            printf("\n");
            __printNode(current);
            current = current->next;
        }
    }
}

SLLNODE *insertAtHead(SLLIST *__list, SLLNODE *__node)
{
    if (__list != NULL && __node != NULL)
    {
        if (__list->head == NULL)
        {
            __list->head = __node;
        }
        else
        {
            __node->next = __list->head;
            __list->head = __node;
        }
        return __node;
    }
    return NULL;
}

SLLNODE *insertAtTail(SLLIST *__list, SLLNODE *__node)
{
    if (__list != NULL && __node != NULL)
    {
        if (__list->head == NULL)
        {
            __list->head = __node;
        }
        else
        {
            SLLNODE *current = __list->head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = __node;
        }
        return __node;
    }
    return NULL;
}

SLLNODE *insertAfter(SLLIST *__list, SLLNODE *__node, SLLNODE *__prev)
{
    if (__list != NULL && __list->head != NULL && __prev != NULL && __node != NULL)
    {
        SLLNODE *current = __list->head;
        while (current != NULL)
        {
            if (current == __prev)
            {
                __node->next = current->next;
                current->next = __node;
                return __node;
            }
            current = current->next;
        }
    }
    return NULL;
}

SLLNODE *insertAtPosition(SLLIST *__list, SLLNODE *__node, int __position)
{
    if (__list != NULL && __list->head != NULL && __position >= 0 && __node != NULL)
    {
        if (__position == 0)
        {
            return insertAtHead(__list, __node);
        }
        SLLNODE *prev = getPrevNodeByPosition(__list, __position);
        if (prev != NULL)
        {
            __node->next = prev->next;
            prev->next = __node;
            return __node;
        }
    }
    return NULL;
}

void releaseWholeList(SLLIST *__list)
{
    if (__list != NULL)
    {
        SLLNODE *temp;
        while (__list->head != NULL)
        {
            temp = __list->head;
            __list->head = __list->head->next;
            free(temp);
        }
    }
}

void deleteHead(SLLIST *__list)
{
    if (__list != NULL && __list->head != NULL)
    {
        SLLNODE *temp = __list->head;
        __list->head = __list->head->next;
        free(temp);
    }
}
void deleteTail(SLLIST *__list)
{
    if (__list != NULL && __list->head != NULL)
    {
        if (__list->head->next == NULL)
        {
            deleteHead(__list);
        }
        else
        {
            SLLNODE *prev = __list->head;
            SLLNODE *current = prev->next;
            while (current->next != NULL)
            {
                prev = prev->next;
                current = current->next;
            }
            SLLNODE *temp = current;
            prev->next = NULL;
            free(temp);
        }
    }
}
void deleteAtPosition(SLLIST *__list, int __position)
{
    if (__list != NULL && __list->head != NULL && __position >= 0)
    {
        if (__position == 0)
        {
            deleteHead(__list);
        }
        else
        {
            SLLNODE *prev = getPrevNodeByPosition(__list, __position);
            if (prev->next->next != NULL)
            {
                SLLNODE *temp = prev->next;
                prev->next = prev->next->next;
                free(temp);
            }
            else
            {
                deleteTail(__list);
            }
        }
    }
}

static void __selectionSort(SLLIST *__list)
{
    if (__list != NULL && __list->head != NULL && __list->head->next != NULL)
    {
        SLLNODE *minimum;
        SLLNODE *external;
        SLLNODE *internal;
        external = __list->head;
        while (external->next != NULL)
        {
            minimum = external;
            internal = external->next;
            while (internal != NULL)
            {
                if (compareDataByKey(minimum->student, internal->student) > 0)
                { // nghịch thế
                    minimum = internal;
                }
                internal = internal->next;
            }
            if (minimum != external)
            {
                swapData(&(minimum->student), &(external->student));
            }
            external = external->next;
        }
    }
}

static SLLNODE *__partition(SLLNODE *__first, SLLNODE *__last)
{
    SLLNODE *pivot = __first;
    SLLNODE *front = __first;
    while (front != NULL && front != __last)
    {
        if (compareDataByAvg(__last->student, front->student) > 0)
        { // nghịch thế
            pivot = __first;
            swapData(&(__first->student), &(front->student));
            __first = __first->next;
        }
        front = front->next;
    }
    swapData(&(__first->student), &(__last->student));
    return pivot;
}

static void __quick_sort(SLLNODE *__first, SLLNODE *__last)
{
    if (__first != __last)
    {
        SLLNODE *__pivot = __partition(__first, __last);
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

static void __quickSort(SLLIST *__list)
{
    if (__list != NULL && __list->head != NULL && __list->head->next != NULL)
    {
        __quick_sort(__list->head, getTail(__list));
    }
}

void sortInAscending(SLLIST *__list)
{
    // __selectionSort(__list);
    __quickSort(__list);
}

void cau4(SLLIST *__list)
{
    SLLNODE *__node = (SLLNODE *)malloc(sizeof(SLLNODE));
    int index = 0;
    if (__list != NULL && __list->head != NULL)
    {
        SLLNODE *current = __list->head;
        __node->student = current->student;
        while (current->next != NULL)
        {
            if (__node->student.averageScore < current->student.averageScore)
            {
                __node->student = current->student;
            }
            current = current->next;
        }
    }
    __printNode(__node);
    free(__node);
}

void cau6(SLLIST *__list)
{
    SLLIST *__list11 = (SLLIST *)malloc(sizeof(SLLIST));

    __list11->head = NULL; // Initialize the head of the new list

    if (__list != NULL && __list->head != NULL)
    {
        SLLNODE *current = __list->head;
        while (current != NULL)
        {
            if (current->student.averageScore >= 7.0)
            {
                SLLNODE *temp = (SLLNODE *)malloc(sizeof(SLLNODE));
                temp->student = current->student;
                temp->next = NULL;
                insertAtHead(__list11, temp);
            }
            current = current->next;
        }
    }
    printSinglyLinkedList(__list11);
    releaseWholeList(__list11);
    free(__list11);
}