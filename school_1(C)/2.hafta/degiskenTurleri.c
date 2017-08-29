#include <stdio.h>

int main() {
    
    // degisken atiyoruz
    int tam = 7;
    unsigned int uTam = 55000;
    
    short kisaTam = 30000;
    unsigned short uKisaTam = 60000;
    
    long uzunTam = 398162092;
    unsigned long uUzunTam = 4047483649;
    
    char karakter = 125;
    unsigned char uKarakter = 252;
    
    double realDouble = 97223.787844;
    float realFloat = 223.52;
    
    // degiskenleri ekrana yazdiriyoruz
    printf("tamsayi: %d\n", tam);
    printf("unsigned tamsayi: %u\n", uTam);
    
    printf("kisa tamsayi: %d\n", kisaTam);
    printf("unsigned kisa tamsayi: %u\n", uKisaTam);
    
    printf("uzun tamsayi: %ld\n", uzunTam);
    printf("unsigned uzun tamsayi: %lu\n", uUzunTam);
    
    printf("karakter: %d\n", karakter);
    printf("unsigned karakter: %d\n", uKarakter);
    
    printf("Debug double: %f\n", realDouble);
    printf("float: %f\n", realFloat);
    
    return 0;
}
