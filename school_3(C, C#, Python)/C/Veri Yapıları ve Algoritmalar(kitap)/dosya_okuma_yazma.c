#include <stdio.h>
#include <string.h>

int main() {
    // yazma
    FILE *fout = fopen("deneme.txt", "w");
    printf("cikmak icin q ya bas.\n");
    char input;
    do {
        input = getchar();
        fprintf(fout, "%c", input);
    }
    while(input != 'q');
    fclose(fout);
    // okuma
    FILE *fin = fopen("deneme.txt", "r");
    printf("// okuma\n\n");
    while(!feof(fin))
        putchar(fgetc(fin));
    return 0;
}
