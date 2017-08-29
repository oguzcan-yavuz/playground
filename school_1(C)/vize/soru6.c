/* Kullanıcı ekrana girdiği 11626020** şeklindeki öğrenci numarasından sınıfa kaçıncı olarak
girdiğini hesaplayan programı yapınız. */

#include <stdio.h>

int main() {
    
    int num, num2;
    printf("Lutfen okul numaranizi giriniz...\n");
    scanf("%d", &num);
    
    num2 = num % 100;
    printf("Sinifa giris siraniz: %d\n", num2);
    
    return 0;
}
