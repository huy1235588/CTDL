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

typedef struct Student {
    int id;
    char name[50];
    float mathScore;
    float literatureScore;
    float averageScore;
} STUDENT;


void swapInteger(int* this, int* that);
void swapDouble(double* this, double* that);
void swapString(char** this, char** that);
void swapCharacterArray(char* this, char* that);
void swapData(STUDENT* this, STUDENT* that);

int compareDataByKey(STUDENT this, STUDENT that);
int compareDataByValue(STUDENT this, STUDENT that);
int compareDataByAvg(STUDENT this, STUDENT that);
int generateRandomInteger(int lower_bound, int upper_bound);

#endif