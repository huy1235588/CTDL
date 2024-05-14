#include <stdio.h>
#include "libs/seach.h"

int main(int argc, char *argv[])
{
    int a[] = {1, 2, 6, 15, 17, 19, 22, 28, 30, 34};
    int x[] = {19, 37};
    int sizaA = sizeof(a) / sizeof(a[0]);
    int sizaX = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < sizaX; i++)
    {
        int result = binarySearch(a, sizaA, &*(x + i));
        printIndex(result);
    }

    return 0;
}