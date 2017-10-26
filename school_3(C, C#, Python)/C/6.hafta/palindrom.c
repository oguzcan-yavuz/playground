#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool recursive_palindrome(char *str, int n, int length) {
    printf("ilk: %c\nson: %c\n", str[n], str[length - n]);
    if(str[n] != str[length - n])
        return false;
    else if(length / 2 == n)
        return true;
    return recursive_palindrome(str, n + 1, length);
}

bool palindrome(char *str) {
    int len = strlen(str) - 2;
    return recursive_palindrome(str, 0, len);
}


int main() {
    char *cumle = malloc(sizeof(char) * 256);
    printf("Bir cumle giriniz.\n");
    fgets(cumle, sizeof(cumle), stdin);
    printf(palindrome(cumle) ? "palindrom\n" : "palindrom degil\n");
    return 0;
}
