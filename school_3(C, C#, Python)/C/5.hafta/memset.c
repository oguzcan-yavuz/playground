#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    unsigned int size;
    printf("Kac adet char boyutunda bellek ayiralim?\n");
    scanf("%u", &size);
    char *p = (char *) malloc(sizeof(char) * size);

    if(p == NULL) {
        printf("Bellek alinamadi!");
        return -1;
    }

    memset(p, 'b', sizeof(char) * size);

    for(int i = 0; i < sizeof(char) * size; i++)
        printf("%d. eleman: %c\n", i, p[i]);

    free(p);

    return 0;
}
