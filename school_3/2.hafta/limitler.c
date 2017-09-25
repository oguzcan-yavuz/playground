#include <stdio.h>
#include <limits.h>


int main(int argc, char *argv[]) {
    char c;
    short int n;
    int n2;
    long int n3;
    printf("char size: %d\nshort int size: %d\nint size: %d\nlong int size: %d\n\n", sizeof(c), sizeof(n), sizeof(n2), sizeof(n3));
    printf("char low limit: %d\nchar up limit:%d\n", CHAR_MIN, CHAR_MAX);
    printf("int low limit: %d\nintt up limit: %d\n", INT_MIN, INT_MAX);
    printf("long min: %ld\nlong max: %ld\n", LONG_MIN, LONG_MAX);
    return 0;
}
