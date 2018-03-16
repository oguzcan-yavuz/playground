#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void RemoveSpaces(char* source) {
    char* i = source;
    char* j = source;
    while(*j != 0) {
        *i = *j++;
        if(*i != ' ')
            i++;
    }
    *i = 0;
}

int main() {
    
    char str[200];
    fgets(str, 200, stdin);
    int result = 0;
    RemoveSpaces(str);
    int i = 0;
    
    if(str[0] != '+' || str[0] != '-') {
        result += strtol(&str[0], NULL, 10);
        i++;
    }
    
    for(; i < 200; i++) {
        if(str[i] == '+') {
            result += strtol(&str[i + 1], NULL, 10);
        }
        if(str[i] == '-') {
            result -= strtol(&str[i + 1], NULL, 10);
        }
        if(str[i] == '\0') {
            break;
        }
    }
    printf("%d\n", result);
    return 0;
}
