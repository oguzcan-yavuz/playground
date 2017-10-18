#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *p = (char *) malloc(256);
    if(p == NULL) {
        printf("Bellek alinamadi!");
        return -1;
    }

    int len;

    printf("Bir cumle giriniz.\n");
    gets(p);

    len = strlen(p);
    char *q = (char *) malloc(len + 1);

    if(p == NULL) {
        printf("Bellek alinamadi!");
        free(p);
        return -1;
    }

    strcpy(q, p);
    free(p);
    p = q;
    q = NULL;

    printf("%s\n", *p);
    free(p);

    return 0;
}
