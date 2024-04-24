#include <iostream>
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
    int numberatorTemp;
    int numberator = 0;
    int denominator = fraction[0]->denominator * lcm;
    for (int i = 0; i < N; i++)
    {
        numberatorTemp *= lcm / fraction[i]->denominator;
        numberator += numberatorTemp;
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
    int *numberatorTemp = new int[N];
    for (int i = 0; i < N; i++)
    {
        numberatorTemp[i] = fraction[i]->numberator;
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                numberatorTemp[i] *= fraction[j]->denominator;
            }
        }
    }
    int numberator = numberatorTemp[0];
    int denominator = fraction[0]->denominator;
    for (int i = 1; i < N; i++)
    {
        numberator -= numberatorTemp[i];
        denominator *= fraction[i]->denominator;
    }
    delete[] numberatorTemp;
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
Comp comparingFraction(Fraction *fraction[N])
{
    for (int i = 0; i < N; i++)
    {
        if (isChecked(fraction[i]))
        {
            return NOCOMP;
        }
    }
    int *numberatorTemp = new int[N];
    for (int i = 0; i < N; i++)
    {
        numberatorTemp[i] = fraction[i]->numberator;
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                numberatorTemp[i] *= fraction[j]->denominator;
            }
        }
    }
    int *numberator = new int[N];
    for (int i = 0; i < N; i++)
    {
        numberator[i] = numberatorTemp[0];
        for (int j = 0; j < N; j++)
        {
            numberator[i] *= numberatorTemp[j];
        }
        /* code */
        //printf("haha: %d\n", numberator[i]);
    }
    for (int i = 0; i < N; i++)
    {
    }
    return EQUAL;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Fraction *fraction[N];
    for (int i = 0; i < N; i++)
    {
        fraction[i] = generateFaction(generateRandomNumber(-100, 100), generateRandomNumber(-100, 100));
    }

    /*     fraction[0] = generateFaction(6, 8);
        fraction[1] = generateFaction(5, 7);
        fraction[2] = generateFaction(-2, 5); */

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
    switch (comparingFraction(fraction))
    {
    case 0:
        printf("The fraction are undefined!!\n");
        break;
    case 1:
        printf("Equal");
        break;
    }

    for (int i = 0; i < N; i++)
    {
        delete fraction[i];
    }

    /*  delete sum;
     delete different;
     delete product;
     delete quotient; */

    return 0;
}