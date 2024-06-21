//*************************************************************
// main.cpp
// Author: Ha
//*************************************************************

#include "utils.h"
#include "linked_list.h"
// #include "stack.h"

//*************************************************************
//*************************************************************

// random number
int generateRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main(int argc, char *argv[])
{
    LIST list_null1 = (LIST){NULL};
    LIST *list1 = &list_null1;

    LIST list_null2 = (LIST){NULL};
    LIST *list2 = &list_null2;

    LIST list_null3 = (LIST){NULL};
    LIST *list3 = &list_null3;

    LIST list_null4 = (LIST){NULL};
    LIST *list4 = &list_null4;

    NODE *n1[10000] = {0};
    NODE *n2[10000] = {0};
    NODE *n3[10000] = {0};
    NODE *n4[10000] = {0};
    int randomValue[10000];
    for (int i = 1; i <= 10000; i++)
    {
        randomValue[i] = generateRandom(0, 10000);
    }

    for (int i = 1; i <= 10000; i++)
    {
        n1[i] = createNode(generateData(i, randomValue[i]));
    }

    for (int i = 1; i <= 10000; i++)
    {
        n2[i] = createNode(generateData(i, randomValue[i]));
    }

    for (int i = 1; i <= 10000; i++)
    {
        n3[i] = createNode(generateData(i, randomValue[i]));
    }

    for (int i = 1; i <= 10000; i++)
    {
        n4[i] = createNode(generateData(i, randomValue[i]));
    }

    for (int i = 1; i <= 10000; i++)
    {
        addAtHead(list1, n1[i]); // 1
    }

    for (int i = 1; i <= 10000; i++)
    {
        addAtHead(list2, n2[i]); // 1
    }

    for (int i = 1; i <= 10000; i++)
    {
        addAtHead(list3, n3[i]); // 1
    }

    for (int i = 1; i <= 10000; i++)
    {
        addAtHead(list4, n4[i]); // 1
    }

    // printList(list1);
    // printf("\n Sort by Quick Sort: ");
    // sortByQS(list1, ASC);
    // printList(list1);

    // printf("\n\n");

    // printList(list2);
    // printf("\n Sort by Merge Sort: ");
    // sortByMerge(list2, ASC);
    // printList(list2);

    // printf("\n\n");

    // printList(list3);
    // printf("\n Sort by Shell Sort: ");
    // sortByInsertion(list3, ASC);
    // printList(list3);

    // printf("\n\n");

    // printList(list4);
    // printf("\n Sort by Shell Sort: ");
    // sortByShell(list4, DESC);
    // printList(list4);

    double timeQS = measureSortTime(sortByQS, list1, ASC);
    printf("Time taken by sort by QuickSort: %f seconds\n", timeQS);

    double timeMerge = measureSortTime(sortByMerge, list2, ASC);
    printf("Time taken by sort by Merge: %f seconds\n", timeMerge);

    double timeInsertion = measureSortTime(sortByInsertion, list3, ASC);
    printf("Time taken by sort by Insertion: %f seconds\n", timeInsertion);

    double timeShell = measureSortTime(sort, list4, ASC);
    printf("Time taken by sort by Shell: %f seconds\n", timeShell);

    releaseWholeList(list1);
    releaseWholeList(list2);
    releaseWholeList(list3);
    releaseWholeList(list4);
    return 0;
}
