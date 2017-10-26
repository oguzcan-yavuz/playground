#include <stdio.h>

int recursive_obeb(int x, int y, int bol) {
    return ((x % bol == 0) && (y % bol == 0)) ? bol : recursive_obeb(x, y, bol - 1);
}

int obeb(int x, int y) {
    return recursive_obeb(x, y, x > y ? y : x);
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("sonuc: %d\n", obeb(x, y));
    return 0;
}
