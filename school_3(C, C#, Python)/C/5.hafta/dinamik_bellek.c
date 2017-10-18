#include <stdio.h>
#include <stdlib.h>

void check_malloc(int *p) {
    if(p == NULL) {
        printf("Bellek alinamadi!\n");
        exit(1);
    }
}

void free_null(int *p) {
    free(p);
    p = NULL;
}

int main() {
    // int *a = (int*)malloc(sizeof(int) * 100000000000000); maksimum bellek miktarini astigimizda check_malloc fonksiyonu exit(1)' i cagiriyor.
    int *a = (int *) malloc(sizeof(int) * 3);
    check_malloc(a);
    int *b = a + 1;     // (a ya verilen adresin 4 byte sonrasini b'ye veriyoruz. + 1 yaparsak pointer'in tipi int oldugu icin 4 byte atlar.)
    int *c = b + 1;     // (b ye verilen adresin 4 byte sonrasini c'ye veriyoruz.)
    *a = 5;
    *b = 10;
    *c = (*a) + (*b);

    printf("a: %d\na adres: %p\nb: %d\nb adres: %p\nsonuc: %d\nc adres: %p\n", *a, a, *b, b, *c, c);
    free_null(a);

    return 0;
}
