#include <stdio.h>
#include <string.h>

char* find_index(char candidate, char* chars) {
    for(int i = 0; i < strlen(chars); i++) {
        if(strcmp((const char *) candidate, (const char *) chars[i]) == 0) {
            return &chars[i];
        }
    }
    return  (char *) 'f';
}


int lengthOfLongestSubstring(char* s) {
    char* chars;
    int result = strcmp(s, "") == 0 ? 0 : 1;
    char* check;

    for(int i = 0; i < strlen(s); i++) {
        check = (char) find_index(s[i], (char *) &chars);
        if(strcmp((const char *) check, (const char *) 'f') != 0) {
            if(result < strlen(chars))
                result = (int) strlen(chars);
            chars = (char *) &check;
        }
        chars[i] = s[i];
        if(result < strlen(chars))
            result = (int) strlen(chars);
    }
    return result;
}

int main() {
    printf((const char *) lengthOfLongestSubstring("abcabcbb"));

    return 0;
}
