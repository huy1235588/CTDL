#include <iostream>

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

int main(){

}