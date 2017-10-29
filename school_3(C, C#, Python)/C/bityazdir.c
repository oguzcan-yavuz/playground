#include <stdio.h>

int main() {
				
	unsigned int sayi = 21;
	unsigned int bits = 256;
	for(int i = 0; i < 9; ++i) {
		printf("%d ",sayi & bits ? 1 : 0);
		printf("%d\n", bits);
		bits >>= 1;
	}			
	return 0;
}

