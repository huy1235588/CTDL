#include <stdio.h>
int binarySearch(int *a, int n, int *k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (*(a + mid) == *k)
        {
            return mid;
        }
        else if (*(a + mid) < *k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int binaryDecreaseSearch(int *a, int n, int *k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (*(a + mid) == *k)
        {
            return mid;
        }
        else if (*(a + mid) < *k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int linearSearch(int *a, int n, int *k)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) == *k)
        {
            return i;
        }
    }
    return -1;
}

int sentinelLinearSearch(int *a, int n, int *k)
{
    int last = *(a + (n - 1));
    int i = 0;
    while (*(a + i) != *k )
    {
        i++;
    }
    *(a + (n - 1)) = last;
    if ((i < n - 1) || (last == *k))
    {
        return i;
    }
    else
    {
        return -1;
    }
}

void printIndex(int result)
{
    if (result != -1)
    {
        printf("index = %d\n", result);
    }
    else
    {
        printf("Not found\n");
    }
}
