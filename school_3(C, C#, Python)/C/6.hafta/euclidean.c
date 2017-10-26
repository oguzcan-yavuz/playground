#include <stdio.h>

int euclidean(int x, int y) {
    return (x == 0) ? y : (y == 0) ? x : euclidean(y, x % y);
}

int main() {
    int a, b;
    printf("Iki deger giriniz.\n");
    scanf("%d%d", &a, &b);
    printf("OBEB: %d\n", euclidean(a, b));
    return 0;
}
