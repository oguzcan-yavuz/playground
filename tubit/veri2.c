#include <stdio.h>
#include <stdlib.h>

int *arr;
int size, capacity;

void initialize() {
    size = 0;
    capacity = 5;
    arr = (int*) malloc(capacity * sizeof(int));
}

void add(int value) {
    if(size < capacity) {
        arr[size] = value;
        size += 1;
    } else {
        capacity *= 2;
        arr = realloc(arr, capacity * sizeof(int));
        add(value);
    }
}

int main() {
    initialize();
    
    for(int i = 0; i < 20; i++) {
        add(i);
    }
    
    printf("Array start: %p, size: %d, capacity: %d\n", arr, size, capacity);
    printf("Array[0]: %d\n", arr[0]);
    return 0;
}