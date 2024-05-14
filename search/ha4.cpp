#include <stdio.h>
#include "libs/seach.h"

int main(int argc, char *argv[])
{
    int a[] = {34, 30, 28, 22, 19, 17, 15, 6, 2, 1};
    int x[] = {19, 34};
    int sizaA = sizeof(a) / sizeof(a[0]);
    int sizaX = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < sizaX; i++)
    {
        int result = binaryDecreaseSearch(a, sizaA, &*(x + i));
        printIndex(result);
    }
    return 0;
}