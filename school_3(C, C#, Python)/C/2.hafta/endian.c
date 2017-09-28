#include <stdio.h>

int i;

struct baytlar{
    unsigned char c0;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
};

union {
    unsigned int butun;
    struct baytlar byt;
} sayi;

int main(int argc, char *argv[]) {
    // int n = 1;
    // if(*(char *)&n == 1)
    //     printf("Little Endian\n");
    // else
    //     printf("Big Endian\n");
    i = 255;
    sayi.butun = i;
    printf("%d %d %d %d\n", sayi.byt.c0, sayi.byt.c1, sayi.byt.c2, sayi.byt.c3);
    i = 256;
    sayi.butun = i;
    printf("%d %d %d %d\n", sayi.byt.c0, sayi.byt.c1, sayi.byt.c2, sayi.byt.c3);

    return 0;
}
