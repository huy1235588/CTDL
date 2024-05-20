#include <iostream>
#include <fstream>
using namespace std;

int solve(int n, int a, int b)
{
    for (int x = n / b, y = n % b; x >= 0; --x)
    {
        if (y % a == 0)
        {
            return x + y / a;
        }
        y += b;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int n;
    fstream inputFile(".//dongGao.txt");
    if (inputFile.fail())
    {
        cout << "Fail";
    }
    inputFile >> n;
    cout << solve(n, 3, 5);
    return 0;
}