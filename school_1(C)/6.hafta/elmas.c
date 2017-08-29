/* Klavyeden girilen bir sayi girildikten sonra girilen sayi kadar yildizlarla elmas yapan programi yaziniz. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    // sayiyi kullanicidan alir
    int n;
    // printf("Sayi veriniz.\n");
    // scanf("%d", &n);
    
    // sayiyi calistirma komutunun yanina girilen ilk parametre olarak alir
    n = atoi(argv[1]);
    
    int bir = n - 1;
    int iki = n - 1;
    int uc = 1;
    
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < bir; i++) {
            printf("-");
        }
        
        for(int l = 0; l < uc; l++) {
            printf("*");
        }
        for(int j = 0; j < iki; j++) {
            printf("-");
        }
        
        printf("\n");
        bir -= 1;
        iki -= 1;
        uc += 2;
    }
    
    int birb = 1;
    int ikib = 1;
    int ucb = (n * 2) - 3;
    
    for(int m = 0; m < n; m++) {
        
        
        for(int i = 0; i < birb; i++) {
            printf("-");
        }
        
        for(int l = 0; l < ucb; l++) {
            printf("*");
        }
        for(int j = 0; j < ikib; j++) {
            printf("-");
        }
        
        printf("\n");
        birb += 1;
        ikib += 1;
        ucb -= 2;
    }
    
    return 0;
}
