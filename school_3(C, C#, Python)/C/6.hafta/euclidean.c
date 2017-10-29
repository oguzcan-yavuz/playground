#include <stdio.h>

int recursive_euclidean(int x, int y) {
    return (x == 0) ? y : (y == 0) ? x : recursive_euclidean(y, x % y);
}

int iterative_euclidean(int x, int y) {
    int swap;
    while(x != 0 && y != 0) {
        swap = x;
        x = y;
        y = swap % y;
    }
    return (x == 0) ? y : x;
}

int main() {
    int a, b;
    printf("Iki deger giriniz.\n");
    scanf("%d%d", &a, &b);
    printf("Recursive OBEB: %d\n", recursive_euclidean(a, b));
    printf("Iterative OBEB: %d\n", iterative_euclidean(a, b));
    return 0;
}
