/* Ekrandan girilen en boy degerleriyle dikdortgen cizimi yapan programi yaziniz. */

/* NOT: Verilen ASCII degerleri desteklenmedigi icin yapmadim.*/

#include <stdio.h>

int main() {
    
    int en, boy;
    printf("Eni ve boyu giriniz.\n");
    scanf("%d%d", &en, &boy);
    
    printf("%c", 218);
    for(int i = 0; i < en; i++) {
        printf("%c", 196);
    }
    
    return 0;
}