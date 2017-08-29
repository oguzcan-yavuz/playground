#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int n[2][5] = {
        {3, 5, 1, 2, 4},
        {1, 5}
    };
    // int *dizi = malloc(n * sizeof(int));         // n * sizeof(int)(4 BYTES) boyutunda, pointer kullanarak diziye heap RAM'de yer ayirir.
    // int dizi[] = {0, 0, 0};                      // integer boyutunda dizi acmak (4 BYTES)
    // int dizi[][] = {{5}, {3}, {7}};              // iki boyutlu dizi
    
    // printf("Dizinin boyutu: %lu BYTES\n", n * sizeof(int));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 5; j++)
            printf("eleman: %d\n", n[i][j]);
    }
    return 0;
}
