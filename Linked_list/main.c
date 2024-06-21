//*************************************************************
// main.cpp
// Author: Smile
//*************************************************************

#include "utils.h"
#include "singly_linked_list.h"
#include "stack.h"

//*************************************************************
//*************************************************************
DATA *generateData(int __key, int __value)
{
    DATA *__data = (DATA *)malloc(sizeof(DATA));
    if (__data != NULL)
    {
        __data->key = __key;
        __data->value = __value;
    }
    return __data;
}

int main(int argc, char *argv[])
{
    // LIST *list = &((LIST){NULL});
    LIST list_null = (LIST){NULL};
    LIST *list = &list_null;

    NODE *n1 = createNode(generateData(1, 10));
    NODE *n2 = createNode(generateData(2, 20));
    NODE *n3 = createNode(generateData(3, 30));
    NODE *n4 = createNode(generateData(4, 40));
    NODE *n5 = createNode(generateData(5, 50));
    NODE *n6 = createNode(generateData(6, 60));
    NODE *n7 = createNode(generateData(7, 70));
    NODE *n8 = createNode(generateData(8, 80));

    NODE *n9 = createNode(generateData(9, 80));
    NODE *n10 = createNode(generateData(10, 20));
    // NODE *n11 = createNode(generateData(11, 35));
    // NODE *n12 = createNode(generateData(12, 40));
    // NODE *n13 = createNode(generateData(13, 88));
    // NODE *n14 = createNode(generateData(14, 80));

    // addAtHead(list, n1);    // 1
    // addAtHead(list, n2);    // 2, 1
    // addAtHead(list, n3);    // 3, 2, 1
    // addAtTail(list, n4);    // 3, 2, 1, 4
    // addAtTail(list, n5);    // 3, 2, 1, 4, 5
    // addAfter(list, n1, n6); // 3, 2, 1, 6, 4, 5
    // addAfter(list, n7, n8); // 3, 2, 1, 6, 4, 5

    // addAfter(list, n5, n9);  // 3, 2, 1, 9, 6, 4, 5
    // addAfter(list, n2, n10); // 3, 2, 10, 1, 9, 6, 4, 5
    // addAfter(list, n9, n11); // 3, 11, 2, 10, 1, 9, 6, 4, 5
    // addAfter(list, n4, n12); // 3, 11, 2, 10, 1, 9, 6, 4, 12, 5
    // addAfter(list, n6, n13); // 3, 11, 2, 10, 1, 9, 6, 4, 12, 5, 13

    addAtHead(list, n1);  // 1
    addAtHead(list, n2);  // 2, 1
    addAtHead(list, n3);  // 3, 2, 1
    addAtHead(list, n4);  // 3, 2, 1, 4
    addAtHead(list, n5);  // 3, 2, 1, 4, 5
    addAtHead(list, n6);  // 3, 2, 1, 6, 4, 5
    addAtHead(list, n8);  // 3, 2, 1, 6, 4, 5
    addAtHead(list, n9);  // 3, 2, 1, 6, 4, 5
    addAtHead(list, n10); // 3, 2, 1, 6, 4, 5

    printList(list);
    printf("\n");
    sortByQS(list, ASC);
    printf("\n");
    printList(list);
    printf("\n\n");

    // STACK* stack = &((STACK) { NULL });

    // ITEM* item1 = createItem(generateData(1, 10));
    // ITEM* item2 = createItem(generateData(2, 20));
    // ITEM* item3 = createItem(generateData(3, 30));
    // ITEM* item4 = createItem(generateData(4, 40));
    // ITEM* item5 = createItem(generateData(5, 50));

    // push(stack, item1);
    // push(stack, item2);
    // push(stack, item3);
    // push(stack, item4);
    // push(stack, item5);

    // printf("\n"); printStack(stack); printf("\n");
    // pop(stack);
    // pop(stack);
    // DATA* data = top(stack);
    // printf("\n%d == %d\n", data->key, data->value); //item2

    // printf("\n"); printStack(stack); printf("\n");

    releaseWholeList(list);
    return 0;
}
