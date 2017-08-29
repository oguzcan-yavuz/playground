// 0 - 1 arasi usler girildiginde de hesap yapabilme ozelligi eklenebilir.

#include <stdio.h>

double ussu(double, int);

int main() {
    double n;
    int u;
    
    printf("Us alinacak sayilari giriniz.\n");
    scanf("%lf%d", &n, &u);

    printf("%.02lf\n", ussu(n, u));
    return 0;
}

double ussu(double a, int b) {
    double result = 1;
    
    for(int i = 0; i < b; i++) {
        result *= a;
    }
    
    return result;
}
