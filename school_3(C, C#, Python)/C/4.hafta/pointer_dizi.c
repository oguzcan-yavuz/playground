#include <stdio.h>

int main() {
    int dizi[10];
    int *p;
    p = dizi;       // p = &dizi[0];    (alternatif)
    *(p+3) = 5;     // dizi[3] = 5;     (alternatif)

    p++;
    *p = 3;

    for(int i = 0; i < 10; i++)
        printf("%d ", *(p + i));

    return 0;
}
