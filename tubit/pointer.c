#include <stdio.h>

int main() {
    
    int int1 = 32;
    int *x = &int1;
    
    printf("%p d degeri => %d\n", &x, *x);
    
    return 0;
}
