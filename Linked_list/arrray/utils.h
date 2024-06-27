#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEXT_MAX_LENGTH 50

void swapInteger(int* __this, int* that);
void swapDouble(double* __this, double* that);
void swapString(char** __this, char** that);
void swapCharacterArray(char* __this, char* that);
int generateRandomInteger(int lower_bound, int upper_bound);

#endif