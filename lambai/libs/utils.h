#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Boolean {
    FALSE = 0,
    TRUE = 1
} BOOLEAN;

typedef enum Order {
    DESC = 0,
    ASC = 1
} ORDER;

typedef enum Comparsion {
    EQUAL_TO = 0,
    GREATER_THAN = 1,
    LESS_THAN = -1
} COMPARISON;

typedef struct Data {
    int key;
    int value;
} DATA;

#endif