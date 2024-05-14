#include <stdio.h>
#include "libs/seach.h"
#include <iostream>
int main(int argc, char *argv[])
{
    int array[] = {8, 2, 6, 15, 7, 9, 22, 18, 10, 14};
    int x[] = {7, 10, 14, 6};
    int sizaArray = sizeof(array) / sizeof(array[0]);
    int sizaX = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < sizaX; i++)
    {
        int result = sentinelLinearSearch(array, sizaArray, &*(x + i));
        printIndex(result);
    }
    return 0;
}