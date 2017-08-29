#include <stdio.h>

int main() {
    // bir degiskeni silsek bile onun adres degerine sahipsek degiskeni adres degerinden de cagirabiliriz. adli islemlerde
    // silinen harddisklerdeki verilerin incelenmesinde de pointer'lar kullanilarak veriler okunabilir.
    // degiskenin adresini %p placeholder'i ve degiskenin basina & isareti ekleyerek ogrenebiliriz.
    int a = 50;
    printf("A degiskeninin bellekteki adresi: %p\n", &a);
    
    // pointer'lar ayri bir degisken olarak da tanimlanabilir.
    char c = 'c';
    char* g = &c;
    printf("C degiskeninin bellekteki adresi: %p\n", g);
    printf("Pointer'in adresi: %p\n", &g);
    
    int b = 14;
    int *p = &b;
    printf("B'nin degeri: %d\n", b);
    // bu atama ile b degiskeninin degerini degistirebiliriz.
    *p = 99;
    printf("B'nin degeri: %d\n", b);
    
    double d = 14.4;
    double* g01 = &d;
    double* g02 = &d;
    printf("Pointer1: %lf\n", *g01);
    printf("Pointer2: %lf\n", *g02);
    *g01 = 52.20;
    printf("Pointer1 degistirildikten sonra Pointer2: %lf\n", *g02);
    
    return 0;
}
