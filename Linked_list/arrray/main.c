//*************************************************************
// main.c
// Author: Smile
//*************************************************************

#include "utils.h"
#include "arrays.h"
// #include "singly_linked_lists.h"
// #include "stacks.h"
// #include "queues.h"
// #include "doubly_linked_lists.h"
// #include "binary_search_trees.h"
// #include "avl_trees.h"

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
        printf("\n[0] Exit the program.");
        printf("\n==================================");
        printf("\nEnter option number [0, 1, 2]: ");
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