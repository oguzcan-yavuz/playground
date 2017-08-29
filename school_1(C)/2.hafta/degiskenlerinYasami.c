#include <stdio.h>

int main() {
    int uzunYasam = 2;
    
    // yeni bir blok actigimizda, bu blogun icerisindeki degiskenler, bu blogun disinda kullanilamaz.
    {
        int kisaYasam = 7;
        uzunYasam = 3;
        
        printf("kisa yasamli degisken: %d\n", kisaYasam);
        printf("uzun yasamli degisken: %d\n", uzunYasam);
    }
    
    // kisaYasam degiskeninin ait oldugu bloktan ciktigimiz icin degiskeni bulamayacaktir.
    printf("kisa yasamli degisken: %d\n", kisaYasam); 
    printf("uzun yasamli degisken: %d\n", uzunYasam);
    
    return 0;
}
