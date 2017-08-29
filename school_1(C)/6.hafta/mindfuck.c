// Elmas (the better way)

#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int i = 0, n = 5;
    char* stars = (char*) calloc(sizeof(char), n * 2 + 1);
    char* spaces = (char*) calloc(sizeof(char), n);
 
    memset(stars, '*', n * 2);
    stars[n * 2 - 1] = '\n';
    memset(spaces, ' ', n - 1);
 
    for(i = 1; i < n * 2; i++) {
        int yildiz = i <= n ? i : 2 * n - i;
        printf(&spaces[yildiz - 1]);
        printf(&stars[(n * 2) - (2 * yildiz)]);
    }
 
    return 0;
}

/*if(i <= n) {
    return i;
} else {
    return n - (i - n);
}*/