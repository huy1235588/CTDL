#include <stdio.h>
#include <stdlib.h>

typedef struct Data
{
    int key;
    int value;
} DATA;

typedef struct Node
{
    DATA data;
    Node *next;
} NODE;

typedef struct List
{
    NODE *head = NULL;
} LIST;

NODE *createNode(int key, int value)
{
    NODE *node;
    node = (NODE *)malloc(sizeof(NODE));
    if (node == NULL)
    {
        printf("Allocate failled");
        exit(1);
    }
    else
    {
        node->data.key = key;
        node->data.value = value;

        node->next = NULL;
        return node;
    }
}

int isEmpty(LIST list)
{
    return (list.head == NULL) ? 1 : 0;
}

int getLength(LIST list)
{
    NODE *current = list.head;
    int numNode = 0;
    while (current != NULL)
    {
        numNode++;
        current = current->next;
    }
    return numNode;
}

void addNode(LIST &list, NODE *node)
{
    if (isEmpty(list))
    {
        list.head = node;
        return;
    }
    node->next = list.head;
    list.head = node;
}

void addTail(LIST &list, NODE *node)
{
    if (isEmpty(list))
    {
        list.head = node;
        return;
    }
    NODE *current;
    current = list.head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = node;
}

void addAfter(LIST list, NODE *prev, NODE *node)
{
    if (isEmpty(list))
    {
        list.head = node;
        return;
    }
    if (prev == NULL)
    {
        addNode(list, node);
    }
    node->next = prev->next;
    prev->next = node;
}

void printList(LIST *list)
{
    NODE *current = list->head;
    while (current != NULL)
    {
        printf("Key = %d Value = %d\n", current->data.key, current->data.value);
        current = current->next;
    }
}

void removeHead(LIST &list)
{
    if (isEmpty(list))
    {
        return;
    }
    NODE *temp;
    temp = list.head;
    list.head = list.head->next;
    free(temp);
}

void removeTail(LIST &list)
{
    if (isEmpty(list))
    {
        return;
    }
    NODE *temp = list.head;
    if (temp->next == NULL)
    {
        list.head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void freeList(LIST &list)
{
    NODE *temp;

    while (list.head != NULL)
    {
        temp = list.head;
        list.head = list.head->next;
        free(temp);
    }
}

// NODE *searchNode(LIST list, NODE *node)
// {
//     NODE *current = list.head;
//     while (current != NULL)
//     {
//         if (current->data.key)
//         {
//             /* code */
//         }

//         current = current->next;
//     }
// }

int main(int argc, char *argv[])
{
    LIST list;
    NODE *node1 = createNode(353, 4);
    NODE *node2 = createNode(73, 94);
    NODE *node3 = createNode(3325, 44);
    NODE *node4 = createNode(63, 4423);
    NODE *node5 = createNode(5, 4423);
    NODE *node6 = createNode(6, 4423);
    addNode(list, node1);
    addNode(list, node2);
    addTail(list, node3);
    addTail(list, node4);
    addAfter(list, node2, node5);
    addAfter(list, node4, node6);

    // printf("Length of listL %d\n", getLength(list));
    // NODE *node = searchNode(list, node5);
    // if (searchNode(list, node1) == NULL)
    // {
    //     printf("Not Found");
    // }
    // else
    // {
    //     printf("NODE %d\n", node->data.key, node->data.value);
    // }

    printList(&list);
    removeTail(list);
    printList(&list);
    freeList(list);
    return 0;
}