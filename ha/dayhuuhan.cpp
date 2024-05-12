#include <iostream>
#include <math.h>
#include <time.h>
#include <sstream>
#include <iomanip>

typedef unsigned long long int ll;
using namespace std;
int main(int argc, char *argv[])
{
    for (ll Exponent = 7; Exponent <= 12; Exponent++)
    {
        int startTime = time(NULL);
        ll n = pow(10.0, Exponent);

        ll sum = (n * (n + 1)) / 2;
        printf("1 + 2 + ... + %llu = %llu\n", n, sum);
        int elapsed = time(NULL) - startTime;
        printf("Duration: %d seconds\n", elapsed);
    }
    int startTIme = time(NULL);
    ll n = pow(10.0, 16.0);
    ll sum = (n * (n + 1)) / 2;
    printf("1 + 2 + ... + %llu = %llu\n", n, sum);
    return 0;
}