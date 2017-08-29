#include <stdio.h>

int lenght(char* arr) {
    
    int i = 0;
    while(*(arr+i) != '\0') {
        i++;
    }
    return i;
}

int main() {
    
    char str[20] = "lolz xd xd xd";
    char *p = str;
    int leng = lenght(p);
    
    int k = leng;
    
    for(int i = 0; i <= leng / 2; i++) {
        char temp = str[i];
        str[i] = str[k - 1];
        str[k - 1] = temp;
        k--;
    }
    printf("Reversed: %s\n", str);
    
    return 0;
}
