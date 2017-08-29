/* Yildizlarla ekrandan girilen sayi kadar merdiven yapan program */

#include <stdio.h>

int main() {
    
    int n;
    printf("Bir sayi giriniz.\n");
    scanf("%d", &n);
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
