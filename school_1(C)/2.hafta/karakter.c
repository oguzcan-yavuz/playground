#include <stdio.h>

int main() {
    char karakter;
    printf("bir karakter girerek ENTER tusuna basiniz:\n");
    scanf("%c", &karakter);
    
    printf("Karakter: %c\nASCII karsiligi: %d\n", karakter, karakter);
    
    return 0;
}
