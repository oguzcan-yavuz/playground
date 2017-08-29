#include <stdio.h>

int main() {
    int sayi=5644;
    
    int birler = sayi %10;
    sayi=sayi/10;
    int onlar = sayi %10;
    sayi/=10;
    int yuzler= sayi%10;
    sayi /= 10;
    int binler=sayi;
    
    int toplam=birler+onlar+yuzler+binler;
    printf("Sayilarin toplami:%d\n",toplam);
    
    return 0;
    
    
}