#include <stdio.h>
#include <stdlib.h>

int sayac(char* arr) {
    
    int i = 0;
    while(*(arr+i) != '\0') {
        i++;
    }
    return i;
}

int kelime(char* arr) {
    int i = 0;
    int k = 0;
    // eger verilen string bos degilse kelime sayisini 1 yap
    if(*(arr) != '\0') {
        k = 1;
    }
    while(*(arr+i) != '\0') {
        if(*(arr+i) == ' ' && *(arr+i+1) != ' ') {
            k++;
        }
        i++;
    }
    return k;
}

int main() {
    char str[20] = "";
    char *p = str;
    
    printf("Uzunluk: %d\n", sayac(p));
    puts(p);
    printf("Kelime sayisi: %d\n", kelime(p));
    
    return 0;
}
