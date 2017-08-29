// hocanin gosterdigi loto programini gozden gecir. (while icerisinde switch veya if kullanarak istedigimiz an atama yapmak)
// srand kullanimina bak.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    for(int i = 0; i < 10; i++) {
        int rasgele = rand() % 10;  // 0 ile 10 arasi bir sayi uretir (10 dahil degil).
        printf("%d. Deneme: %d\n", i, rasgele);
    }
    
    return 0;
}
