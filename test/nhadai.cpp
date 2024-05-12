#include <iostream>
#include <fstream>

using namespace std;

#define maxCount 100009
typedef unsigned long long int ll;

void swap(ll *a, ll *b)
{
    ll *temp = a;
    a = b;
    b = temp;
}

void bubbleSort(ll a[], int n)
{
    bool swapped;
    do
    {
        swapped = false;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                swapped = true;
            }
        }

    } while (swapped);
}

bool checkStairNumber(int n)
{
    if (n <= 11)
    {
        return false;
    }
    while (n != 0)
    {
        if ((n / 10) % 10 > n % 10)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

int binarySearch(ll arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

void printArray(ll a[], ll n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void checkNumber(ll a[], ll b[], int n, int k)
{
    int kq = 0;
    for (int j = 0; j < k; j++)
    {
        int count = 0;
        int result = binarySearch(a, 0, n - 1, b[j]);
        for (int i = result; i < n; i++)
        {
            if (a[i] != b[j])
            {
                break;
            }
            count++;
        }
        for (int i = result - 1; i >= 0; i--)
        {
            if (a[i] != b[j])
            {
                break;
            }
            count++;
        }
        if (checkStairNumber(count) == true)
        {
            cout << b[j] << " " << count << endl;
            kq++;
        }
    }
    if (kq == 0)
    {
        cout << 0;
    }
}

int main()
{
    int n, k;
    ifstream fileInput(".//inputNhaDai.txt");
    if (fileInput.fail())
    {
        cout << "Failed" << endl;
        return -1;
    }

    fileInput >> n;
    fileInput >> k;

    ll a[maxCount];
    ll b[maxCount];

    for (int i = 0; i < n; i++)
    {
        fileInput >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        fileInput >> b[i];
    }


    bubbleSort(a, n);
    bubbleSort(b, k);

    printArray(a, n);
    printArray(b, k);
    checkNumber(a, b, n, k);

    fileInput.close();
    return 0;
}