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
        double n = pow(10.0, Exponent);

        double sum = ((n * (n + 1)) / 2) / pow(10.0, Exponent - 1);
        printf("1 + 2 + ... + 10^%d = %.0Fe+%d\n", (int)Exponent, sum, (int)(Exponent - 1.0));
        int elapsed = time(NULL) - startTime;
        printf("Duration: %d seconds\n", elapsed);
    }
    int startTIme = time(NULL);
    double n = pow(10.0, 16.0);
    double sum = ((n * (n + 1)) / 2) / pow(10.0, 15.0);
    printf("1 + 2 + ... + 10^%d = %.15Fe+%d\n", 16, sum, 15);
    return 0;
}