#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    
    // get the string from user
    string name = GetString();
    // calculate the length of the string and stores it in 'n'
    int n = strlen(name);
    
    // if the string is not NULL
    if(name != NULL) {
        // calculate how many spaces in 'name' variable
        int spaces = 1;
        for(int i = 0; i < n; i++) {
            if(name[i] != ' ') {
                continue;
            } else {
                spaces++;
            }
        }
        
        // create an array
        char result[spaces];
        // loop variable for name string
        int j = 0;
        // index variable for result array
        int k = 0;
        
        // if the first character of the array is not a space, do it uppercase and add it to 'result'
        if(name[0] != ' ') {
            result[k] = toupper(name[0]);
            k++;
            j++;
        }
        
        // runs for every character in 'name' string
        while(j < n) {
            // if the character is space and the next character from it is not a space, do it uppercase and add it to 'result'
            if(name[j] == ' ' && name[j + 1] != ' ') {
                result[k] = toupper(name[j + 1]);
                k++;
            }
            j++;
        }
        // print the 'result' string
        printf("%s\n", result);
    }
    return 0;
}
