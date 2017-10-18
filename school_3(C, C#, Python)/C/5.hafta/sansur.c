#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cumle[256];
	char kelime[64];

	printf("Bir cumle giriniz.\n");
	gets(cumle);
	printf("Sansurlenmesini istediginiz kelimeyi giriniz.\n");
	gets(kelime);

	char *index;
    while(index = strstr(cumle, kelime)) {
        memset(index, '*', strlen(kelime));
    }

    printf("Orijinal cumle: %s\n", cumle);
    printf("Sansurlenmis cumle: %s\n", cumle);

    return 0;
}
