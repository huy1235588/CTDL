#include "libs/sort.hpp"

int main(int argc, char *argv[])
{
    int n, i;
    bool check = true;

    int *array1 = intputArray(n);
    int *array2 = intputArray(n);
    int *array3 = intputArray(n);
    int *array4 = intputArray(n);
    int *array5 = intputArray(n);
    int *array6 = intputArray(n);
    int *array7 = intputArray(n);
    if (array1 != nullptr && array2 != nullptr && array3 != nullptr && array4 != nullptr && array5 != nullptr && array6 != nullptr && array7 != nullptr)
    {
        bubbleSort(array1, n);
        selectionSort(array2, n);
        insertionSort(array3, n);
        mergeSort(array4, n);
        sharkerSort(array5, n);
        shellSort(array6, n);
        quickSort(array7, n);
        // printArray(array, n);
        for (i = 0; i < n; i++)
        {
            if (*(array1 + i) != *(array7 + i))
            {
                check = false;
            }
        }
        printf("check: %s", check ? "true" : "false");

        delete[] array1;
        delete[] array2;
        delete[] array3;
        delete[] array4;
        delete[] array5;
        delete[] array6;
        delete[] array7;
    }
    else
    {
        std::cout << "Array initialization failed." << std::endl;
    }

    return 0;
}