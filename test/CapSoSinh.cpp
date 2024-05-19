#include <iostream>
#include <fstream>
using namespace std;
typedef unsigned long long int ll;
ll capSoSinh(ll m, ll n)
{
    int count = 0;
    ll mTemp2 = m;
    for (int i = 0; i < n; i++)
    {
        ll mTemp = mTemp2;
        ll x = mTemp % 10;
        x += mTemp;
        mTemp /= 10;
        while (mTemp != 0)
        {
            x += mTemp % 10;
            mTemp /= 10;
        }
        if (m + n >= mTemp + x)
        {
            count++;
        }
        mTemp2++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    ll m, n;
    ifstream fileInput(".//inputCapSoSinh.txt");
    if (fileInput.fail())
    {
        cout << "Failed" << endl;
        return -1;
    }

    fileInput >> m;
    fileInput >> n;

    cout << capSoSinh(m, n);
    fileInput.close();
    return 0;
}