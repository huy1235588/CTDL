#include <stdio.h>
#include "libs/seach.h"

int main(int argc, char *argv[])
{
    int a[] = {8, 2, 6, 15, 7, 9, 22, 18, 10, 14};
    int x[] = {19, 7};
    int sizaA = sizeof(a) / sizeof(a[0]);
    int sizaX = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < sizaX; i++)
    {
        int result = linearSearch(a, sizaA, &*(x + i));
        printIndex(result);
    }
    return 0;
}