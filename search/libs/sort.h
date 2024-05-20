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
        fileInput >> a[i];
    }
    fileInput.close();
    
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << a[i] << "\t";
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
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&a[minIndex], &a[i]);
    }
}

void insertionSort(int a[], int n)
{
    int i, firstValueUnodered, pos;
    for (i = 1; i < n; i++)
    {
        pos = i;
        firstValueUnodered = a[i];
        while (pos > 0 && a[pos - 1] > firstValueUnodered)
        {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = firstValueUnodered;
    }
}