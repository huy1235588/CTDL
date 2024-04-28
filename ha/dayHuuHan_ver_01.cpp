#include <iostream>
#include <math.h>
typedef unsigned long long int ll;

int main(int argc, char *argv[])
{
    int startTime = time(NULL);
    ll nReduce = (ll)pow(10.0, 1.0);
    ll sum = 0;
    for (ll i = 0; i <= nReduce; i++)
    {
        sum += i;
    }
    ll ha = sum;
    printf("1 + 2 + ... + %llu = %llu\n", nReduce, sum);
    int elapsed = time(NULL) - startTime;
    printf("Duration = %d seconds\n", elapsed);
    for (int exponent = 2; exponent < 12; exponent++)
    {
        int startTime = time(NULL);
        ll n = (ll)pow(10.0, (double)exponent);
        for (ll i = nReduce + 1; i <= n; i += (n / 10))
        {
            ha += pow(10.0, (exponent - 1) * 2);
            sum += ha;
        }
        nReduce = n;
        ha = sum;
        printf("1 + 2 + ... + %llu = %llu\n", n, sum);
        int elapsed = time(NULL) - startTime;
        printf("Duration = %d seconds\n", elapsed);
    }

    return 0;
}