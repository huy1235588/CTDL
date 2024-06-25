#include <stdlib.h>

#include "libs/sort.c"

void printMenu()
{
    printf("**Welcome to Ha** \t\t\n");
    printf("~Menu~\t\t\n");

    printf(" (1) Print \n");
    printf(" (2) Insert \n");
    printf(" (3) Search \n");
    printf(" (4) Sort \n");
    printf(" (0) exit \n");
}

int getUserChoice()
{
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void displayMenu()
{
    int choice;
    int *array;
    int size = 100;

    array = (int *)malloc(size * sizeof(int));
    int n = sizeof(array) / sizeof(*(array + 0));

    if (array == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    do
    {
        printMenu();
        choice = getUserChoice();

        switch (choice)
        {
        case 1:
            printf(" (1) Array \n");
            printArray(array, n);
            break;
        case 2:
            printf(" (2) Enter number to insert: ");
            insertArray(array, n);
            break;
            // case 3:
            //     cout << " (3) Spaghetti Bolognaise ----" << " $" << totalSpaghetti << endl;
            //     totalSpaghetti = spaghetti * mealQuantity;
            //     break;
            // case 4:
            //     cout << " (4) Prawns Pesto ------------" << " $" << totalPesto << endl;
            //     totalPesto = pesto * mealQuantity;
            //     break;
            // case 5:
            //     cout << "(5) Assorted Friedrice ------" << " $" << totalFried << endl;
            //     totalFried = friedrice * mealQuantity;
            //     break;
            // case 6:
            //     cout << " (6) Garlic Buttered Prawns---" << " $" << totalPrawns << endl;
            //     totalPrawns = prawns * mealQuantity;
            //     break;
        }
    } while (choice != 0);

    printf(" \n\t\t ----Thank you for companion with us---- \t\t\n");
    free(array);
}