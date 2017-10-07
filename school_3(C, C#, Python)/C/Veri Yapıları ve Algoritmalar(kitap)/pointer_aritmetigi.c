#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;
    int n = 2;
    printf("gercek adres degeri: %p\n", p);     // orijinal adres
    p++;        // p = p + sizeof(p);
    printf("bir arttirdiktan sonraki degeri: %p\n", p);   // 4 byte(int) sonraki adres
    p += n;     // p = p + (n * sizeof(p));
    printf("n arttirdiktan sonraki degeri: %p\n", p);   // 2(n) * 4(int) = 8 byte sonrasi
    return 0;
}
