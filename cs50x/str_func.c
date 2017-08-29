#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str() {
    char *sonuc = malloc(5);
    int a = 15;
    sprintf(sonuc, "%d , %d", a,a);
    return sonuc;
}

int main() {
    printf("%s\n",str());
    return 0;
}
