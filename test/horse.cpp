#include <iostream>

#define N 5
int matrix[N][N];

int main(int argc, char *argv[])
{
    for (int i; i < N; i++)
    {
        for (int j; j < N; j++)
        {
            int matrix [j] = new int;
            matrix[i][j] = -1;
        }
    }

    for (int i; i < N; i++)
    {
        for (int j; j < N; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    matrix[0][0] = 1;
    std::cout << matrix[0][0] << " ";
    return 0;
}