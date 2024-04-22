#include <iostream>
#include <stdlib.h>
#include <stdio.h>

// Hàm nhập mảng
void inputArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Nhập phần tử thứ  %d: ", i + 1);
        scanf("%d", arr + i);
    }
    printf("\n");
}

// Hàm in mảng
void printArray(int *arr, int size)
{
    printf("Mảng đã cấp phát là: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}


int main(int argc, char *argv[])
{
    int size;
    int extendSize = 2;
    printf("Nhập size: ");
    scanf("%d", &size);
    // Cấp phát bộ nhớ động cho mảng
    int *arr = (int *)malloc(size * sizeof(int));

    // Thông báo cấp phát
    if (arr == NULL)
    {
        printf("Cấp phát thất bại \n");
        return 1;
    }
    else
    {
        printf("Cấp phát thành công \n");
        inputArray(arr, size); // Nhập mảng
        printArray(arr, size); // In mảng
        // Mở rộng mảng
        arr = (int *)realloc(arr, (size + extendSize) * sizeof(int));
        // Thêm 2 phần tử vào mảng
        for (int i = size; i < size + extendSize; i++)
        {
            printf("Nhập thêm phần tử thứ %d vào mảng: ", i + 1);
            scanf("%d", arr + i);
        }

        printArray(arr, size + extendSize); // In mảng

        // Giải phóng vùng nhớ
        free(arr);
    }

    return 0;
}