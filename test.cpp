#include <iostream>
#include <math.h>
#define ll unsigned long long int
int main()
{
    for (double pows = 7; pows < 12; pows++)
    {
        int startTime = time(NULL);
        ll n = (ll)pow(10.0, pows);
        ll sum = 0;
        ll sumE = 0;
        ll i;
        for (i = 0; i <= n; i++)
        {
            if (sum == pow(10.0, 9.0))
            {
                sumE += i;
                continue;
            }
            sum += i;
        }
        printf("1 + 2 + ... + %llu = %llu\n", n, sum);
        int elapsedTime = time(NULL) - startTime;
        printf("Duration: %d seconds\n", elapsedTime);
    }
    return 0;
}