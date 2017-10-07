#include <stdio.h>

void tek_boyut(float arr[]) {
    printf("tek boyut\n");
}

void iki_boyut(float arr[][2]) {
    printf("iki boyut\n");
}

void uc_boyut(float arr[][2][3]) {
    printf("uc boyut\n");
}
int main() {
    float a[] = {1.2, 3.1};     // C'de dizi tek boyutlu ise kac elemanli oldugunu belirtmek zorunlu degil.
    float b[][2] = {{1.2, 3.1}, {3.5, 4.6}};    // ancak birden fazla boyutlu ise ilk boyuttan sonraki
    float c[][2][3] = {{{1.2, 2.5, 4.6}, {3.1, 4.5, 4.3}}};     // boyutlarin elemanlari belirtilmek zorunda.
                                // fonksiyon argumanlarini da ayni sekilde olusturduk.
    tek_boyut(a);
    iki_boyut(b);
    uc_boyut(c);

    return 0;
}
