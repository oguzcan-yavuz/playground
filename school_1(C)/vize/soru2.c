/* Bir hafta boyunca her gün okuduğu sayfa sayısını ekrana giren kullanıcının bir hafta
sonunda kaç sayfa kitap okuduğunu ve günde ortalama kaç sayfa kitap okuduğunu hesaplayan
programı yapınız. */

#include <stdio.h>

int main() {
    
    int toplam = 0, kitap = 0;
    
    for(int gun = 1; gun < 8; gun++) {
        printf("%d .gun icin okudugunuz kitap sayisini giriniz.\n", gun);
        scanf("%d", &kitap);
        toplam += kitap;
    }
    printf("Hafta sonunda okudugunuz toplam kitap sayisi: %d\n", toplam);
    printf("Gunde ortalama okudugunuz kitap sayisi: %d\n", toplam / 7);
    return 0;
}