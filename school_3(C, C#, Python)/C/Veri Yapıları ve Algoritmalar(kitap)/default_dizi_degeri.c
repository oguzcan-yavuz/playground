#include <stdio.h>

void print_array(int *arr, int length) {
    for(int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int x[10];
    int y[10] = {1, 2, 3, 0};      // dizinin elemanlarina default olarak \0 degerini atar.
                                   // 0 sayisi, C dilinde NULL olarak kabul edilir.
    print_array(x, sizeof(x) / sizeof(int));
    print_array(&y[0], sizeof(y) / sizeof(int));
    return 0;
}
