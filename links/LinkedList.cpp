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

int isEmpty(NODE *node)
{
    return (&node == NULL) ? 1 : 0;
}

void addNode(NODE *node)
{
    LIST *list;
    if (isEmpty(list->head))
    {
        list->head = node;
        return;
    }
    node->next = list->head;
    list->head = node;
}

void printList(LIST *list)
{
    NODE *current = list->head;
    while (current != NULL)
    {
        printf("%d::%d\n", current->data.key, current->data.value);
        current = current->next;
    }

}

int main(int argc, char *argv[])
{
    LIST list;
    NODE *node, *node2, *node3, *node4;
    node = createNode(353, 4);
    node2 = createNode(73, 94);
    node3 = createNode(3325, 44);
    node4 = createNode(63, 4423);
    addNode(node);
    addNode(node2);
    addNode(node3);
    addNode(node4);
    printList(&list);
    if (isEmpty(node))
    {
        printf("Link is emty ");
    }
    else
    {
        printf("haha\n");
    }

    printf("%d::%d", node->data.key, node->data.value);
    free(node);
    return 0;
}