#include <stdio.h>
#include <math.h>
#include <windows.h>

void print8BitBinary(int number)
{
    for (int i = 7; i >= 0; i--)
    {
        int bit = (number >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main()
{

    int binary = 31;
    int index = 7;
    int check = 1;

    print8BitBinary(binary);
    while (1)
    {
        if (binary == 248)
        {
            check = 0;
        }
        if (binary == 31)
        {
            check = 1;
        }
        if (check == 1)
        {
            binary += pow(2, index) - pow(2, index - 3);
            index--;
        }
        if (check == 0)
        {
            binary += pow(2, index - 2) - pow(2, index + 1);
            index++;
        }
        print8BitBinary(binary);
        Sleep(30);
    }
    return 0;
}
