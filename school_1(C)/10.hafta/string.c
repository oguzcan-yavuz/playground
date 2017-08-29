#include <stdio.h>

int main() {
    char dizi[20] = "Bilgisayar sinifi";    
    
    for(int i = 0; i < 20; i++) {
        printf("%c\n", dizi[i]);
    }
    
    int k = 0;
    
    while(dizi[k] != '\0') {
        printf("%c\n", dizi[k]);
        k++;
    }
    
    return 0;
}