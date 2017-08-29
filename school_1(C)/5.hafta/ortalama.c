/* kullanicinin klavyeden girdigi notlarin ortalamasini bulan program yaziniz. 
fakat kullanici kac adet not girecegini bize bildirmeyecek. kullanici not girmeyi birakirsa ekrana -1 girmesi gerekir.
*/

#include <stdio.h>

int main() {
    // degiskenler
    int i = 1;
    int notlar = 0;
    int toplam = 0;
    
    printf("Notlari giriniz. Eger baska not girmeyecekseniz -1 giriniz...\n");
    
    do {
        // kullanicidan girdi istiyor
        printf("%d. not: ", i);
        scanf("%d", &notlar);
        
        // eger kullanici -1 girerse donguden cikiyor
        if(notlar == -1) {
            break;
        }
        
        // eger kullanici negatif bir deger girerse uyari verip devam ediyor
        if(notlar < 0) {
            printf("Pozitif bir sayi giriniz...\n");
            continue;
        }
        
        // eger kullanici not girdiyse girdigi notu toplam degiskeni ile topluyor
        else {
            toplam += notlar;
        }
        
        // not indexi
        i++;
    } while(notlar != -1);          // kullanici -1 girmedigi surece dongu devam ediyor
    
    // kullanicinin kac not girdigini ve notlarin ortalamasini ekrana yazdiriyor
    printf("%d not girdiniz. Notlarin ortalamasi: %d\n", (i - 1), toplam / (i - 1));
    
    return 0;
}