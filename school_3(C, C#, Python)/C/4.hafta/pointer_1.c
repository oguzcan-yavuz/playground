#include <stdio.h>

int main() {
    int i = 10;
    int *p = &i;
    printf("i degiskeninin degeri: %d\n", *p);
    printf("i degiskeninin adresi: %p\n", p);

    *p = 20;
    printf("i degiskeninin degeri: %d\n", i);
    printf("i degiskeninin adresi: %p\n", p);
    return 0;
}
