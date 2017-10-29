#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cumle[256];
    printf("Bir cumle giriniz.\n");
    gets(cumle);
    char *p;
    if(p == NULL) {
        printf("Bellek ayrilamiyor!\n");
        return -1;
    }
    p = (char *) malloc(strlen(cumle) + 1);
    // memcpy(p, cumle, strlen(cumle) + 1);
    // memmove(p, cumle, strlen(cumle) + 1);
    // memcpy(cumle + 2, cumle, 5);
    // printf("cumle: %s\n", cumle);   // kesan yusuf capraz => kekekesusuf capraz
    memmove(cumle + 2, cumle, 5);
    printf("cumle: %s\n", cumle);   // kesan yusuf capraz => kekesanusuf capraz
    free(p);

    return 0;
}
