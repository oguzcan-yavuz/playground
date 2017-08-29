#include <stdio.h>

int main() {
    // yaricap ve pi degiskenlerini atiyoruz
    double r;
    double pi = 3.1415;
    
    // kullanicidan yaricapi istiyoruz ve r degiskenine atiyoruz
    printf("dairenin yaricapini girin...(cm)\n");
    scanf("%lf", &r);
    
    // dairenin alanini ve cevresini hesaplayip degiskenlere atiyoruz
    double alan = r * r * pi;
    double cevre = 2 * pi * r;
    
    // dairenin alanini ve cevresini ekrana yazdiriyoruz
    printf("dairenin alani: %lf cm²\n", alan);
    printf("dairenin cevresi: %lf cm\n", cevre);
    
    return 0;
}
