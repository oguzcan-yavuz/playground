#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int deger(char c) {
    if(c >= 'A' && c <= 'Z')
        return c - 'A';
    return c - 'a';
}

int main() {
    char isim1[101];
    char isim2[101];
    scanf("%s", isim1);
    scanf("%s", isim2);
    int result = 0, i;
    for(i = 0; i < strlen(isim1); i++) {
        result += abs(deger(isim1[i]) - deger(isim2[i]));
    }
    printf("%d\n", result);

    return 0;
}
