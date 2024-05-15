#include <stdio.h>
#include "libs/seach.h"

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 6, 15, 17, 19, 22, 28, 30, 34};
    int x[] = {19, 37};
    int sizeArray = sizeof(a) / sizeof(a[0]);
    int sizeX = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < sizeX; i++)
    {
        int result = binarySearch(a, sizeArray, &*(x + i));
        printIndex(result);
    }

    return 0;
}