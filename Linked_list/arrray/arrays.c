#include "arrays.h"

//*************************************************************
// Array of Integers
//*************************************************************
void print_array_of_integers(int __array[], int __size)
{
    int index;
    printf("Array: ");
    for (index = 0; index < __size; index++)
    {
        printf("%d\t", __array[index]);
    }
    printf("\n");
}

void demonstrate_array_of_integers()
{
    int arr[] = {8, 10, 0, 3, 2, 9, 7, 4, 9};
    int size = sizeof(arr) / sizeof(arr[0]); // size = 9
    int keys[] = {11, 8, 3, 4, 9};
    int index = -1;
    print_array_of_integers(arr, size);
    for (int idx = 0; idx < sizeof(keys) / sizeof(keys[0]); idx++)
    {
        index = linear_search(arr, size, keys[idx]);
        // index = sentinel_linear_search(arr, size, keys[idx]);
        // index = binary_search(arr, size, keys[idx]);
        if (index == -1)
        {
            printf("Key = %d is not found!\n", keys[idx]);
        }
        else
        {
            printf("Key = %d is found at index %d of the array.\n", keys[idx], index);
        }
    }
    print_array_of_integers(arr, size);
    // selection_sort(arr, size);
    // interchange_sort(arr, size);
    // bubble_sort(arr, size);
    // insertion_sort(arr, size);
    // shaker_sort(arr, size);
    // shell_sort(arr, size);
    // quick_sort(arr, size);
    merge_sort(arr, size);
    print_array_of_integers(arr, size);
}

//*************************************************************
// Các hàm tìm kiếm trả về số chỉ index từ 0 đến size - 1
// khi có phần tử trong bằng với tham số key
// Ngược lại, trả về -1.
//*************************************************************
int linear_search(int __array[], int __size, int __key)
{
    int index;
    // Duyệt từ phần tử đầu tiên (0) đến phần tử cuối cùng (size - 1)
    for (index = 0; index < __size; index++)
    {
        if (__array[index] == __key)
        {
            return index;
        }
    }
    return -1;
}

int sentinel_linear_search(int __array[], int __size, int __key)
{
    int last = __array[__size - 1];
    // Gán key vào phần tử cuối để làm "lính canh"
    __array[__size - 1] = __key;
    // Duyệt từ phần tử đầu tiên (0) đến khi tìm được key
    int index = 0;
    while (__array[index] != __key)
    {
        index++;
    }
    // Sau khi duyệt mảng xong, gán lại giá trị ban đầu cho phần tử cuối
    __array[__size - 1] = last;
    // Trả về index khi index thuộc [0; size - 2] hoặc giá trị của phần tử cuối = key
    if ((index < __size - 1) || (__array[__size - 1] == __key))
    {
        return index;
    }
    return -1;
}

int binary_search(int __array[], int __size, int __key)
{
    // Đặt low làm chặn dưới, high làm chặn trên
    int low = 0;
    int high = __size - 1;
    // Tính chặn giữa middle sau mỗi lần lặp cho đến khi low > high thì dừng
    int middle;
    while (low <= high)
    {
        middle = (low + high) / 2; // Cách tính 1
        // middle = low + (high - low)/2;   // Cách tính 2
        // Xét phần tử chặn giữa middle với key
        if (__array[middle] == __key)
        { // Tìm được phần tử cần tìm
            return middle;
        }
        else
        {
            if (__array[middle] > __key)
            { // Phần tử cần tìm thuộc nửa dưới
                high = middle - 1;
            }
            else
            { // Phần tử cần tìm thuộc nửa trên
                low = middle + 1;
            }
        }
    }
    return -1;
}

// Selection Sort: Tìm lần lượt phần tử nhỏ nhất trong mỗi lần duyệt và đưa phần tử đó về vị trí đầu của mảng hiện hành.
void selection_sort(int __array[], int __size)
{
    if (__size <= 1)
        return;
    int min_index;
    for (int i = 0; i < __size - 1; i++)
    {
        min_index = i; // số chỉ của phần tử có giá trị nhỏ nhất trong mỗi lần duyệt
        for (int j = i + 1; j < __size; j++)
        {
            if (__array[min_index] > __array[j])
            { // nghịch thế
                min_index = j;
            }
        }
        // Kết thúc mỗi lần duyệt, kiểm tra xem có tìm được phần tử có giá trị nhỏ nhất
        // không phải là phần tử đầu của mảng hiện hành hay không
        if (min_index != i)
        {
            swapInteger(&__array[min_index], &__array[i]);
        }
    }
}

// Interchange Sort: Tương tự Selection Sort
// Nhưng thay vì tìm chỉ số của phần tử có giá trị nhỏ nhất,
// Thuật toán đổi chỗ luôn trong lần duyệt nếu có nghịch thế.
void interchange_sort(int __array[], int __size)
{
    if (__size <= 1)
        return;
    for (int i = 0; i < __size - 1; i++)
    {
        for (int j = i + 1; j < __size; j++)
        {
            if (__array[i] > __array[j])
            { // nghịch thế
                swapInteger(&__array[i], &__array[j]);
            }
        }
    }
}

