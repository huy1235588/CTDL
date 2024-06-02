#include <iostream>
#include "libs/sort.hpp"

void merge(int array[], int left, int middle, int right)
{
    int i, j, k;
    int leftArraySize = middle - left + 1;
    int rightArraySize = right - middle;
    int leftArray[leftArraySize], rightArray[rightArraySize];
    for (i = 0; i < leftArraySize; i++)
    {
        *(leftArray + i) = *(array + i + left);
    }
    for (j = 0; j < rightArraySize; j++)
    {
        *(rightArray + j) = *(array + j + middle + 1);
    }
    i = 0, j = 0, k = left;
    while (i < leftArraySize && j < rightArraySize)
    {
        if (*(leftArray + i) <= *(rightArray + j))
        {
            *(array + k) = *(leftArray + i);
            i++;
        }
        else
        {
            *(array + k) = *(rightArray + j);
            j++;
        }
        k++;
    }
    while (i < leftArraySize)
    {
        *(array + k) = *(leftArray + i);
        i++;
        k++;
    }
    while (j < rightArraySize)
    {
        *(array + k) = *(rightArray + j);
        j++;
        k++;
    }
}

void _mergeSort(int array[], int low, int high)
{
    int middle;
    if (low < high)
    {
        middle = (low + high) / 2;
        _mergeSort(array, low, middle);
        _mergeSort(array, middle + 1, high);
        merge(array, low, middle, high);
    }
}

void mergeSort(int array[], int n)
{
    _mergeSort(array, 0, n - 1);
}

int main(int argc, char *argv[])
{
    int a[] = {23,523,4,123,6,7,5,2,643};
    int n = sizeof(a) / sizeof(*(a + 0));
    //intputArray(a, &n);
    printArray(a, n);
    mergeSort(a,n);
    printArray(a,n);
    return 0;
}