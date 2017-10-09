#include <stdio.h>

int main() {
    int i, *p, **q;
    i = 5;
    p = &i;
    q = &p;

    printf("i adres: %p\n", &i);
    printf("i adres: %p\n", p);
    printf("p adres: %p\n", &p);
    printf("p adres: %p\n", q);
    printf("q adres: %p\n", &q);
    printf("i degeri: %d\n", **q);
    **q = 10;
    printf("i degeri: %d\n", **q);

    return 0;
}