// Bubble Sort: Duyệt mảng từ phần tử thứ 0 đến size-1
// So sánh hai phần tử kề nhau, nếu nghịch thế thì đổi chỗ.
void bubble_sort(int __array[], int __size)
{
    if (__size <= 1)
        return;
    for (int i = 0; i < __size - 1; i++)
    {
        // Sau mỗi lần duyệt sẽ đẩy được phần tử có giá trị cao nhất về bên phải
        for (int j = 0; j < __size - 1 - i; j++)
        {
            if (__array[j] > __array[j + 1])
            { // nghịch thế
                swapInteger(&__array[j], &__array[j + 1]);
            }
        }
    }
}

// Insertion Sort: Chia mảng thành 2 phần: Phần được sắp xếp bên trái và phần chưa được sắp xếp bên phải.
// Lấy lần lượt từng phần tử từ phần mảng chưa được sắp xếp
// và đặt phần tử đó ở vị trí chính xác trong phần mảng được sắp xếp.
void insertion_sort(int __array[], int __size)
{
    if (__size <= 1)
        return;
    int pos;
    int x;
    // Duyệt phần mảng chưa được sắp xếp
    for (int index = 1; index < __size; index++)
    {
        pos = index;
        x = __array[index];
        // Duyệt phần mảng đã sắp xếp
        // So sánh x lần lượt từ phải sang trái với các phần tử (trước) thuộc phần mảng đả sắp xếp để tìm nghịch thế
        // Nếu nghịch thế thì đổi chỗ
        // Nếu không nghịch thế thì dừng lặp
        while (pos > 0 && __array[pos - 1] > x)
        { // nghịch thế
            __array[pos] = __array[pos - 1];
            pos--;
        }
        __array[pos] = x;
    }
}

// Shaker Sort: Trong một lần duyệt của mảng hiện hành, đưa phần tử nhỏ nhất về bên trái và đưa phần tử lớn nhất về bên phải.
void shaker_sort(int __array[], int __size)
{
    int index, left, right, pivot;
    left = 0;           // Chặn trái
    right = __size - 1; // Chặn phải
    pivot = 0;          // Chặn giữa
    while (left < right)
    {
        // Đưa phần tử lớn về bên phải của dãy hiện hành
        for (index = left; index < right; index++)
        {
            if (__array[index] > __array[index + 1])
            { // nghịch thế
                swapInteger(&__array[index], &__array[index + 1]);
                pivot = index; // Đưa chặn giữa về phía bên phải
            }
        }
        right = pivot;
        // Đưa phần tử nhỏ về bên trái của dãy hiện hành
        for (index = right; index > left; index--)
        {
            if (__array[index - 1] > __array[index])
            { // nghịch thế
                swapInteger(&__array[index - 1], &__array[index]);
                pivot = index; // Đưa chặn giữa về phía bên phải
            }
        }
        left = pivot;
    }
}

// Shell Sort: Cải tiến từ Insertion Sort.
// Chia (đôi) mảng thành nhiều mảng con, với mỗi mảng con các phần tử cách nhau một khoảng h cho đến khi h = 1.
void shell_sort(int __array[], int __size)
{
    if (__size <= 1)
        return;
    int pos; // vị trí bắt đầu so sánh
    int x;   // giá trị cần chèn
    int index;
    int h; // Khoảng cách giữa các phần tử (interval)
    // Duyệt mảng h = {size/2; size/4; ...; 1}
    for (h = __size / 2; h > 0; h /= 2)
    {
        for (index = h; index < __size; index++)
        {
            pos = index;
            x = __array[index];
            while (pos >= h && __array[pos - h] > x)
            { // nghịch thế
                __array[pos] = __array[pos - h];
                pos -= h;
            }
            __array[pos] = x;
        }
    }
}

