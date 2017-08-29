#include <stdio.h>
#include <stdlib.h>

// O(n) ==> n = length
int linear_search(int value, int* arr, int length){
    for(int i = 0; i < length; i++)
        if(arr[i] == value)
            return 1;
    return 0;
}

// O(logn) ==> n = length
int binary_search(int value, int* arr, int length){
    int low = 0, high = length;

    while(low <= high){
        int mid = low + ((high - low) / 2);

        if(arr[mid] == value)
            return 1;
        else if(arr[mid] < value)
            low = mid + 1;
        else if(arr[mid] > value)
            high = mid - 1;
    }

    return 0;
}

void swap(int *arr, int i, int j){
    if(i == j) return;
    int temp = arr[i];

    arr[i] = arr[j];
    arr[j] = temp;
}

int getMin(int *arr, int length){
    int min = 0;

    for(int i = 1; i < length; i++)
        if(arr[min] > arr[i])
            min = i;

    return min;
}

void bubble_sort(int *arr, int length){
    for(int i = 0; i < length; i++)
        for(int j = i + 1; j < length; j++)
            if(arr[i] > arr[j])
                swap(arr, i, j);
}

void selection_sort(int *arr, int length){
    int current = 0;

    while(current < length){
        int min = getMin(&arr[current], length - current);

        swap(arr, current, current + min);
        current += 1;
    }
}

void quick_sort(int *arr, int length){
    if(length <= 0) return;

    int pivot = arr[length - 1], wall = 0;

    for(int i = 0; i < length - 1; i++)
        if(pivot > arr[i]) {
            swap(arr, wall, i);
            wall += 1;
        }

    swap(arr, wall, length - 1);
    // Sağ taraf için aynı işlemi yap.
    quick_sort(arr + wall + 1, length - wall - 1);
    // Sol taraf için aynı işlemi yap.
    quick_sort(arr, wall);
}

void print_array(int *arr, int length){
    for(int i = 0; i < length; i++)
        printf("%d\n", arr[i]);
}

int main() {
    int array[5] = {15, 10, 53, 35, 92};
    int length = sizeof(array) / sizeof(array[0]);

    quick_sort(array, length);
    int result = binary_search(35, array, length);

    printf("Sonuç: %d\n", result);
    print_array(array, length);
    
    return 0;
}
