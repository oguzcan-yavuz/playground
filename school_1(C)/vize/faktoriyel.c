#include <stdio.h>

int main() {
    
    int n, sonuc = 1;
    printf("Faktoriyelini almak istediginiz sayiyi giriniz...\n");
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        sonuc *= i;
    }
    
    printf("Sonuc: %d\n", sonuc);
    return 0;
}