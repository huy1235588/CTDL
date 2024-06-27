//*************************************************************
// main.c
// Author: Smile
//*************************************************************

#include "utils.h"
// #include "arrays.h"
#include "singly_linked_lists.h"
// #include "stacks.h"
// #include "queues.h"
// #include "doubly_linked_lists.h"
// #include "binary_search_trees.h"
// #include "avl_trees.h"
// #include "hashtable/hash_table.h"

//*************************************************************
//*************************************************************
int main(int argc, char *argv[])
{
    // MENU
    int loopable = 1;
    int option = -1;
    SLLIST *list = (SLLIST *)malloc(sizeof(SLLIST));
    if (list != NULL)
    {
        do
        {
            printf("\n\n========== PROGRAM MENU ==========");
            printf("\n[1] Nhap thong tin.");
            printf("\n[2] In ra thong tin .");
            printf("\n[3] Tim hoc sinh cao diem nhat.");
            printf("\n[4] Sap xep danh sach theo diem trung binh tang dan");
            printf("\n[5] Tao ra danh sach cac hoc sinh co diem toan tren 7 diem.");
            printf("\n[0] Exit the program.");
            printf("\n==================================");
            printf("\nEnter option number [0 - 9]: ");
            scanf("%d", &option);
            getchar();
            switch (option)
            {
            case 1:
                printf("\n\n[1] Nhap thong tin\n");
                demonstrate_singly_linked_lists(list);
                break;
            case 2:
                printf("\n\n[2] Cac thong tin cua hoc sinh\n");
                printSinglyLinkedList(list);
                break;
            case 3:
                printf("\n\n[3] Hoc sinh co diem trung binh cao nhat:\n");
                cau4(list);
                break;
            case 4:
                printf("\n\n[4] Sap xep\n");
                sortInAscending(list);
                printSinglyLinkedList(list);
                break;
            case 5:
                printf("\n\n[5] Danh sach\n");
                cau6(list);
                break;
            case 0:
                printf("\n\n[0] Exit the program\n\n");
                loopable = 0;
                break;
            default:
                break;
            }
        } while (loopable);
    }
    else
    {
        puts("Cannot allocate.");
        return -1;
    }
    releaseWholeList(list);
    free(list);
    return 0;
}