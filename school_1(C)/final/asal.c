// 0 ile 100 arasindaki asal sayilari konsol ekranina yazdiran programi yaziniz.

#include <stdio.h>
#include <stdbool.h>

int main() {
    
    int asal, index;
    bool kontrol = false;
    for(asal = 2; asal < 100; asal++) {
        for(index = 2; index < asal; index++) {
            if(asal % index == 0) {
                kontrol = true;
                break;
            }
        }
        if(kontrol) {
            kontrol = false;
            continue;
        } else {
            printf("%d bir asal sayidir.\n", asal);
        }
    }
    return 0;
}
