#include <iostream>
#include <time.h>

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

int isChecked(Fraction *fraction1, Fraction *fraction2)
{
    if (fraction1 == NULL || fraction2 == NULL)
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

Fraction *computeSum(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1, fraction2))
    {
        return NULL;
    }
    int numberator = fraction1->numberator * fraction2->denominator + fraction2->numberator * fraction1->denominator;
    int denominator = fraction1->denominator * fraction2->denominator;
    return generateFaction(numberator, denominator);
}

Fraction *computeDifferent(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1, fraction2))
    {
        return NULL;
    }
    int numberator = fraction1->numberator * fraction2->denominator - fraction2->numberator * fraction1->denominator;
    int denominator = fraction1->denominator * fraction2->denominator;
    return generateFaction(numberator, denominator);
}

Fraction *computeProduct(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1, fraction2))
    {
        return NULL;
    }
    int numberator = fraction1->numberator * fraction2->numberator;
    int denominator = fraction1->denominator * fraction2->denominator;
    return generateFaction(numberator, denominator);
}

Fraction *computeQuotient(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1, fraction2))
    {
        return NULL;
    }
    int numberator = fraction1->numberator * fraction2->denominator;
    int denominator = fraction1->denominator * fraction2->numberator;
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
Comp comparingFraction(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1, fraction2))
    {
        return NOCOMP;
    }

    int numberator1 = fraction1->numberator * fraction2->denominator;
    int numberator2 = fraction2->numberator * fraction1->denominator;

    return (numberator1 == numberator2 ? EQUAL : (numberator1 > numberator2 ? GREATER : LESS));
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Fraction *fraction1 = generateFaction(generateRandomNumber(-100, 100), generateRandomNumber(-100, 100));
    Fraction *fraction2 = generateFaction(generateRandomNumber(-100, 100), generateRandomNumber(-100, 100));
    // Fraction *fraction1 = generateFaction(3, -2);
    // Fraction *fraction2 = generateFaction(7, 4);
    // Fraction *fraction1 = generateFaction(3, 4);
    // Fraction *fraction2 = generateFaction(3, 4);

    printf("Franction 1: ");
    printFractionNotSimple(fraction1);
    printf("Franction 2: ");
    printFractionNotSimple(fraction2);
    //  Sum
    Fraction *sum = computeSum(fraction1, fraction2);
    printf("Sum: ");
    printFraction(sum);
    // Different
    Fraction *different = computeDifferent(fraction1, fraction2);
    printf("Different: ");
    printFraction(different);
    // Product
    Fraction *product = computeProduct(fraction1, fraction2);
    printf("Product: ");
    printFraction(product);
    // Quotient
    Fraction *quotient = computeQuotient(fraction1, fraction2);
    printf("Quotient: ");
    printFraction(quotient);
    // Compare
    printf("Compare: ");
    switch (comparingFraction(fraction1, fraction2))
    {
    case 0:
        printf("The fraction are undefined!!\n");
        break;
    case 1:
        printf("Equal");
        break;
    case 2:
        printFraction(fraction1);
        break;
    case 3:
        printFraction(fraction2);
        break;
    }

    delete fraction1;
    delete fraction2;
    delete sum;
    delete different;
    delete product;
    delete quotient;

    return 0;
}