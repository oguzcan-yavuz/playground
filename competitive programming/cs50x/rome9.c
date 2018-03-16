// Roman rakamlarını sayıya çeviren program

#include "cs50.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char roman[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
int dec[7] = { 1, 5, 10, 50, 100, 500, 1000 };
string str;

bool check(char ch, int index) {
    for(int i = 0;  i < strlen(str); i++) {
        for(int j = 0; j < 7; j++) {
            if(ch == roman[j]) {
                if(j <= index) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    str = GetString();
    int result = 0;
    
    for(int i = 0; i < strlen(str); i++) {
        for(int j = 0; j < 7; j++) {
            if(str[i] == roman[j]) {
                if(check(str[i + 1], j) == true) {
                    result += dec[j];
                } else {
                    result -= dec[j];    
                }
            }
        }    
    }
    printf("%d\n", result);
    return 0;
}
