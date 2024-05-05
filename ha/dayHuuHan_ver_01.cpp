#include <iostream>
#include <math.h>
typedef unsigned long long int ll;

int main(int argc, char *argv[])
{
    // 10^7
    int startTime = time(NULL);
    ll nReduce = (ll)pow(10.0, 7.0);
    ll sum = 0;
    for (ll i = 0; i <= nReduce; i++)
    {
        sum += i;
    }
    ll tempSum = sum;

    ll firstN = sum / (ll)pow(10.0, 7.0);
    ll lastN = sum % (ll)pow(10.0, 7.0);
    ll tempFirstN = firstN;
    ll tempLastN = lastN;
    printf("1 + 2 + ... + %llu = %llu%llu\n", nReduce, firstN, lastN);

    // printf("1 + 2 + ... + %llu = %llu\n", nReduce, sum);
    int elapsed = time(NULL) - startTime;
    printf("Duration = %d seconds\n", elapsed);
    // 10^8 -> 10^12
    for (int exponent = 8; exponent <= 12; exponent++)
    {
        int startTime = time(NULL);
        ll n = (ll)pow(10.0, (double)exponent);
        for (ll i = nReduce + 1; i <= n; i += (n / 10))
        {
            tempSum += pow(10.0, (exponent - 1) * 2);
            sum += tempSum;
        }
        nReduce = n;
        tempSum = sum;

        //ll firstN = sum / (ll)pow(10.0, (double)exponent);
        //ll lastN = sum % (ll)pow(10.0, (double)exponent);
        //printf("1 + 2 + ... + %llu = %llu%llu\n", nReduce, firstN, lastN);

        printf("1 + 2 + ... + %llu = %llu\n", n, sum);
        int elapsed = time(NULL) - startTime;
        printf("Duration = %d seconds\n", elapsed);
    }
    // 10^16
    startTime = time(NULL);
    ll n = (ll)pow(10.0, (double)16.0);
    for (ll i = nReduce + 1; i <= n; i += (n / 10))
    {
        tempSum += pow(10.0, (16.0 - 1) * 2);
        sum += tempSum;
    }
    nReduce = n;
    tempSum = sum;

    firstN = sum / (ll)pow(10.0, 16.0);
    lastN = sum % (ll)pow(10.0, 16.0);
    printf("1 + 2 + ... + %llu = %llu%llu\n", nReduce, firstN, lastN);

    //printf("1 + 2 + ... + %llu = %llu\n", n, sum);
    elapsed = time(NULL) - startTime;
    printf("Duration = %d seconds\n", elapsed);
    return 0;
}