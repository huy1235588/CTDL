#include <iostream>
#include <math.h>
typedef unsigned long long int ll;

int main(int argc, char *argv[])
{
    ll firstNumberSum = 0;
    ll midleNumberSum = 0;
    ll lastNumberSum = 0;
    ll temp = 9 * pow(10.0, 9.0);
    for (double i = 0; i < 9; i++)
    {
         temp += 9 * pow(10.0, i);
    }
    
    printf("temp: %llu\n", temp);
    for (double pows = 7; pows < 12; pows++)
    {
        int startTime = time(NULL);
        ll n = (ll)pow(10.0, pows);
        ll i;
        for (i = 0; i < n; i++)
        {
            lastNumberSum += i;
            if (lastNumberSum >= temp)
            {
                midleNumberSum++;
                lastNumberSum = lastNumberSum - pow(10.0, 10.0);
            }
        }
        printf("1 + 2 + ... + %llu = %llu %llu\n", n, midleNumberSum, lastNumberSum);
        int elapsedTime = time(NULL) - startTime;
        printf("Duration: %d seconds\n", elapsedTime);
    }

    return 0;
}