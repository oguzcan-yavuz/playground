/* Soru : Dizide yer alan metnin harfelerini dikey olarak yazdiran main programini kodlayiniz.  */
#include <stdio.h>
#include <string.h>

int main() {
	char str[]= {"PROGLAMLAMA"};
	char *strpt = str;
	for (int i=0; i < strlen(str); i++) {
		printf("%c\n", *(strpt + i));
	}

	return 0;
}
