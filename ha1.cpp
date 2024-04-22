#include <iostream>

using namespace std;

void swap(int* n1, int* n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main(){
    int a, b;
    int *numA, *numB;
    numA = &a;
    numB = &b;
    cout<< "Nhập a: ";
    cin>>a;
    cout<< "Nhập b: ";
    cin>>b;
    swap(numA, numB);
    cout<<"a sau khi hoán đổi là: "<<a<<endl;
    cout<<"b sau khi hoán đổi là: "<<b<<endl;
    return 0;
}