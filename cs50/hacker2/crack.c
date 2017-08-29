#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <unistd.h>
#define _XOPEN_SOURCE

int main(int argc, string argv[]) {
    
    // if the program is executed without one command-line argument; exit immediately
    if(argc != 2) {
        return -1;
    }
    
    printf("%s\n", argv[1]);
    
    return 0;
}
