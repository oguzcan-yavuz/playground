/*Soru: Ekrana rastgele 15 tane sayi yazdiran programi kodlayiniz. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    
    int sayi = time(NULL);
    
    srand(sayi);
    
    for(int i = 0; i < 15; i++) {
        printf("%d\n", rand() % 49 + 1);
    }
    return 0;
}
