#include <stdio.h>

int main() {
    char c;
    char *pc = &c;

    int i;
    int *pi = &i;

    printf("c'nin ilk adresi: %p\n", pc);
    pc--;
    printf("c'nin bir azaltilmis adresi: %p\n", pc);

    printf("i'nin ilk adresi: %p\n", pi);
    pi++;
    printf("i'nin bir arttirilmis adresi: %p\n", pi);

    int *q;     // tehlikeli olabilir
    printf("deger atanmamis pointer'in degeri: %p\n", q);

    return 0;
}
