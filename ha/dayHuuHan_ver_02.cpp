#include <iostream>
#include <math.h>
#include <time.h>
#include <sstream>
#include <iomanip>

typedef unsigned long long int ll;
using namespace std;
int main(int argc, char *argv[])
{
    for (double Exponent = 7; Exponent <= 12; Exponent++)
    {
        int startTime = time(NULL);
        ll n = (ll)pow(10.0, Exponent);
        ll sum = (n * (n + 1)) / 2;
        printf("1 + 2 + ... + 10^%d = %llu\n", (int)Exponent, sum);
        cout << setw(24) << scientific << sum << endl;
        int elapsed = time(NULL) - startTime;
        printf("Duration: %d seconds\n", elapsed);
    }
    return 0;
}