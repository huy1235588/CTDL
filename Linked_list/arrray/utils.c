#include "utils.h"

void swapInteger(int* __this, int* __that) {
    int temp = *__this;
    *__this = *__that;
    *__that = temp; 
}

void swapDouble(double* __this, double* __that) {
    double temp = *__this;
    *__this = *__that;
    *__that = temp; 
}

void swapString(char** __this, char** __that) { // swap pointers
    char* temp = *__this; 
    *__this = *__that; 
    *__that = temp;  
}

void swapCharacterArray(char* __this, char* __that) {    // swap data
    char* temp = (char*) malloc ((strlen(__this) + 1) * sizeof(char)); 
    strcpy(temp, __this); 
    strcpy(__this, __that); 
    strcpy(__that, temp); 
    free(temp); 
}

int generateRandomInteger(int lower_bound, int upper_bound){
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}