#include <stdio.h>
#include <math.h>

float cakma_log(int a, int b) {
    return log(b) / log(a);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("Sonuc: %f\n", cakma_log(a, b));
    return 0;
}
