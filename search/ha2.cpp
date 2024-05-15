#include <stdio.h>
#include "libs/seach.h"
int main(int argc, char *argv[])
{
    int array[] = {8, 2, 6, 15, 7, 9, 22, 18, 10, 14};
    int x[] = {7, 10, 14, 3};
    int sizeArray = sizeof(array) / sizeof(array[0]);
    int sizeX = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < sizeX; i++)
    {
        int result = sentinelLinearSearch(array, sizeArray, &*(x + i));
        printIndex(result);
    }
    return 0;
}