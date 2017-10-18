#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_malloc(char *p) {
    if(p == NULL) {
        printf("Bellek ayirilamiyor!");
        exit(1);
    }
}

void print_array(char *p, int length) {
    for(int i = 0; i < length; i++)
        printf("%c ", p[i]);
    printf("\n");
}

int main() {
    // memcpy = kaynak pointer'in 0.adresinden istenilen adrese kadar, kaynak pointer'daki verileri hedef pointer'a yazar.
    char *sp = (char *) malloc(sizeof(char) * 10);    // 10byte'lik yer ayir.
    check_malloc(sp);
    char *dp = (char *) malloc(10);     // sizeof(char) = 1 oldugu icin burada yazmadim.
    check_malloc(dp);

    memset(sp, '*', 10);
    memcpy(dp, sp, 5);

    printf("Source array\n");
    print_array(sp, 10);
    printf("Destination array\n");
    print_array(dp, 10);

    free(sp);
    free(dp);

    return 0;
}
