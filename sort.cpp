#include <stdio.h>
// #include <iostream>

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
        //std::cout << a[i] << "\t";
    }
    printf("\n");
    //std::cout << std::endl;
}

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void selection_sort(int a[], int n) {
    int i, j, min;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&a[min], &a[i]);
        } 
    }
}

void insertion_sort(int a[], int n) {
    int i, pos;
    int x;
    for (i = 1; i < n; i++) {
        pos = i;
        x = a[i];
        while (pos > 0 && a[pos - 1] > x) {
            a[pos] = a[pos - 1];
            pos--;
        }
        a[pos] = x;
    }
}

void interchange_sort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void bubble_sort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j + 1] < a[j]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void shaker_sort(int a[], int n) {
    int i, left, right, k;
    left = 0;
    right = n - 1;
    k = 0;
    while(left < right) {
        // push big to tail
        for (i = right; i > left; i--) {
            if (a[i - 1] > a[i]) {
                swap(&a[i - 1], &a[i]);
                k = i;
            }
        }
        left = k;
        // push small to head
        for (i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                k = i;
            }
        }
        right = k;
    }
}

void _partition(int a[], int low, int high){
    int i, j;
    int pivot_index = low + (high - low)/2; // or (low + high)/2 or high or low
    int pivot = a[pivot_index];
    i = low; // left
    j = high; // right
    do {
        while (a[i] < pivot && i < high) {
            i++;
        }
        while (a[j] > pivot && j > low) {
            j--;
        }
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (low < j) {
        _partition(a, low, j);
    }
    if (i < high) {
        _partition(a, i, high);
    }
}
void quick_sort(int a[], int n) {
    _partition(a, 0, n - 1);
}

void shell_sort(int a[], int n){
    int h, i, pos, x;
    for (h = n/2; h > 0; h /= 2) {
        for (i = h; i < n; i++) {
            pos = i;
            x = a[i];
            while (pos >= h && a[pos - h] > x) {
                a[pos] = a[pos - h];
                pos -= h;
            }
            a[pos] = x;
        }
    }
}

void _merge(int a[], int low, int middle, int high){
    int i, j, k;
    int l_size = middle - low + 1;
    int h_size = high - middle;
    int l_arr[l_size];
    int h_arr[h_size];
    for (i = 0; i < l_size; i++){
        l_arr[i] = a[low + i];
    }  
    for (j = 0; j < h_size; j++){
        h_arr[j] = a[middle + j + 1];
    }
    i = 0;
    j = 0;
    k = low;
    while (i < l_size && j < h_size) {
        if (l_arr[i] > h_arr[j]) {
            a[k] = l_arr[i];
            i++;
        }
        else {
            a[k] = h_arr[j];
            j++;
        }
        k++;
    }
    while (i < l_size) {
        a[k] = l_arr[i];
        i++;
        k++;
    }
    while (j < h_size) {
        a[k] = h_arr[j];
        j++;
        k++;
    }

}

void _merge_sort(int a[], int low, int high){
    int middle;
    if (low < high) {
        middle = low + (high - low)/2;
        _merge_sort(a, low, middle);
        _merge_sort(a, middle + 1, high);
        _merge(a, low, middle, high);
    }
}
void merge_sort(int a[], int n){
    _merge_sort(a, 0, n - 1);
}

int main(int argc, char* argv[]){
    int a[] = {9, 12, 4, 7, 3, 0, 1, 8};
    int n = sizeof(a) / sizeof(a[0]);
    print_array(a, n);
    // selection_sort(a, n);
    // insertion_sort(a, n);
    // interchange_sort(a, n);
    // bubble_sort(a, n);
    // shaker_sort(a, n);
    // quick_sort(a, n);
    // shell_sort(a, n);
    merge_sort(a, n);
    print_array(a, n);
    return 0;
}