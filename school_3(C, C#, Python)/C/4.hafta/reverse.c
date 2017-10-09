#include <stdio.h>

void reverse(char *str) {

    // while(str[length])
    //     length++;

    // while(length > 0) {
    //     printf("%c", str[length]);
    //     length--;
    // }

    int length = 0;
    while(*str++)
        length++;

    printf("uzunluk: %d\n", length);

    while(length-- >= 0)            // dongunun son elemani aslinda \0 oluyor ancak biz donguye oradan basliyoruz
                                    // bu yuzden 0.elemana ulasabilmek icin donguyu bir fazladan donduruyoruz.
        printf("%c", *(--str));
}


int main() {
    char rev[20] = {"test"};
    reverse(rev);
    return 0;
}
