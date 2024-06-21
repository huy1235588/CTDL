//*************************************************************
// main.cpp
// Author: Ha
//*************************************************************

#include "utils.h"
#include "linked_list.h"
// #include "stack.h"

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
    LIST list_null1 = (LIST){NULL};
    LIST *list1 = &list_null1;

    LIST list_null2 = (LIST){NULL};
    LIST *list2 = &list_null2;

    // NODE *n1[100] = {0};
    // NODE *n2[100] = {0};

    // for (int i = 1; i <= 100; i++)
    // {
    //     n1[i] = createNode(generateData(i, 10));
    // }
    // for (int j = 1; j <= 100; j++)
    // {
    //     n2[j] = createNode(generateData(j, 10));
    // }

    // for (int i = 1; i <= 100; i += 8)
    // {
    //     addAtHead(list1, n1[i]);               // 1
    //     addAtHead(list1, n1[i + 1]);           // 2, 1
    //     addAtHead(list1, n1[i + 2]);           // 3, 2, 1
    //     addAtTail(list1, n1[i + 3]);           // 3, 2, 1, 4
    //     addAtTail(list1, n1[i + 4]);           // 3, 2, 1, 4, 5
    //     addAfter(list1, n1[i], n1[i + 5]);     // 3, 2, 1, 6, 4, 5
    //     addAfter(list1, n1[i + 6], n1[i + 7]); // 3, 2, 1, 6, 4, 5
    // }

    NODE *n1 = createNode(generateData(1, 10));
    NODE *n2 = createNode(generateData(2, 20));
    NODE *n3 = createNode(generateData(3, 30));
    NODE *n4 = createNode(generateData(4, 40));
    NODE *n5 = createNode(generateData(5, 50));
    NODE *n6 = createNode(generateData(6, 60));
    NODE *n7 = createNode(generateData(7, 70));
    NODE *n8 = createNode(generateData(8, 80));
    NODE *n9 = createNode(generateData(9, 80));
    NODE *n10 = createNode(generateData(10, 57));
    NODE *n11 = createNode(generateData(11, 46));
    NODE *n12 = createNode(generateData(12, 82));
    NODE *n13 = createNode(generateData(13, 45));
    NODE *n14 = createNode(generateData(14, 52));
    NODE *n15 = createNode(generateData(15, 67));
    NODE *n16 = createNode(generateData(16, 12));
    NODE *n17 = createNode(generateData(17, 37));
    NODE *n18 = createNode(generateData(18, 43));
    NODE *n19 = createNode(generateData(19, 97));
    NODE *n20 = createNode(generateData(20, 24));
    NODE *n21 = createNode(generateData(21, 66));
    NODE *n22 = createNode(generateData(22, 35));
    NODE *n23 = createNode(generateData(23, 98));
    NODE *n24 = createNode(generateData(24, 35));

    addAtHead(list1, n1);  // 1
    addAtHead(list1, n2);  // 2, 1
    addAtHead(list1, n3);  // 3, 2, 1
    addAtHead(list1, n4);  // 3, 2, 1, 4
    addAtHead(list1, n5);  // 3, 2, 1, 4, 5
    addAtHead(list1, n6);  // 3, 2, 1, 6, 4, 5
    addAtHead(list1, n8);  // 3, 2, 1, 6, 4, 5
    addAtHead(list1, n9);  // 3, 2, 1, 6, 4, 5
    addAtHead(list1, n10); // 3, 2, 1, 6, 4, 5
    // addAtHead(list1, n11); // 3, 2, 1, 6, 4, 5
    // addAtHead(list1, n12); // 3, 2, 1, 6, 4, 5
    // addAtHead(list1, n13); // 3, 2, 1, 6, 4, 5
    // addAtHead(list1, n14); // 3, 2, 1, 6, 4, 5
    // addAtHead(list1, n15); // 3, 2, 1, 6, 4, 5
    // addAtHead(list1, n16); // 3, 2, 1, 6, 4, 5

    // addAtHead(list1, n9);  // 3, 2, 1, 9, 6, 4, 5
    // addAtTail(list1, n10); // 3, 2, 10, 1, 9, 6, 4, 5
    // addAtHead(list1, n11); // 3, 11, 2, 10, 1, 9, 6, 4, 5
    // addAtHead(list1, n12); // 3, 11, 2, 10, 1, 9, 6, 4, 12, 5
    // addAtHead(list1, n13); // 3, 11, 2, 10, 1, 9, 6, 4, 12, 5, 13

    // addAfter(list1, n5, n9);  // 3, 2, 1, 9, 6, 4, 5
    // addAfter(list1, n2, n10); // 3, 2, 10, 1, 9, 6, 4, 5
    // addAfter(list1, n9, n11); // 3, 11, 2, 10, 1, 9, 6, 4, 5
    // addAfter(list1, n4, n12); // 3, 11, 2, 10, 1, 9, 6, 4, 12, 5
    // addAfter(list1, n6, n13); // 3, 11, 2, 10, 1, 9, 6, 4, 12, 5, 13

    // addAtHead(list1, n9);      // 9, 3, 2, 1, 6, 4, 5
    // addAtHead(list1, n10);     // 10, 9, 3, 2, 1, 6, 4, 5
    // addAtHead(list1, n11);     // 11, 10, 9, 3, 2, 1, 6, 4, 5
    // addAtTail(list1, n12);     // 11, 10, 9, 3, 2, 1, 6, 4, 5, 12
    // addAtTail(list1, n13);     // 11, 10, 9, 3, 2, 1, 6, 4, 5, 12, 13
    // addAfter(list1, n1, n14);  // 11, 10, 9, 3, 2, 1, 14, 6, 4, 5, 12, 13
    // addAfter(list1, n15, n16); // 11, 10, 9, 3, 2, 1, 14, 6, 4, 5, 12, 13

    // addAtHead(list1, n17);     // 17, 11, 10, 9, 3, 2, 1, 14, 6, 4, 5, 12, 13
    // addAtHead(list1, n18);     // 18, 17, 11, 10, 9, 3, 2, 1, 14. 6, 4, 5, 12, 13
    // addAtHead(list1, n19);     // 19, 18, 17, 11, 10, 9, 3, 2, 1, 14, 6, 4, 5, 12, 13
    // addAtTail(list1, n20);     // 19, 18, 17, 11, 10, 9, 3, 2, 1, 14, 6, 4, 5, 12, 13, 20
    // addAtTail(list1, n21);     // 19, 18, 17, 11, 10, 9, 3, 2, 1, 14, 6, 4, 5, 12, 13, 20, 21
    // addAfter(list1, n1, n22);  // 19, 18, 17, 11, 10, 9, 3, 2, 1, 22. 14, 6, 4, 5, 12, 13, 20, 21
    // addAfter(list1, n23, n24); // 19, 18, 17, 11, 10, 9, 3, 2, 1, 22. 14, 6, 4, 5, 12, 13, 20, 21

    printList(list1);
    printf("\n");
    // sort(list1, ASC);
    sortByQS(list1, ASC);
    // sortByMerge(list1, DESC);
    printList(list1);

    printf("\n\n");

    // printList(list2);
    // printf("\n");
    // sortByMerge(list1, ASC);
    // printList(list1);

    // double timeQS = measureSortTime(sortByQS, list, ASC);
    // printf("Time taken by sortByQS: %f seconds\n", timeQS);

    // double timeMerge = measureSortTime(sortByMerge, list2, ASC);
    // printf("Time taken by sortByMerge: %f seconds\n", timeMerge);

    releaseWholeList(list1);
    releaseWholeList(list2);
    return 0;
}
