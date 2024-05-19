#include <iostream>
#include <fstream>
using namespace std;
int a[100];
void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int n)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 2; i <= n; i++)
        {
            if (a[i - 1] > a[i])
            {
                swap(a[i], a[i - 1]);
                swapped = true;
            }
        }

    } while (swapped);
}

int findLeastTime(int n)
{
    if (n == 1)
    {
        return a[1];
    }
    if (n == 2)
    {
        return a[2];
    }
    if (n == 3)
    {
        return a[1] + a[2] + a[3];
    }
    return min(findLeastTime(n - 1) + a[1] + a[n], findLeastTime(n - 2) + a[1] + a[n] + 2 * a[2]);
}

int main(int argc, char *argv[])
{
    int n;
    fstream fileInput(".//inputQuaCau.txt");
    if (fileInput.fail())
    {
        cout << "fail";
        return -1;
    }
    fileInput >> n;
    for (int i = 1; i <= n; i++)
    {
        fileInput >> a[i];
    }
    bubbleSort(n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << findLeastTime(n);
    return 0;
}