#include <iostream>
using namespace std;

void inputArray(int *arr, int sizeOfArray){
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout<<"Nhập phần tử thứ "<<i+1<<": ";
        cin>> *(arr + i);
    }
}

void printArray(int* arr, int sizeOfArray){
    cout<<"Mảng đã nhập là: ";
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout<< *(arr + i)<<" ";
    }
    
}

int main(int argc, char* argv[]){
    int sizeOfArray=5;
    int arr[sizeOfArray];
    int *ptr = arr;
    inputArray(arr, sizeOfArray);
    printArray(arr, sizeOfArray);
    return 0;
}