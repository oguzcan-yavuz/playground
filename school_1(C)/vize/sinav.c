#include <stdio.h>

int main() {
    
    int ondalik, ikilik = 0;
    printf("0-255 arasi bir sayi giriniz.\n");
    scanf("%d", &ondalik);
    
    if(ondalik >= 128) {
        ikilik += 10000000;
        ondalik -= 128;
    }
    if(ondalik >= 64) {
        ikilik += 1000000;
        ondalik -= 64;
    }
    if(ondalik >= 32) {
        ikilik += 100000;
        ondalik -= 32;
    }
    if(ondalik >= 16) {
        ikilik += 10000;
        ondalik -= 16;
    }
    if(ondalik >= 8) {
        ikilik += 1000;
        ondalik -= 8;
    }
    if(ondalik >= 4) {
        ikilik += 100;
        ondalik -= 4;
    }
    if(ondalik >= 2) {
        ikilik += 10;
        ondalik -= 2;
    }
    if(ondalik >= 1) {
        ikilik += 1;
        ondalik -= 1;
    }
    printf("Sonuc: %08d\n", ikilik);
    return 0;
    
}
