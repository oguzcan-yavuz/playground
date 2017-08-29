#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[4];
    fgets(str, 4, stdin);
    int n = strtol(&str[0], NULL, 10);
    int m = strtol(&str[2], NULL, 10);
    
    int hotel[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &hotel[i]);
    }
    
    int s;
    scanf("%d", &s);
    
    int vacant = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(hotel[i] % 10 == 0) {
                vacant += 1;
                if(vacant >= s) {
                    printf("1\n");
                    return 0;
                }
            } else {
                vacant = 0;
            }
            hotel[i] /= 10;
        }
    }
    
    printf("0\n");
    
    return 0;
}
