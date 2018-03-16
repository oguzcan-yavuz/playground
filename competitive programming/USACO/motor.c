#include <stdio.h>

int main() {
    int n, res_sayisi;
    scanf("%d %d", &n, &res_sayisi);
    char db[n][20];
    for(int i = 0; i < n; i++) {
        scanf("%s", db[i]);
    }
    int arama;
    scanf("%d", &arama);
    char aramalar[arama][20];
    for(int i = 0; i < arama; i++) {
        scanf("%s", aramalar[i]);
    }
    return 0;
}
