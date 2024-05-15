#include <stdio.h>
#include "libs/seach.h"

int main(int argc, char *argv[])
{
    int a[] = {8, 2, 6, 15, 7, 9, 22, 18, 10, 14};
    int x[] = {19, 7};
    int sizeArray = sizeof(a) / sizeof(a[0]);
    int sizeX = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < sizeX; i++)
    {
        int result = linearSearch(a, sizeArray, &*(x + i));
        printIndex(result);
    }
    return 0;
}