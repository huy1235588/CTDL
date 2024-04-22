#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generateRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(time(NULL));
    const int cols = 10;
    const int rows = 3;
    int n = 20;

    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0)
            {
                matrix[i][j] = generateRandom(0, n - 1);
            }
            else if (i == 1)
            {
                matrix[i][j] = generateRandom(1, n);
            }
            else
            {
                matrix[i][j] = generateRandom(0, n);
            }
        }
    }
    printf("Matrix %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}