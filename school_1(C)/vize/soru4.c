/* Bir üçgenin iki iç açısını kullanıcıdan alacaksınız.Ve üçgenin Dik açılı , Geniş açılı ya da
Dar açılı mı olduğunu ekrana yazdıran programı yapınız. */

#include <stdio.h>

int main() {
    
    int aci1, aci2;
    int ucgen = 180;
    printf("Iki adet aci giriniz...\n");
    scanf("%d%d", &aci1, &aci2);
    
    int aci3 = ucgen - (aci1 + aci2);
    
    if(aci1 > 90 || aci2 > 90 || aci3 > 90) {
        printf("Bu ucgen genis acilidir...\n");
    } else if(aci1 == 90 || aci2 == 90 || aci3 == 90) {
        printf("Bu ucgen dik acilidir...\n");
    } else {
        printf("Bu ucgen dar acilidir...\n");
    }
    
    return 0;
}