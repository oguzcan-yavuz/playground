#include "DoubleLinkedList.h"

int main() {
    sona_ekle(62);
    sona_ekle(57);
    sona_ekle(41);
    sona_ekle(53);
    sona_ekle(5);
    araya_ekle(2, 7);
    listele();
    printf("Degistiriliyor...\n");
    degistir(62, 5);
    listele();
    yok_et();
    printf("Listeleniyor...\n");
    listele();
    // araya_ekle(77, 2);
    // listele();
    // sil(77);
    // listele();
    // sil(3);
    // listele();
    // sil(5);
    // listele();
    // sil(62);
    // listele();
    // sil(57);
    // listele();
    // printf("Toplam node sayisi: %d\n", say());
    // sil(41);
    // listele();
    // sil(53);
    // listele();
    // printf("Toplam node sayisi: %d\n", say());
    return 0;
}

