#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEXT_MAX_LENGTH 50

typedef enum Boolean {
    FALSE = 0,
    TRUE = 1
} BOOLEAN;

typedef enum Order {
    DESC = 0,
    ASC = 1
} ORDER;

typedef struct Data {
    int key;
    int number;
    char text[TEXT_MAX_LENGTH];
} DATA;


void swapInteger(int* this, int* that);
void swapDouble(double* this, double* that);
void swapString(char** this, char** that);
void swapCharacterArray(char* this, char* that);
void swapData(DATA* this, DATA* that);

int compareDataByKey(DATA this, DATA that);
int compareDataByValue(DATA this, DATA that);

int generateRandomInteger(int lower_bound, int upper_bound);

#endif