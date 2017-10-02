#include <stdio.h>
#include <stdlib.h>

int main() {
    // bir sayinin ucuncu bitinin degerini bulan program.
    // NOT: bitleri saymaya 0'dan basliyoruz.
    int a = 6;
    printf((a & 8) ? "ucuncu bit: 1\n" : "ucuncu bit: 0\n");
    printf((a & 0x10000) ? "17. bit: 1\n" : "17. bit: 0\n");

    // x sayisinin diger bitlerini degistirmeden 5.bitini 1 yapan program.
    int x = 30;
    printf("x: %d\n", x | 0x20);    // 0x20 (16'lik) => 32(2'lik)

    // y sayisinin diger bitlerini hic degistirmeden 2.bitini 0 yapan program.
    int y = 6;
    printf("y: %d\n", y & (~0x4));

    return 0;
}
