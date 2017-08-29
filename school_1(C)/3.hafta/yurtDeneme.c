#include <stdio.h>

int main(){
    
    int sayi=0,toplam=0;
    printf("4 basamaklı bir sayı giriniz:\n");
    scanf("%d",&sayi);
    
    toplam += sayi % 10;
    sayi /= 10;
    toplam += sayi % 10;
    sayi /= 10;
    toplam += sayi % 10;
    sayi /= 10;
    toplam += sayi % 10;
    sayi /= 10;
    
    printf("Basamakların toplam değeri : %d\n",toplam);
    return 0;
}