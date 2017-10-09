#include <stdio.h>

float hesap_kitap(int x, int y) {
    return (x + y) / 2.0;
}

void topla(int x, float y) {
    printf("x + y: %.3f\n", x + y);
}

void cikar(int x, float y) {
    printf("x - y: %.3f\n", x - y);
}

void carp(int x, float y) {
    printf("x * y: %.3f\n", x * y);
}

int main() {
    float (*p)(int, int);   // fonk. argumanlari iki tane int olan bir fonk. pointeri.
    p = hesap_kitap;        // fonk.u pointer'a atarken parantez koyma.
                            // parantez koymak fonksiyonu cagirir.
    printf("sonuc: %.3f\n", p(10, 3));

    // veri yapisi olusturmak icin typedef kullanim ornegi
    typedef int tamsayi[10];   // int tipinden, tamsayi adinda yeni bir veri yapisi olusturduk
    tamsayi a;         // int a[10]; yerine tamsayi a; yaziyoruz.
    a[0] = 13;
    printf("typedef: %d\n", a[0]);

    // fonksiyonlari diziden cagirmak
    typedef void (*FI)(int, float);     // FI adli yeni bir veri yapisi tanimlar
                                //  (fonksiyon pointerini veri yapisi haline getirdik)
    FI fonklar[3] = {topla, cikar, carp};   // FI yapisindan bir dizi olusturup
                                            // fonksiyonlari icine yerlestirdik.
    fonklar[0](5, 10.5);
    fonklar[1](5, 10.5);
    fonklar[2](5, 10.5);

    return 0;
}
