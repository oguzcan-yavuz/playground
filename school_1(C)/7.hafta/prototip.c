#include <stdio.h>
int topla(int, int);

int main() {
    
    int toplam = 0;
    toplam = topla(3, 4);
    printf("%d\n", toplam);
    
    return 0;
}

int topla(int a, int b) {
    return a + b;
}
