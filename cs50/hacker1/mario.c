#include <stdio.h>
#include <cs50.h>

int num;

int check() {
    if(num < 0 || num > 23) {
        printf("Enter a non-negative integer < 24: ");
        num = GetInt();
        check();
    }
    
    return 0;
}

int main() {
    
    printf("Enter a non-negative integer < 24: ");
    num = GetInt();
    
    check();
    
    for(int i = 0; i < num; i++) {
        int bosluk = num - i - 1;
        int sharp = num - bosluk;
        
        for(int j = 0; j < bosluk; j++) {
            printf(" ");
        }
        for(int l = 0; l < sharp; l++) {
            printf("#");
        }
        printf("  ");
        for(int m = 0; m < sharp; m++) {
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}
