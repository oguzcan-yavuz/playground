/* Kullanıcıdan bir çift sayı girmesini isteyiniz.Kullanıcı eğer çift sayı girmişşse ekrana “Çift
sayı girdiniz : sayi “ şeklinde gösteriniz.Eğer tek sayı girdiyse “Hata ! Tek sayı girdiniz.” şeklinde
ekrana değer döndüren programı yazınız. */

#include <stdio.h>

int main() {
    
    int sayi;
    printf("Lutfen bir cift sayi giriniz...\n");
    scanf("%d", &sayi);
    
    if(sayi % 2 == 0) {
        printf("Cift sayi girdiniz: %d\n", sayi);
    } else {
        printf("Hata! Tek sayi girdiniz.\n");
    }
    
    return 0;
    
}