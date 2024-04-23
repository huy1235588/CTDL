#include <iostream>
#include <time.h>

struct fraction
{
    int numerator;
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
    Fraction *pFraction = new Fraction;
    pFraction->numerator = numberator;
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
    if (isChecked(fraction))
    {
        return NULL;
    }
    int gcd = greatestCommonDivisor(fraction->numerator, fraction->denominator);
    int numerator = fraction->numerator / gcd;
    int denominator = fraction->denominator / gcd;
    return generateFaction(numerator, denominator);
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
        printf("%d\n", fraction->numerator);
    }
    else
    {
        printf("%d/%d \n", fraction->numerator, fraction->denominator);
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
        printf("%d\n", fraction->numerator);
    }
    else
    {
        printf("%d/%d \n", fraction->numerator, fraction->denominator);
    }
}

Fraction *computeSum(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1) || isChecked(fraction2))
    {
        return NULL;
    }
    int numerator = fraction1->numerator * fraction2->denominator + fraction2->numerator * fraction1->denominator;
    int denominator = fraction1->denominator * fraction2->denominator;
    return generateFaction(numerator, denominator);
}

Fraction *computeDifferent(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1) || isChecked(fraction2))
    {
        return NULL;
    }
    int numerator = fraction1->numerator * fraction2->denominator - fraction2->numerator * fraction1->denominator;
    int denominator = fraction1->denominator * fraction2->denominator;
    return generateFaction(numerator, denominator);
}

Fraction *computeProduct(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1) || isChecked(fraction2))
    {
        return NULL;
    }
    int numerator = fraction1->numerator * fraction2->numerator;
    int denominator = fraction1->denominator * fraction2->denominator;
    return generateFaction(numerator, denominator);
}

Fraction *computeQuotient(Fraction *fraction1, Fraction *fraction2)
{
    if (isChecked(fraction1) || isChecked(fraction2))
    {
        return NULL;
    }
    int numerator = fraction1->numerator * fraction2->denominator;
    int denominator = fraction1->denominator * fraction2->numerator;
    return generateFaction(numerator, denominator);
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
    int numerator1 = fraction1->numerator * fraction2->denominator;
    int numerator2 = fraction2->numerator * fraction1->denominator;

    return (numerator1 == numerator2 ? EQUAL : (numerator1 > numerator2 ? GREATER: LESS));
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Fraction *fraction1 = generateFaction(generateRandomNumber(1, 100), generateRandomNumber(1, 100));
    Fraction *fraction2 = generateFaction(generateRandomNumber(1, 100), generateRandomNumber(1, 100));
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
    if (comparingFraction(fraction1, fraction2) == 1)
    {
        printf("Equal");
    }else if (comparingFraction(fraction1, fraction2) == 2)
    {
        printFraction(fraction1);
    }else
    {
        printFraction(fraction2);
    }
    

    delete fraction1;
    delete fraction2;
    delete sum;
    delete different;
    delete product;
    delete quotient;

    return 0;
}