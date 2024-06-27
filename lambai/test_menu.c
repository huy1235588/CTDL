
#include "libs/utils.h"
#include "libs/linked_list.h"

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

void printMenu()
{
    printf("\n\n==========Welcome to Ha==========\n");
    printf("~Menu~\t\t\n");

    printf(" (1) Print \n");
    printf(" (2) Insert \n");
    printf(" (3) Search \n");
    printf(" (4) Sort \n");
    printf(" (0) Exit \n");
    printf("==================================\n");
}

void printMenuInsert()
{
    printf("\n===========Menu Inserts===========\n");

    printf(" (1) ADD at Head \n");
    printf(" (2) ADD at Tail \n");
    printf(" (3) ADD after node \n");
    printf(" (4) Add at Position \n");
    printf(" (0) Exit \n");
    printf("==================================\n");
}

void printMenuSort()
{
    printf("\n============Menu Sorts============\n");

    printf(" (1) Interchange Sort \n");
    printf(" (2) QuickSort \n");
    printf(" (3) Merge Sort \n");
    printf(" (4) Insertion Sort \n");
    printf(" (5) Shell Sort \n");
    printf(" (0) Exit \n");
    printf("==================================\n");
}

void printMenuSortOrder()
{
    printf("\n==================================\n");
    printf(" (1) Sort in Ascending order \n");
    printf(" (2) Sort in Descending order \n");
    printf("==================================\n");
}

int getUserChoice()
{
    int choice;
    printf("Enter your choice:");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int choice, choiceInsert, choiseSort, choiseSortOrder, value, pos, keyOfNote;
    int key = 1;
    ORDER order;

    LIST list_null = (LIST){NULL};
    LIST *list = &list_null;
    NODE *node;
    NODE *nodeTemp;

    do
    {
        printMenu();
        choice = getUserChoice();

        switch (choice)
        {
        case 1:
            if (isEmptyList(list))
            {
                printf("\n==================================\n");
                printf("List is empty");
                printf("\n==================================\n");
            }
            else
            {
                printf("\n==============Lists==============");
                printList(list);
                printf("\n==================================\n");
            }
            break;

        case 2:
            printf("\nEnter value want to insert: ");
            scanf("%d", &value);
            node = createNode(generateData(key, value));
            printMenuInsert();
            choiceInsert = getUserChoice();
            switch (choiceInsert)
            {
            case 1:
                addAtHead(list, node);
                key++;
                break;

            case 2:
                addAtTail(list, node);
                key++;
                break;

            case 3:
                printf("\n==============Lists==============");
                printList(list);
                printf("\n==================================\n");
                
                printf("\nEnter key of node want to add after: ");
                scanf("%d", &keyOfNote);
                nodeTemp = getNode(list, getPositionByKey(list, keyOfNote));
                if (nodeTemp == NULL)
                {
                    printf("Not found\n");
                }
                else
                {
                    addAfter(list, nodeTemp, node);
                    key++;
                }
                break;

            case 4:
                printf("\nEnter position want to add: ");
                scanf("%d", &pos);
                if (addAtPosition(list, pos, node) != NULL)
                {
                    key++;
                }
                else
                {
                    printf("\nFailed to add node at the specified position.\n");
                }
                break;

            default:
                break;
            }
            break;

        case 3:
            printf("\nEnter value want to search: ");
            scanf("%d", &value);
            pos = getPositionByValue(list, value);
            if (pos == -1)
            {
                printf("\nNot found");
            }
            else
            {
                // printf("Position: %d\n", pos);
                node = getNode(list, pos);
                printf("\nNode: ");
                printNode(node);
            }
            break;

        case 4:
            printMenuSort();
            choiseSort = getUserChoice();
            if (choiseSort == 0)
            {
                break;
            }

            printMenuSortOrder();
            choiseSortOrder = getUserChoice();

            if (choiseSortOrder == 1)
            {
                order = ASC;
            }
            else
            {
                order = DESC;
            }

            switch (choiseSort)
            {
            case 1:
                sortinterChange(list, order);
                printList(list);
                break;

            case 2:
                sortByQS(list, order);
                printList(list);
                break;

            case 3:
                sortByMerge(list, order);
                printList(list);
                break;

            case 4:
                sortByInsertion(list, order);
                printList(list);
                break;

            case 5:
                sortByShell(list, order);
                printList(list);
                break;

            default:
                break;
            }
            break;
        }
    } while (choice != 0);

    printf(" \n\t\t ----Thank you for companion with us---- \t\t\n");
    releaseWholeList(list);
    return 0;
}