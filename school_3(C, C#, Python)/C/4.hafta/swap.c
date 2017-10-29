#include <stdio.h>


void swap(int *p, int *q) {
//    int r = *p;
//    *p = *q;
//    *q = r;
    // without third variable
    *p += *q;
    *q = *p - *q;
    *p -= *q;
}


int main() {
    int a = 3, b = 5;
    printf("a = %d\tb = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d\tb = %d\n", a, b);
    return 0;
}
