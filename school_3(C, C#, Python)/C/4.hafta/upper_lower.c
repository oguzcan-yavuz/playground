#include <stdio.h>

void *convert_upper(char *str) {
    int i = 0;
    while(str[i]) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('a' - 'A');
        i++;
    }
}

void *convert_lower(char *str) {
    int i = 0;
    while(str[i]) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ('a' - 'A');
        i++;
    }
}


int main() {
    char upper[20] = {"upper"};
    char lower[20] = {"LOWER"};
    convert_upper(upper);
    printf("upper: %s\n", upper);
    convert_lower(lower);
    printf("lower: %s\n", lower);

    return 0;
}
