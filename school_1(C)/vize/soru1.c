// Kullanıcıdan alınan sayıyı her satırda ekrana birer birer eksilterek yazan programı yapınız.

#include <stdio.h>

int main() {
    
    int sayi;
    
    printf("Bir sayi giriniz...\n");
    scanf("%d", &sayi);
    
    while(sayi > 0) {
        printf("%d\n", sayi);
        sayi--;
    }
    
    return 0;
}
