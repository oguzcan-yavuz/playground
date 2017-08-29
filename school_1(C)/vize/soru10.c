/* Bir memur, ATM makinasından para çekmek istemektedir. Makinede sadece 10, 20, 50 ve
100 TL' lik banknotlar kalmıştır. Büyük değerli banknotların sayısı maksimum olacak şekilde,
çekilecek paranın kaç tane 100, 50, 20 ve 10 liralık banknottan oluşacağını ekranda yazan C
programını yazınız. */

#include <stdio.h>

int main() {
    
    int yuz = 0, elli = 0, yirmi = 0, on = 0, para;
    printf("Cekmek istediginiz para miktarini giriniz...\n");
    scanf("%d", &para);
    
    while(para >= 100) {
        para -= 100;
        yuz++;
    }
    while(para >= 50) {
        para -= 50;
        elli++;
    }
    while(para >= 20) {
        para -= 20;
        yirmi++;
    }
    while(para >= 10) {
        para -= 10;
        on++;
    }
    
    printf("Yuzluk: %d\tEllilik: %d\tYirmilik: %d\tOnluk: %d\tBirlik: %d\n", yuz, elli, yirmi, on, para);
    return 0;
}