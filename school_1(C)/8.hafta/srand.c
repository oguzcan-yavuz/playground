#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    
    int sayi = time(NULL);
    
    srand(sayi);
    
    for(int i = 0; i < 5; i++) {
        printf("Sayi: %d\n", rand() % 49 + 1);
    }
    return 0;
}
