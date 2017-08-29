#include <stdio.h>

int main() {
    
    double sayi1 = 1234.2568;
    int sayi2 = 123;
    
    // eğer placeholder'in başına sayısal değer girersek, o değer kadar boşluk bırakır veya o değer kadar sayının başına 0 ekler
    
    printf("%.5f\n", sayi1);
    printf("%10.3f\n", sayi1); // toplamda 10 haneli olacak, noktadan sonra 3 hane hakkı var.
    printf("%012f\n", sayi1);
    printf("%2f\n", sayi1); // eğer sayının toplam uzunluğundan kısa bir değer verilirse sayı değişmez
    
    // - sola dayalı yazmak için kullanılır
    
    printf("%d\n", sayi2);
    printf("%10d\n", sayi2);
    printf("%-10d! \n", sayi2);
    
    return 0;
}
