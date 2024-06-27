#ifndef __ARRAYS_H__
#define __ARRAYS_H__

#include "utils.h"

// Array of Integers
void demonstrate_array_of_integers();   // demo fucntion
void print_array_of_integers(int __array[], int __size);
int linear_search(int __array[], int __size, int __key);
int sentinel_linear_search(int __array[], int __size,  int __key);
int binary_search(int __array[], int __size,  int __key);

void selection_sort(int __array[], int __size);
void interchange_sort(int __array[], int __size);
void bubble_sort(int __array[], int __size);
void insertion_sort(int __array[], int __size);
void shaker_sort(int __array[], int __size);
void shell_sort(int __array[], int __size);
void quick_sort(int __array[], int __size);
void merge_sort(int __array[], int __size);

// Dynamic Array of Structs
typedef struct __Data {
    int key;
    int number;
    char text[TEXT_MAX_LENGTH];
} __DATA;

void demonstrate_dynamic_array_of_data();   // demo fucntion
void enter_dynamic_array_of_data(__DATA* __array, int __size, int __quantity);
void print_dynamic_array_of_data(__DATA* __array, int __size);
int linear_search_in_array_of_data(__DATA* __array, int __size, char __text[]);
void selection_sort_in_array_of_data(__DATA* __array, int __size);

#endif