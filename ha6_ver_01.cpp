#include <iostream>

using namespace std;

struct Fraction
{
    int numerator;   // Tử số
    int denominator; // Mẫu số
};

// Hàm tìm ước số chung lớn nhất
int greatest_Common_Divisor(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm nhập phân số
void inputFraction(Fraction *frac)
{
    cout << "Nhap tu so: ";
    cin >> frac->numerator;
    do
    {
        cout << "Nhap mau so (khac 0): ";
        cin >> frac->denominator;
    } while (frac->denominator == 0);
}

// Hàm tính tổng hai phân số
void add(Fraction *frac1, Fraction *frac2)
{
    int resultNumerator = (frac1->numerator * frac2->denominator) + (frac2->numerator * frac1->denominator);
    int resultDenominator = (frac1->denominator * frac2->denominator);
    cout << resultNumerator << "/" << resultDenominator << endl;
}

// Hàm tính hiệu hai phân số
void subtract(Fraction *frac1, Fraction *frac2)
{
    int resultNumerator = (frac1->numerator * frac2->denominator) - (frac2->numerator * frac1->denominator);
    int resultDenominator = (frac1->denominator * frac2->denominator);
    cout << resultNumerator << "/" << resultDenominator << endl;
}

// Hàm tính tích hai phân số
void multiply(Fraction *frac1, Fraction *frac2)
{
    int resultNumerator = (frac1->numerator * frac2->numerator);
    int resultDenominator = (frac1->denominator * frac2->denominator);
    cout << resultNumerator << "/" << resultDenominator << endl;
}

// Hàm tính thương hai phân số
void divide(Fraction *frac1, Fraction *frac2)
{
    int resultNumerator = (frac1->numerator * frac2->denominator);
    int resultDenominator = (frac1->denominator * frac2->numerator);
    cout << resultNumerator << "/" << resultDenominator << endl;
}

// Hàm quy đồng mẫu của hai phân số.
void makeSameDenominator(Fraction *frac1, Fraction *frac2)
{
    int commonDenominator = frac1->denominator * frac2->denominator;
    frac1->numerator *= frac2->denominator;
    frac2->numerator *= frac1->denominator;
    frac1->denominator = frac2->denominator = commonDenominator;
    cout << frac1->numerator << "/" << frac1->denominator << " và ";
    cout << frac2->numerator << "/" << frac2->denominator << endl;
}

// Hàm so sánh hai phân số.
void compareFractions(Fraction *frac1, Fraction *frac2)
{
    if (frac1->numerator < frac2->numerator)
    {
        cout << frac1->numerator << "/" << frac1->denominator << " < ";
        cout << frac2->numerator << "/" << frac2->denominator << endl;
    }
    else
    {
        cout << frac1->numerator << "/" << frac1->denominator << " > ";
        cout << frac2->numerator << "/" << frac2->denominator << endl;
    }
}

// Hàm rút gọn phân số
void simplifyFracion(int *a, int *b)
{
    int gcd = greatest_Common_Divisor(*a, *b);
    *a /= gcd;
    *b /= gcd;
}

// Hàm in rút gọn phân số
void printSimplifyFracion(Fraction *frac)
{
    simplifyFracion(&(frac->numerator), &(frac->denominator));
    if (frac->denominator == 1)
    {
        cout << frac->numerator;
    }
    else
    {
        cout << frac->numerator << "/" << frac->denominator << endl;
    }
}

int main()
{
    Fraction frac1, frac2;
    cout << "Nhập phân số thứ nhất:\n";
    inputFraction(&frac1);
    cout << "Nhập phân số thứ hai:\n";
    inputFraction(&frac2);
    cout << endl;

    // In phân số thứ nhất
    // cout << "Phân số thứ nhất là: ";
    // printFraction(&frac1);
    // // In phân số thứ hai
    // cout << "Phân số thứ hai là: ";
    // printFraction(&frac2);
    // cout << endl;

    // Tổng 2 phân số
    cout << "Tổng 2 phân số: ";
    add(&frac1, &frac2);
    // Hiệu 2 phân số
    cout << "Hiệu 2 phân số: ";
    subtract(&frac1, &frac2);
    // Tích 2 phân số
    cout << "Tích 2 phân số: ";
    multiply(&frac1, &frac2);
    // Thương 2 phân số
    cout << "Thương 2 phân số: ";
    divide(&frac1, &frac2);
    cout << endl;

    // Quy đồng mẫu của hai phân số.
    cout << "Quy đồng mẫu của hai phân số: ";
    makeSameDenominator(&frac1, &frac2);
    cout << endl;

    // So sánh hai phân số.
    compareFractions(&frac1, &frac2);
    cout << endl;

    // rút gọn phân số
    cout << "Phân số thứ nhất được rút gọn là: ";
    printSimplifyFracion(&frac1);
    cout << "Phân số thứ hai được rút gọn là: ";
    printSimplifyFracion(&frac2);
    return 0;
}