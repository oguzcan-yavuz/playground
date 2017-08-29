/* Fibonacci serisini ekrana yazdiran programi yaziniz. */

#include <stdio.h>

int main() {
    
    int n, aktif = 1, aktif1 = 1;
    
    printf("Kacinci eleman bulunacak?\n");
    scanf("%d", &n);
    printf("%d\n%d\n", aktif, aktif1);
    int sonuc;
    
    for(int i = 0; i < n - 2; i++) {
        sonuc = aktif + aktif1;
        printf("%d\n", sonuc);
        aktif = aktif1;
        aktif1 = sonuc;
    }
    
    return 0;

}
