/* Kullanıcıdan alınan üç tane partinin oy sayılarıyla birinci olan partiyi , en yakınındaki
rakibine ne kadar fark attığını ve partilerin yüzde kaç oy aldıklarını hesaplayan programı yazınız. */

#include <stdio.h>

int main() {
    
    int a, b, c;
    float oran;
    
    printf("Sirasiyla AP, BP ve CP oylarini giriniz...\n");
    scanf("%d%d%d", &a, &b, &c);
    float toplam = a + b + c;
    oran = 100 / toplam;
    
    if(a > b && a > c) {
        printf("Birinci parti = AP. Oy sayisi = %d\n", a);
        printf("Oylarin yuzde olarak hesabi: %.3f\n", oran * a);
        if(b > c) {
            printf("En yakin rakibine attigi fark: %d\n", a - b);
            printf("Ikinci parti = BP. Oy sayisi = %d\n", b);
            printf("Ucuncu parti = CP. Oy sayisi = %d\n", c);
        } else {
            printf("En yakin rakibine attigi fark: %d\n", a - c);
            printf("Ikinci parti = CP. Oy sayisi = %d\n", c);
            printf("Ucuncu parti = BP. Oy sayisi = %d\n", b);
        }
        
    } else if(b > a && b > c) {
        printf("Birinci parti = BP. Oy sayisi = %d\n", b);
        printf("Oylarin yuzde olarak hesabi: %.3f\n", oran * b);
        if(a > c) {
            printf("En yakin rakibine attigi fark: %d\n", b - a);
            printf("Ikinci parti = AP. Oy sayisi = %d\n", a);
            printf("Ucuncu parti = CP. Oy sayisi = %d\n", c);
        } else {
            printf("En yakin rakibine attigi fark: %d\n", b - c);
            printf("Ikinci parti = CP. Oy sayisi = %d\n", c);
            printf("Ucuncu parti = AP. Oy sayisi = %d\n", a);
        }
    } else if(c > a && c > b) {
        printf("Birinci parti = CP. Oy sayisi = %d\n", c);
        printf("Oylarin yuzde olarak hesabi: %.3f\n", oran * c);
        if(a > b) {
            printf("En yakin rakibine attigi fark: %d\n", c - a);
            printf("Ikinci parti = AP. Oy sayisi = %d\n", a);
            printf("Ucuncu parti = BP. Oy sayisi = %d\n", b);
        } else {
            printf("En yakin rakibine attigi fark: %d\n", c - b);
            printf("Ikinci parti = BP. Oy sayisi = %d\n", b);
            printf("Ucuncu parti = AP. Oy sayisi = %d\n", a);
        }
    }
    return 0;
}