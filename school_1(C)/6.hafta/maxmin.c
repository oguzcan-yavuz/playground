/* Ekrandan girilecek int turu sayilar arasindan en buyuk ve en kucugunu bulup ekrana yazdiran C kodunu yaziniz. */

#include <stdio.h>

int main() {
    
    // kullanicidan deger iste
    printf("Sayilari giriniz. Cikmak icin -1 giriniz.\n");
    
    // degiskenler
    double max, n, min;
    
    // kullanicidan sayiyi aliyoruz ve n degiskenine atiyoruz
    scanf("%lf", &n);
    
    // eger n, -1 degerine esitse
    if(n == -1) {
        // donguden cik
        return 0;
    }
    
    // n degiskenini max ve min degiskenleriyle esitliyoruz
    min = n;
    max = n;
    
    // sonsuz dongudeyken
    while(n != -1) {
        // girilen diger sayilari da okuyoruz.
        scanf("%lf", &n);
        
        // eger n, max degerinden buyukse
        if(n > max && n != -1) {
            // max degerini yeni n degerine esitle
            max = n;
        }
        
        // eger n, min degerinden kucukse
        if(n < min && n != -1) {
            // min degerini yeni n degerine esitle
            min = n;
        }
        
        // eger n, -1 degerine esitse
        if(n == -1) {
            // donguden cik
            break;
        }
    }
    
    // max ve min degerlerini ekrana yazdir
    printf("Max sayi: %.0lf\n", max);
    printf("Min sayi: %.0lf\n", min);
    
    return 0;
}
