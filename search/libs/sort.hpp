#include <iostream>
#include <fstream>

void intputArray(int a[], int *n)
{
    int i;
    std::ifstream fileInput(".//testInput.txt");
    if (fileInput.fail())
    {
        std::cout << "Fail" << std::endl;
    }
    fileInput >> *n;
    for (i = 0; i < *n; i++)
    {
        fileInput >> *(a + i);
    }
    fileInput.close();
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << *(a + i) << " ";
    }
    std::cout << std::endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n)
{
    int i;
    bool swapped;
    do
    {
        swapped = false;
        for (i = 1; i < n; i++)
        {
            if (*(a + i) < *(a + i - 1))
            {
                swap((a + i), (a + i - 1));
                swapped = true;
            }
        }

    } while (swapped);
}

void selectionSort(int a[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (*(a + j) < *(a + minIndex))
            {
                minIndex = j;
            }
        }
        swap((a + minIndex), (a + i));
    }
}

void insertionSort(int a[], int n)
{
    int i, posValue, pos;
    for (i = 1; i < n; i++)
    {
        pos = i;
        posValue = *(a + i);
        while (pos > 0 && *(a + pos - 1) > posValue)
        {
            *(a + pos) = *(a + pos - 1);
            pos--;
        }
        *(a + pos) = posValue;
    }
}

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

void sharkerSort(int a[], int n)
{
    int i, left, right, k;
    left = 0;
    right = n - 1;
    k = 0;
    while (left < right)
    {
        for (i = left; i < right; i++)
        {
            if (*(a + i) > *(a + i + 1))
            {
                swap((a + i), (a + i + 1));
                k = i;
            }
        }
        right = k;
        for (i = right; i > left; i--)
        {
            if (*(a + i) < *(a + i - 1))
            {
                swap((a + i), (a + i - 1));
                k = i;
            }
        }
        left = k;
    }
}

void shellSort(int a[], int n)
{
    int i, h, pos, posValue;
    for (h = n / 2; h > 0; h /= 2)
    {
        for (i = h; i < n; i++)
        {
            pos = i;
            posValue = *(a + i);
            while (pos >= h && *(a + pos - h) > posValue)
            {
                *(a + pos) = *(a + pos - h);
                pos -= h;
            }
            *(a + pos) = posValue;
        }
    }
}

void partition(int a[], int low, int high)
{
    int i, j;
    int pivot = (low + high) / 2;
    i = low;
    j = high;
    do
    {
        while (*(a + i) < *(a + pivot) && i < high)
        {
            i++;
        }
        while (*(a + j) > *(a + pivot) && j > low)
        {
            j--;
        }
        if (i <= j)
        {
            swap((a + i), (a + j));
            i++;
            j--;
        }

    } while (i <= j);
    if (i < high)
    {
        partition(a, i, high);
    }
    if (j > low)
    {
        partition(a, low, j);
    }
}

void quickSort(int a[], int n)
{
    partition(a, 0, n - 1);
}