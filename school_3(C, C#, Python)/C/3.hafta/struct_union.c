// 8 bitlik bir sayi olusturan ve bitlerini ekrana yazdiran program.

#include <stdio.h>
#include <stdlib.h>

union {
    unsigned int butun;
    struct {
        unsigned char b0;          // :1 seklinde belirttigimiz kisim ile bit sayisini belirtebiliyoruz.
        unsigned char b1;
        unsigned char b2;
        unsigned char b3;
    } bytlar;
} tamsayi;



union {     // bitler ile butun degiskenleri ayni yeri paylastigindan, butun degiskenini
            // degistirdigimizde struct'umuz da ayni sekilde degisecek, struct'umuzu bitlere
            // boldugumuz icin degisen sayinin bitlerini gormus olacagiz.
    unsigned char butun;
    struct {
        unsigned char b0:1;          // :1 seklinde belirttigimiz kisim ile bit sayisini belirtebiliyoruz.
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
    } bitler;
} sayi;

int main() {
    sayi.butun = 15;
    printf("sayi: %d\n", sayi.butun);

    printf("%d %d %d %d %d %d %d %d\n",
        sayi.bitler.b7,
        sayi.bitler.b6,
        sayi.bitler.b5,
        sayi.bitler.b4,
        sayi.bitler.b3,
        sayi.bitler.b2,
        sayi.bitler.b1,
        sayi.bitler.b0
    );
    sayi.bitler.b0 = 0;
    sayi.bitler.b7 = 1;

    printf("sayi: %d\n", sayi.butun);
    printf("%d %d %d %d %d %d %d %d\n",
        sayi.bitler.b7,
        sayi.bitler.b6,
        sayi.bitler.b5,
        sayi.bitler.b4,
        sayi.bitler.b3,
        sayi.bitler.b2,
        sayi.bitler.b1,
        sayi.bitler.b0
    );

    tamsayi.butun = 255;
    printf("sayi: %d\n", tamsayi.butun);
    printf("%d %d %d %d\n",
        tamsayi.bytlar.b3,
        tamsayi.bytlar.b2,
        tamsayi.bytlar.b1,
        tamsayi.bytlar.b0
    );

    tamsayi.butun = 258;
    printf("sayi: %d\n", tamsayi.butun);
    printf("%d %d %d %d\n",
        tamsayi.bytlar.b3,
        tamsayi.bytlar.b2,
        tamsayi.bytlar.b1,
        tamsayi.bytlar.b0
    );

    tamsayi.butun = 2017;
    printf("sayi: %d\n", tamsayi.butun);
    printf("%d %d %d %d\n",
        tamsayi.bytlar.b3,
        tamsayi.bytlar.b2,
        tamsayi.bytlar.b1,
        tamsayi.bytlar.b0
    );
    return 0;
}
