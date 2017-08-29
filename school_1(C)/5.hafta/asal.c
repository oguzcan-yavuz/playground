// ekrandan girilen sayi degerinin kac oldugunu ve asal sayi olup olmadigini, olmadiysa nedenini ekrana yazdiran programi yaziniz...

#include <stdio.h>

int main() {
    
    int sayi;
    int index = 2;
    printf("Sayi giriniz...\n");
    scanf("%d", &sayi);

    if(sayi < 0) {
        printf("pozitif bir sayi girmelisiniz...\n");
        return 0;
    }
    
    while(sayi / 2 >= index) {
        if (sayi % index == 0) { 
            // sayinin asal olmadigi durumda kullanicidan yeni bir deger isteniyor
            printf("%d, %d sayisina bolunebildigi icin asal sayi degildir\n", sayi, index);
            scanf("%d", &sayi);
            return 0;
        }
        index++;
    }
    
    printf("%d bir asal sayidir\n", sayi);
    return 0;
    
}
