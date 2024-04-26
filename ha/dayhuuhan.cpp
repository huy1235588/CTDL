#include <iostream>
#include <time.h>
#include <math.h>
#include <stdint.h>
typedef unsigned long long int ll;
int main(int argc, char *argv[])
{
    for (int pows = 7; pows < 13; pows++)
    {
        int startTime = time(NULL);
        ll powss = ((ll)pow(10, pows-1)) * ((ll)pow(10, pows-1)) * 100;
        ll firstNumber = 4 * powss;
        ll secondNumber = 9 * (powss / pow(10,1));
        for (int i = 2; i < pows; i++)
        {
            secondNumber += 9 * (powss / pow(10,i));
        }
        ll powsss = ((ll) pow(10, pows-1)) * 10;
        ll thirdNumber = 5 * powsss;
        ll sum = firstNumber + secondNumber + thirdNumber;
        printf("\n1 + 2 + ... + 10^%d = %llu\n", pows, sum);
        int elapsedTime = time(NULL) - startTime;
        printf("Duration: %d seconds\n", elapsedTime);
    }
    return 0;
}