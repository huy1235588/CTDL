//*************************************************************
// main.c
// Author: Smile
//*************************************************************

#include "utils.h"
#include "arrays.h"
#include "singly_linked_lists.h"
#include "stacks.h"
#include "queues.h"
// #include "doubly_linked_lists.h"
// #include "binary_search_trees.h"
// #include "avl_trees.h"
#include "hashtable/hash_table.h"

//*************************************************************
//*************************************************************
int main(int argc, char* argv[]) {
    // MENU
    int loopable = 1;
    int option = -1;
    do {
        printf("\n\n========== PROGRAM MENU ==========");
        printf("\n[1] Demonstrate an array of integers.");
        printf("\n[2] Demonstrate a dynamic array of data.");
        printf("\n[3] Demonstrate a singly linked list.");
        printf("\n[4] Demonstrate a stack.");
        printf("\n[5] Demonstrate a queue.");
        printf("\n[6] Demonstrate a doubly linked list.");
        printf("\n[7] Demonstrate a binary search tree.");
        printf("\n[8] Demonstrate a AVL tree.");
        printf("\n[9] Demonstrate a hash table.");
        printf("\n[0] Exit the program.");
        printf("\n==================================");
        printf("\nEnter option number [0 - 9]: ");
        scanf("%d", &option);
        getchar();
        switch (option) {
            case 1:
                printf("\n\n[1] Demonstrate an array of integers\n");
                demonstrate_array_of_integers();
                break;
            case 2:
                printf("\n\n[2]Demonstrate a dynamic array of data\n");
                demonstrate_dynamic_array_of_data();
                break;
            case 3:
                printf("\n\n[3] Demonstrate a singly linked list\n");
                demonstrate_singly_linked_lists();
                break;
            case 4:
                printf("\n\n[4] Demonstrate a stack\n");
                demonstrate_stacks();
                break;
            case 5:
                printf("\n\n[5] Demonstrate a queue\n");
                demonstrate_queues();
                break;
            case 6:
                printf("\n\n[6] Demonstrate a doubly linked list\n");
                break;
            case 7:
                printf("\n\n[7] Demonstrate a binary search tree\n");
                break;
            case 8:
                printf("\n\n[8] Demonstrate a AVL tree\n");
                break;
            case 9:
                printf("\n\n[9] Demonstrate a hash table\n");
                break;
            case 0:
                printf("\n\n[0] Exit the program\n\n");
                loopable = 0;
                break;
            default:
                break;
        }
    } while(loopable);
    
    return 0;
}