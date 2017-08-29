/* Zamaninda bir kral satranc oyununu cok seviyormus ve bunu bulan bir kisi varmis. Bu kisiye kral odul olarak altin vermek istemis. Satranci
bulan kisi: satranc tahtasinin her bir karesi icin 1 tane olmak kaydiyla her bir kare icin 2 kat artacak kadar altin istemis. Kac altin? */

#include <stdio.h>

int main() {
    
    double toplam = 1;
    double sonuc = 0;
    
    printf("1. asama = Sonuc: 1\n");
    
    for(int i = 1; i < 64; i++) {
        toplam *= 2;
        printf("%d. asama = Sonuc: %.0f\n", i + 1, toplam);
        sonuc += toplam;
    }
    
    printf("Sonuc: %.0f\n", sonuc);
    
    return 0;
}
