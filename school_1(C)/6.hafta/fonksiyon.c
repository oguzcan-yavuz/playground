#include <stdio.h>

int topla(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    printf("Toplamak istediginiz degerleri giriniz.\n");
    scanf("%d%d", &a, &b);
    
    printf("%d\n", topla(a, b));
    return 0;
}
