#include <stdio.h>

void crypt(char *s) {
    while(*s) {
        // *s = ~(*s);
        *s += 2;
        s++;
    }
}

void decrypt(char *s) {
    while(*s) {
        // *s = ~(*s);
        *s -= 2;
        s++;
    }
}

int main() {
    char str[256];
    printf("Bir cumle giriniz:\n");
    scanf("%s", str);
    crypt(str);
    printf("%s\n", str);
    decrypt(str);
    printf("%s\n", str);
    return 0;
}