static void __partition(int a[], int low, int high)
{
    int i, j;
    int pivot = low + (high - low) / 2; // số chỉ trục
    // int pivot = (low + high)/2;
    // int pivot = high;
    // int pivot = low;
    int x = a[pivot]; // phần tử trục
    i = low;          // số chỉ trái
    j = high;         // số chỉ phải
    do
    {
        while (a[i] < x && i < high)
        { // tìm phần tử bên trái lớn hơn trục
            i++;
        }
        while (a[j] > x && j > low)
        { // tìm phần tử bên phải nhỏ hơn trục
            j--;
        }
        if (i <= j)
        {
            swapInteger(&a[i], &a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (low < j)
    {
        __partition(a, low, j);
    }
    if (i < high)
    {
        __partition(a, i, high);
    }
}

// Quick Sort: Chia liên tục mảng thành hai nửa (Phân hoạch)
// Trong mỗi lần phần hoạch: hoán đổi phần tử nhỏ phần bên phải so với trục và phần tử lớn bên trái so với trục.
// Thực hiện phân hoạch liên tục cho đến khi mỗi phân vùng còn lại không quá một phần tử.
void quick_sort(int __array[], int __size)
{
    __partition(__array, 0, __size - 1);
}

static void __merge(int a[], int low, int middle, int high)
{
    int i, j, k;
    int l_size = middle - low + 1;
    int h_size = high - middle;
    int l_arr[l_size];
    int h_arr[h_size];
    for (i = 0; i < l_size; i++)
    {
        l_arr[i] = a[low + i];
    }
    for (j = 0; j < h_size; j++)
    {
        h_arr[j] = a[middle + j + 1];
    }
    i = 0;
    j = 0;
    k = low;
    while (i < l_size && j < h_size)
    {
        if (l_arr[i] <= h_arr[j])
        { // nghịch thế
            a[k] = l_arr[i];
            i++;
        }
        else
        {
            a[k] = h_arr[j];
            j++;
        }
        k++;
    }
    while (i < l_size)
    {
        a[k] = l_arr[i];
        i++;
        k++;
    }
    while (j < h_size)
    {
        a[k] = h_arr[j];
        j++;
        k++;
    }
}
void __merge_sort(int a[], int low, int high)
{
    int middle;
    if (low < high)
    {
        middle = low + (high - low) / 2;
        __merge_sort(a, low, middle);
        __merge_sort(a, middle + 1, high);
        __merge(a, low, middle, high);
    }
}

void merge_sort(int __array[], int __size)
{
    __merge_sort(__array, 0, __size - 1);
}

//*************************************************************
// Dynamic Array of Structs
//*************************************************************
void demonstrate_dynamic_array_of_data()
{
    srand(time(NULL));
    int size = 10; // tổng số lượng phần tử
    __DATA *darr = (__DATA *)malloc(size * sizeof(__DATA));
    if (darr != NULL)
    {
        char text[30];
        int lower = 0;
        int upper = 999;
        int quantity = 0; // số lượng phần tử được nhập thủ công
        int index;
        for (index = 0; index < size - quantity; index++)
        {
            (darr + index)->key = index;
            (darr + index)->number = generateRandomInteger(lower, upper);
            sprintf(text, "Heart A-%03d", generateRandomInteger(lower, upper));
            strcpy((darr + index)->text, text);
        }
        // enter_dynamic_array_of_data(darr, size, quantity);
        print_dynamic_array_of_data(darr, size);
        selection_sort_in_array_of_data(darr, size);
        puts("");
        print_dynamic_array_of_data(darr, size);
        free(darr);
    }
}

void enter_dynamic_array_of_data(__DATA *__array, int __size, int __quantity)
{
    for (int index = __size - __quantity; index < __size; index++)
    {
        (__array + index)->key = index;
        printf("\nAdd the %02d(th) element:\n", (__array + index)->key);
        printf("\t+ Enter a number (000 - 999): ");
        scanf("%d", &(__array + index)->number);
        getchar();
        printf("\t+ Enter a text (0 - 29 characters): ");
        // fgets((darr + index)->text, TEXT_MAX_LENGTH, stdin);
        scanf("%[^\n]s", (__array + index)->text);
    }
}
void print_dynamic_array_of_data(__DATA *__array, int __size)
{
    for (int i = 0; i < __size; i++)
    {
        printf("__DATA[key=%d, number=%d, text=\'%s\']\n",
               (__array + i)->key,
               (__array + i)->number,
               (__array + i)->text);
    }
}

int linear_search_in_array_of_data(__DATA *__array, int __size, char __text[])
{
    for (int index = 0; index < __size; index++)
    {
        if (strcmp((__array + index)->text, __text) == 0)
        {
            return index;
        }
    }
    return -1;
}

static void swap__DATA(__DATA *__this, __DATA *__that)
{
    __DATA temp = *__this;
    *__this = *__that;
    *__that = temp;
}

void selection_sort_in_array_of_data(__DATA *__array, int __size)
{ // sắp xếp theo __text tăng dần
    if (__size <= 1)
        return;
    int min_index;
    for (int i = 0; i < __size - 1; i++)
    {
        min_index = i; // số chỉ của phần tử có giá trị nhỏ nhất trong mỗi lần duyệt
        for (int j = i + 1; j < __size; j++)
        {
            if (strcmp((__array + min_index)->text, (__array + j)->text) > 0)
            { // nghịch thế
                min_index = j;
            }
        }
        // Kết thúc mỗi lần duyệt, kiểm tra xem có tìm được phần tử có giá trị nhỏ nhất
        // không phải là phần tử đầu của mảng hiện hành hay không
        if (min_index != i)
        {
            swap__DATA((__array + min_index), (__array + i));
        }
    }
}