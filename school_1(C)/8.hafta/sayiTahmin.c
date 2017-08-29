#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int tahmin = 0;
    int sayac = 1;
    int random;
    int puan = 50;
    
    srand(time(NULL));
    random = rand() % 100 + 1;
    
    printf("1-100 arasi bir sayi tuttum. Tahmin et! Cikmak icin -1 gir.\n");
    
    while(tahmin != -1) {
        
        scanf("%d", &tahmin);
        
        if(tahmin == -1) {
            printf("Oyundan cikiliyor...\n");
            break;
        }
        
        if(tahmin < 1 || tahmin > 100) {
            printf("Tahminin 1 ve 100 arasinda olmali.\n");
            puan -= 5;
            sayac++;
        } else {
            if(tahmin == random) {
                printf("Tebrikler. Sayiyi %d. denemede bildin. Sayi: %d. Puan: %d\n", sayac, random, puan);
                break;
            } else if(tahmin < random) {
                printf("Kucuk bir sayi girdin. Tekrar dene!\n");
                sayac++;
                puan -= 5;
            } else {
                printf("Buyuk bir sayi girdin. Tekrar dene!\n");
                sayac++;
                puan -= 5;
            }
        }
        
    }
    return 0;
}
