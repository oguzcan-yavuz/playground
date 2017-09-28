#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int size = 2
    char *res = malloc(size + 1);
    strcat(res, "lol");
    printf("%s\n", res);
    return 0;
}
