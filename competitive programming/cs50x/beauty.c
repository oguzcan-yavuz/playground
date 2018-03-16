#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

bool vowel(char c) {
    char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for(int i = 0; i < 6; i++) {
        if(vowels[i] == c)
            return true;
    }
    return false;
}


int main(){
    char* w = (char *)malloc(512000 * sizeof(char));
    scanf("%s",w);
    // Print 'Yes' if the word is beautiful or 'No' if it is not.
    for(int i = 0; i < strlen(w) - 1; i++) {
        if(!(vowel(w[i]))) {
            if(w[i] == w[i + 1]) {
                printf("No\n");
                return 0;
            }
        } else {
            if(vowel(w[i + 1])) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    
    return 0;
}
