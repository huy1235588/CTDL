//*************************************************************
// main.cpp
// Author: Ha
//*************************************************************

#include "utils.h"
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "binary_search_tree.h"
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
    // LIST list_null = (LIST){NULL};
    // LIST *list = &list_null;

    // LIST list_null2 = (LIST){NULL};
    // LIST *list2 = &list_null2;

    // NODE *n1 = createNode(generateData(1, 10));
    // NODE *n2 = createNode(generateData(2, 20));
    // NODE *n3 = createNode(generateData(3, 30));
    // NODE *n4 = createNode(generateData(4, 40));
    // NODE *n5 = createNode(generateData(5, 50));
    // NODE *n6 = createNode(generateData(6, 60));
    // NODE *n7 = createNode(generateData(7, 70));
    // NODE *n8 = createNode(generateData(8, 80));

    // NODE *nn1 = createNode(generateData(1, 10));
    // NODE *nn2 = createNode(generateData(2, 20));
    // NODE *nn3 = createNode(generateData(3, 30));
    // NODE *nn4 = createNode(generateData(4, 40));
    // NODE *nn5 = createNode(generateData(5, 50));
    // NODE *nn6 = createNode(generateData(6, 60));
    // NODE *nn7 = createNode(generateData(7, 70));
    // NODE *nn8 = createNode(generateData(8, 80));

    // addAtHead(list, n1);    // 1
    // addAtHead(list, n2);    // 2, 1
    // addAtHead(list, n3);    // 3, 2, 1
    // addAtTail(list, n4);    // 3, 2, 1, 4
    // addAtTail(list, n5);    // 3, 2, 1, 4, 5
    // addAfter(list, n1, n6); // 3, 2, 1, 6, 4, 5
    // addAfter(list, n7, n8); // 3, 2, 1, 6, 4, 5

    // addAtHead(list2, nn1);     // 1
    // addAtHead(list2, nn2);     // 2, 1
    // addAtHead(list2, nn3);     // 3, 2, 1
    // addAtTail(list2, nn4);     // 3, 2, 1, 4
    // addAtTail(list2, nn5);     // 3, 2, 1, 4, 5
    // addAfter(list2, nn1, nn6); // 3, 2, 1, 6, 4, 5
    // addAfter(list2, nn7, nn8); // 3, 2, 1, 6, 4, 5

    // printList(list);
    // printf("\n");
    // sortByQS(list, ASC);
    // printList(list);

    // printf("\n");

    // printList(list2);
    // printf("\n");
    // sortByMerge(list2, ASC);
    // printList(list2);

    // double timeQS = measureSortTime(sortByQS, list, ASC);
    // printf("Time taken by sortByQS: %f seconds\n", timeQS);

    // double timeMerge = measureSortTime(sortByMerge, list2, ASC);
    // printf("Time taken by sortByMerge: %f seconds\n", timeMerge);

    // releaseWholeList(list);
    // releaseWholeList(list2);

    //*************************************************************
    // STACK
    //*************************************************************
    // STACK stack_null = (STACK){NULL};
    // STACK *stack = &stack_null;
    // // STACK* stack = &((STACK) { NULL });

    // ITEM *item1 = createItem(generateData(1, 11));
    // ITEM *item2 = createItem(generateData(2, 95));
    // ITEM *item3 = createItem(generateData(3, 24));
    // ITEM *item4 = createItem(generateData(4, 47));
    // ITEM *item5 = createItem(generateData(5, 63));
    // ITEM *item6 = createItem(generateData(6, 87));

    // push(stack, item1);
    // push(stack, item2);
    // push(stack, item3);
    // push(stack, item4);
    // push(stack, item5);
    // push(stack, item6);

    // printf("\n\nStack:");
    // printStack(stack);
    // printf("\n\n");

    // pop(stack);
    // printStack(stack);

    // pop(stack);
    // pop(stack);
    // pop(stack);
    // pop(stack);
    // printf("\n\n");
    // printStack(stack);

    // pop(stack);
    // printf("\n");
    // printStack(stack);

    // freeStack(stack);
    // if (isEmptyStack(stack))
    // {
    //     printf("Release Stack succeces");
    // }

    //*************************************************************
    // QUEUE
    //*************************************************************

    // QUEUE queue_null = (QUEUE){NULL};
    // QUEUE *queue = &queue_null;

    // ELEMENT *element1 = createElement(generateData(1, 10));
    // ELEMENT *element2 = createElement(generateData(2, 23));
    // ELEMENT *element3 = createElement(generateData(3, 41));
    // ELEMENT *element4 = createElement(generateData(4, 4151));
    // ELEMENT *element5 = createElement(generateData(5, 2));
    // ELEMENT *element6 = createElement(generateData(6, 5));

    // enqueue(queue, element1);
    // enqueue(queue, element2);
    // enqueue(queue, element3);
    // enqueue(queue, element4);
    // enqueue(queue, element5);
    // enqueue(queue, element6);

    // printf("\n\nQueue:");
    // printQueue(queue);
    // printf("\n\n");

    // dequeue(queue);
    // printQueue(queue);

    // dequeue(queue);
    // dequeue(queue);
    // dequeue(queue);
    // dequeue(queue);
    // printf("\n\n");
    // printQueue(queue);

    // dequeue(queue);
    // printf("\n");
    // printQueue(queue);

    // freeQueue(queue);
    // if (isEmptyQueue)
    // {
    //     printf("Release Queue succeces");
    // }

    //*************************************************************
    // BINARY SEARCH TREE
    //*************************************************************
    TREE root = NULL;

    TNODE *TreeNode1 = createTreeNode(generateData(1, 10));
    TNODE *TreeNode2 = createTreeNode(generateData(2, 23));
    TNODE *TreeNode3 = createTreeNode(generateData(3, 41));
    TNODE *TreeNode4 = createTreeNode(generateData(4, 4151));
    TNODE *TreeNode5 = createTreeNode(generateData(5, 2));
    TNODE *TreeNode6 = createTreeNode(generateData(6, 5));

    // printf("\nroot outside adress: %p\t root: %p\n", &root, root);
    // printf("\nroot outside: %p\t root right: %p\n", &root, root->right);

    insert(&root, TreeNode6);
    insert(&root, TreeNode3);
    insert(&root, TreeNode1);
    insert(&root, TreeNode5);
    insert(&root, TreeNode4);
    insert(&root, TreeNode2);

    printf("\n\nBinary Tree:\n");
    traverse((root));
    printf("\n\n");

    TNODE *key5 = search(root, 5);
    printf("Key 5: %d :: %d\n", key5->data->key, key5->data->value);

    TNODE *min_Tree_Node = minTreeNode(root);
    printf("min_Tree_Node: %d :: %d\n", min_Tree_Node->data->key, min_Tree_Node->data->value);

    freeTree(&root);
    if (root == NULL)
    {
        printf("Release Tree succeces");
    }

    return 0;
}
