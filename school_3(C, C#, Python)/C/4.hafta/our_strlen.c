// strlen fonksiyonu

#include <stdio.h>

int our_strlen(char *arr) {
    int length = 0;
    while(arr[length])
        length++;
    return length;
    /*  Hocanin cozumu:
    int say = 0;
    while(*str++)  say++;
    return say;
    */
}

int main() {
    char test[200];
    printf("bir cumle giriniz.\n");
    gets(test);
    printf("test uzunlugu: %d\n", our_strlen(test));
    return 0;
}
