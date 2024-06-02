#include "libs/sort.hpp"

int main(int argc, char *argv[])
{
    int a[10001], n;
    intputArray(a, &n);
    // bubbleSort(a,n);
    // selectionSort(a,n);
    // insertionSort(a,n);
    // mergeSort(a,n);
    // sharkerSort(a,n);
    //shellSort(a, n);
    quickSort(a,n);
    printArray(a, n);
    return 0;
}