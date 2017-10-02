#include <stdio.h>
#include <stdlib.h>

union {
    unsigned char gun;
    unsigned char ay;
    unsigned short int yil;
} tarih;



int main(int argc, char *argv[]) {

    tarih.gun = 15;
    tarih.ay = 8;
    tarih.yil = 1921;   // gun ve ayin yazildigi 8 bitlik kisim, 1921 sayisi icin 129 seklinde
                        // ikilik tabanda yazildigi icin, gun ve ay degerleri 129 degerini veriyor.

    // -------- (8bit) | -------- (8bit)
    //                          gun
    //                          ay
    //                yil

    printf("union'un bellekte kapladigi alan: %d byte\n", sizeof(tarih));
    printf("gun: %d\nay: %d\nyil: %d\n", tarih.gun, tarih.ay, tarih.yil);
    return 0;
}
