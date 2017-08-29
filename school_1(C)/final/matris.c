/* Uc satir, dort sutundan olusan bir matrisi matris[i][j] dizisine yazan ve diziden okudugu degerleri ekrana
matris formunda yazan main programini kodlayiniz. Not: Matrisin her bir elemaninin degeri 2i+3j olarak hesaplanacak. */

#include <stdio.h>

int main() {
    
    int matris[3][4];
    int i, j, k, l;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 4; j++) {
            matris[i][j] = (2 * i) + (3 * j);
        }
    }
    
    // ekrana yazdirma
    for(k = 0; k < 3; k++) {
        for(l = 0; l < 4; l++) {
            printf("%d\t", matris[k][l]);
        }
        printf("\n");
    }
    
    return 0;
}
