#include "utils.h"

void swapInteger(int* this, int* that) {
    int temp = *this;
    *this = *that;
    *that = temp; 
}

void swapDouble(double* this, double* that) {
    double temp = *this;
    *this = *that;
    *that = temp; 
}

void swapString(char** this, char** that) { // swap pointers
    char* temp = *this; 
    *this = *that; 
    *that = temp;  
}

void swapCharacterArray(char* this, char* that) {    // swap data
    char* temp = (char*) malloc ((strlen(this) + 1) * sizeof(char)); 
    strcpy(temp, this); 
    strcpy(this, that); 
    strcpy(that, temp); 
    free(temp); 
}

void swapData(DATA* this, DATA* that) {
    DATA temp = *this;
    *this = *that;
    *that = temp;
}

int compareDataByKey(DATA this, DATA that) {
    int comparsion = 0;
    if (this.key > that.key) {
        comparsion = 1;
    } else if (this.key < that.key) {
        comparsion = -1;
    }
    return comparsion;
}

int compareDataByValue(DATA this, DATA that) {
    return strcmp(this.text, that.text);
}

int generateRandomInteger(int lower_bound, int upper_bound){
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}