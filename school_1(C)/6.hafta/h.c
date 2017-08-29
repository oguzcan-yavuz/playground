/* H harfini yildizlarla cizen program */

#include <stdio.h>

int main() {
    
    for(int i = 1; i < 9; i++) {
        printf("*     *\n");
        if(i == 4) {
            printf("*******\n");
        }
    }
    
    return 0;
}
