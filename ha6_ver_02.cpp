#include <stdio.h>
#include <stdlib.h>
struct fraction
{
    int numerator;   // tu so
    int denominator; // mẫu số
};
typedef struct fraction Fraction;
Fraction *generate_fraction(int numerator, int denominator)
{
    if (denominator == 0)
    {
        return NULL;
    }
    Fraction *pFraction = (Fraction *)malloc(sizeof(Fraction));
    pFraction->denominator = denominator;
    pFraction->numerator = numerator;
    return pFraction;
}

void print(Fraction *fraction)
{
    if (fraction == NULL)
    {
        printf("unidentified number!\n");
        return;
    }
    printf("%d/%d\n", fraction->numerator, fraction->denominator);
}

int is_checked(Fraction *fraction1, Fraction *fraction2)
{
    if (fraction1 == NULL || fraction2 == NULL)
    {
        return -1; // fail
    }
    return 0; // success
}

Fraction *compute_sum(Fraction *fraction1, Fraction *fraction2)
{
    if (is_checked(fraction1, fraction2))
    {
        return NULL;
    }
    int denominator = fraction1->denominator * fraction2->denominator;
    int numerator = fraction1->numerator * fraction2->denominator + fraction2->numerator + fraction1->denominator;
    return generate_fraction(numerator, denominator);
}

Fraction *compute_different(Fraction *fraction1, Fraction *fraction2)
{
    if (is_checked(fraction1, fraction2))
    {
        return NULL;
    }
    int denominator = fraction1->denominator * fraction2->denominator;
    int numerator = fraction1->numerator * fraction2->denominator - fraction2->numerator * fraction1->denominator;
    return generate_fraction(numerator, denominator);
}

Fraction *compute_product(Fraction *fraction1, Fraction *fraction2)
{
    if (is_checked(fraction1, fraction2))
    {
        return NULL;
    }
    int denominator = fraction1->denominator * fraction2->denominator;
    int numerator = fraction1->numerator * fraction2->numerator;
    return generate_fraction(numerator, denominator);
}

Fraction *compute_quotient(Fraction *fraction1, Fraction *fraction2)
{
    if (is_checked(fraction1, fraction2))
    {
        return NULL;
    }
    int denominator = fraction1->denominator * fraction2->numerator;
    int numerator = fraction1->numerator * fraction2->denominator;
    return generate_fraction(numerator, denominator);
}



int main(int argc, char *argv[])
{
    Fraction *fraction1 = generate_fraction(2, 3);
    Fraction *fraction2 = generate_fraction(1, 4);
    printf("F1: ");
    print(fraction1);
    // printf("%d/%d \n", fraction1->numerator, fraction1->denominator);
    printf("F2: ");
    print(fraction2);
    // sun, different, product, quotient
    Fraction *sum = compute_sum(fraction1, fraction2);
    Fraction *different = compute_different(fraction1, fraction2);
    Fraction *product = compute_product(fraction1, fraction2);
    Fraction *quotient = compute_quotient(fraction1, fraction2);
    printf("Sum: ");
    print(sum);
    printf("Different: ");
    print(different);
    printf("Product: ");
    print(product);
    printf("Quotient: ");
    print(quotient);
    // Release
    free(fraction1);
    free(fraction2);
    free(sum);
    free(different);
    free(product);
    free(quotient);
    return 0;
}