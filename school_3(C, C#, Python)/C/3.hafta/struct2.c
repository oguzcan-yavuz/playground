#include <stdio.h>
#include <stdlib.h>

// eger bunu bir veri yapisi haline getirip birden fazla kez kullanmak istiyorsak, degisken
// adini struct keyword'unden sonra yazmamiz gerek.
typedef struct {
    unsigned char gun;
    unsigned char ay;
    unsigned short int yil;
} tarih_t;  // eger degisken adi blogun sonuna yazilirsa, tarih adinda bir degiskeni tanimlar.
            // typedef ile tanimlarsak degisken tanimlanmaz.

/*struct tarih dogum;    Typedef: eger bastaki struct keywordu olmadan direk "tarih dogum" olarak
                         tanimlamak istersek typedef kullaniriz.*/
tarih_t dogum;

int main(int argc, char *argv[]) {
    dogum.gun = 10;
    dogum.ay = 5;
    dogum.yil = 2017;

    printf("struct'un bellekte kapladigi alan: %d byte\n", sizeof(tarih_t));
    printf("gun: %d\nay: %d\nyil: %d\n", dogum.gun, dogum.ay, dogum.yil);

    return 0;
}
