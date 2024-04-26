#include <iostream>
#include <stdint.h>
#include <time.h>

#define N 4
typedef long long int ll;

struct fraction
{
    int numberator;
    int denominator;
};
typedef struct fraction Fraction;

int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

Fraction *generateFaction(int numberator, int denominator)
{
    if (denominator == 0)
    {
        return NULL;
    }
    if (denominator < 0)
    {
        numberator *= -1;
        denominator *= -1;
    }

    Fraction *pFraction = new Fraction;
    pFraction->numberator = numberator;
    pFraction->denominator = denominator;
    return pFraction;
}

int greatestCommonDivisor(int a, int b)
{
    while (a != 0)
    {
        int temp = a;
        a = b % a;
        b = temp;
    }
    return abs(b);
}

int isChecked(Fraction *fraction)
{
    if (fraction == NULL)
    {
        return -1; // fail
    }
    return 0; // success
}

Fraction *simplifyingFraction(Fraction *fraction)
{
    if (fraction == NULL)
    {
        return NULL;
    }
    int gcd = greatestCommonDivisor(fraction->numberator, fraction->denominator);
    int numberator = fraction->numberator / gcd;
    int denominator = fraction->denominator / gcd;
    return generateFaction(numberator, denominator);
}

void printFraction(Fraction *fraction)
{

    fraction = simplifyingFraction(fraction);
    if (fraction == NULL)
    {
        printf("The fraction are undefined!!\n");
        return;
    }

    if (fraction->denominator == 1)
    {
        printf("%d\n", fraction->numberator);
    }
    else
    {
        printf("%d/%d \n", fraction->numberator, fraction->denominator);
    }
}

void printFractionNotSimple(Fraction *fraction)
{
    if (fraction == NULL)
    {
        printf("The fraction are undefined!!\n");
        return;
    }

    if (fraction->denominator == 1)
    {
        printf("%d\n", fraction->numberator);
    }
    else
    {
        printf("%d/%d \n", fraction->numberator, fraction->denominator);
    }
}

ll leastCommonMultiple(Fraction *fraction[N])
{
    // Initialize result
    ll ans = fraction[0]->denominator;

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for (int i = 1; i < N; i++)
        ans = (((fraction[i]->denominator * ans)) /
               (greatestCommonDivisor(fraction[i]->denominator, ans)));

    return ans;
}

Fraction *computeSum(Fraction *fraction[N])
{
    for (int i = 0; i < N; i++)
    {
        if (isChecked(fraction[i]))
        {
            return NULL;
        }
    }
    int lcm = leastCommonMultiple(fraction);
    int numberator = lcm / fraction[0]->denominator * fraction[0]->numberator;
    int denominator = lcm;
    for (int i = 1; i < N; i++)
    {
        numberator += lcm / fraction[i]->denominator * fraction[i]->numberator;
    }
    return generateFaction(numberator, denominator);
}

Fraction *computeDifferent(Fraction *fraction[N])
{
    for (int i = 0; i < N; i++)
    {
        if (isChecked(fraction[i]))
        {
            return NULL;
        }
    }
    int lcm = leastCommonMultiple(fraction);
    int numberator = lcm / fraction[0]->denominator * fraction[0]->numberator;
    int denominator = lcm;
    for (int i = 1; i < N; i++)
    {
        numberator -= lcm / fraction[i]->denominator * fraction[i]->numberator;
    }
    return generateFaction(numberator, denominator);
}

Fraction *computeProduct(Fraction *fraction[N])
{
    for (int i = 0; i < N; i++)
    {
        if (isChecked(fraction[i]))
        {
            return NULL;
        }
    }
    int numberator = 1;
    int denominator = 1;
    for (int i = 0; i < N; i++)
    {
        numberator *= fraction[i]->numberator;
        denominator *= fraction[i]->denominator;
    }
    return generateFaction(numberator, denominator);
}

Fraction *computeQuotient(Fraction *fraction[N])
{
    for (int i = 0; i < N; i++)
    {
        if (isChecked(fraction[i]))
        {
            return NULL;
        }
    }
    int numberator = fraction[0]->numberator;
    int denominator = fraction[0]->denominator;
    for (int i = 1; i < N; i++)
    {
        numberator *= fraction[i]->denominator;
        denominator *= fraction[i]->numberator;
    }
    return generateFaction(numberator, denominator);
}

enum CompareFraction
{
    NOCOMP,
    EQUAL,
    GREATER,
    LESS,
};
typedef enum CompareFraction Comp;
int *comparingFraction(Fraction *fraction[N])
{
    for (int i = 0; i < N; i++)
    {
        if (isChecked(fraction[i]))
        {
            return nullptr;
        }
    }
    int nullNumber = -1;
    int *pNullNumber = &nullNumber;
    int lcm = leastCommonMultiple(fraction);
    int numberator;
    int maxNumberator = 0;
    int maxNumberatorPosition[N];
    for (int i = 0; i < N; i++)
    {
        maxNumberatorPosition[i] = -2;
    }
    int minNumberator = INT16_MAX;
    int minNumberatorPosition;
    for (int i = 0; i < N; i++)
    {
        numberator = lcm / fraction[i]->denominator * fraction[i]->numberator;
        if (numberator >= maxNumberator)
        {
            maxNumberator = numberator;
            maxNumberatorPosition[i] = i;
        }
    }
    int *pMaxNumberatorPosition = maxNumberatorPosition;
    return (maxNumberator == 0 && minNumberator == INT16_MAX ? pNullNumber : pMaxNumberatorPosition);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Fraction *fraction[N];
    /*for (int i = 0; i < N; i++)
    {
        fraction[i] = generateFaction(generateRandomNumber(-100, 100), generateRandomNumber(-100, 100));
    }*/

    // fraction[0] = generateFaction(6, 8);
    // fraction[1] = generateFaction(5, 7);
    // fraction[2] = generateFaction(-2, 5);
    // fraction[3] = generateFaction(3, 4);

    // fraction[0] = generateFaction(6, 8);
    // fraction[1] = generateFaction(6, 8);
    // fraction[2] = generateFaction(6, 8);
    // fraction[3] = generateFaction(6, 8);

    fraction[0] = generateFaction(6, 0);
    fraction[1] = generateFaction(6, 0);
    fraction[2] = generateFaction(6, 0);
    fraction[3] = generateFaction(6, 0);

    for (int i = 0; i < N; i++)
    {
        printf("Franction %d: ", i);
        printFractionNotSimple(fraction[i]);
    }

    //  Sum
    Fraction *sum = computeSum(fraction);
    printf("Sum: ");
    printFraction(sum);
    // Different
    Fraction *different = computeDifferent(fraction);
    printf("Different: ");
    printFraction(different);
    // Product
    Fraction *product = computeProduct(fraction);
    printf("Product: ");
    printFraction(product);
    // Quotient
    Fraction *quotient = computeQuotient(fraction);
    printf("Quotient: ");
    printFraction(quotient);
    // Compare
    printf("Compare: ");
    if (*comparingFraction(fraction) == 0)
    {
        printf("Equal \n");
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << *(comparingFraction(fraction) + i) << std::endl;
            if (*(comparingFraction(fraction) + i) != -2)
            {
                printFraction(fraction[i]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        delete fraction[i];
    }

    delete sum;
    delete different;
    delete product;
    delete quotient;

    return 0;
}