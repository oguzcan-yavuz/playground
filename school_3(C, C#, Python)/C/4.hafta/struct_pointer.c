#include <stdio.h>
#include <string.h>

typedef struct _kayit_t {
    int a;
    int b;
    float puan;
} kayit_t;


int main() {
    kayit_t kayitlar;
    kayitlar.puan = 12.53;
    kayit_t *pkayit;
    pkayit = &kayitlar;
    pkayit -> a = 10;
    pkayit -> b = 20;
    printf("struct adresi: %p\n", pkayit);
    printf("struct'un boyutu: %d\n", sizeof(kayit_t), sizeof(kayit_t));
    printf("a: %d\nb: %d\npuan: %f\n", pkayit -> a, pkayit -> b, pkayit -> puan);

    pkayit++;
    printf("struct adresi: %p\n", pkayit);
    printf("struct'un boyutu: %d\n", sizeof(kayit_t), sizeof(kayit_t));
    printf("a: %d\nb: %d\npuan: %f\n", pkayit -> a, pkayit -> b, pkayit -> puan);

    return 0;
}
