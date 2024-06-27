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

void swapData(STUDENT* this, STUDENT* that) {
    STUDENT temp = *this;
    *this = *that;
    *that = temp;
}

int compareDataByKey(STUDENT this, STUDENT that) {
    int comparsion = 0;
    if (this.id > that.id) {
        comparsion = 1;
    } else if (this.id < that.id) {
        comparsion = -1;
    }
    return comparsion;
}

int compareDataByAvg(STUDENT this, STUDENT that) {
    int comparsion = 0;
    if (this.averageScore > that.averageScore) {
        comparsion = 1;
    } else if (this.averageScore < that.averageScore) {
        comparsion = -1;
    }
    return comparsion;
}

int compareDataByValue(STUDENT this, STUDENT that) {
    return strcmp(this.name, that.name);
}

int generateRandomInteger(int lower_bound, int upper_bound){
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}