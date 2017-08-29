// Kullanıcının 3 adet float türünden sayı girdiği ve bu sayıların kendisinin karesinin ve küpünün ekrana yazdırıldığı programı yazınız.

#include <stdio.h>

int main() {
    
    // degiskenlerimizi tanimliyoruz
    float sayi1, sayi2, sayi3;
    
    // kullanicidan uc tane sayi girmesini istiyoruz
    printf("Uc tane sayi giriniz...\n");
    // kullanicinin girdigi uc sayiyi degiskenlere atiyoruz
    scanf("%f%f%f", &sayi1, &sayi2, &sayi3);
    
    // sayilarin karelerini ve kuplerini ekrana yazdiriyoruz
    printf("Sayilar\t\tKareleri\tKupleri\n");
    printf("%.2f\t\t%f\t%f\n", sayi1, sayi1 * sayi1, sayi1 * sayi1 * sayi1);
    printf("%.2f\t\t%f\t%f\n", sayi2, sayi2 * sayi2, sayi2 * sayi2 * sayi2);
    printf("%.2f\t\t%f\t%f\n", sayi3, sayi3 * sayi3, sayi3 * sayi3 * sayi3);
    
    return 0;
}
