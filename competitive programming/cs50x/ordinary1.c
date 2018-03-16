#include <stdio.h>
#include <string.h>

int main() {
    char str[4000];
    char *word;
    fgets(str, 4000, stdin);
    
    if(strcmp(str, "\n") == 0) {
        printf("There is no box\n");
        return 0;
    }
    word = strtok(str, "\n ,.-");
    
    int i = 1;
    while(word != NULL) {
        if(strcmp(word, "cat") == 0) {
            if(!(i % 100 >= 10 && i % 100 <= 19)) {
                switch(i % 10) {
                    case 1:
                        printf("The cat is the %dst item in the box\n", i);
                        return 0;
                    case 2:
                        printf("The cat is the %dnd item in the box\n", i);
                        return 0;
                    case 3:
                        printf("The cat is the %drd item in the box\n", i);
                        return 0;
                    default:
                        printf("The cat is the %dth item in the box\n", i);
                        return 0;
                }
            } else {
                printf("The cat is the %dth item in the box\n", i);
                return 0;
            }
        }
        word = strtok(NULL, "\n ,.-");
        i++;
    }
    
    printf("No cat yet\n");
    
    return 0;
}