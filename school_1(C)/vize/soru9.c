/* Soru – 9 Ekrandan girilen sayının faktöriyelini hesaplayan programı yazınız. */

#include <stdio.h>

int main() {
    
    int sayi, res = 1;
    printf("Bir sayi giriniz.\n");
    scanf("%d", &sayi);
    
    while(sayi > 0) {
        res *= sayi;
        sayi--;
    }
    printf("Sonuc: %d\n", res);
    return 0;
}